#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/sched/signal.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("David Cox");
MODULE_DESCRIPTION("LKM to do cool stuff");

#define BUTTON_GPIO 16 // GPIO for our Button
#define REGISTER_SAPP _IO('R', 'g') // Signal for US Listener to listen for
#define SIGNR 44 // Signal for US listener

static dev_t dev;
static unsigned int irq_value;
static unsigned long last_button_press = 0;
static struct cdev characterDevice;
static struct class *buttonListener_class;
static struct task_struct *task = NULL;

static irq_handler_t signalHandler(unsigned int irq, void *dev_id)
{
    struct siginfo signalInfo;
    unsigned long now = jiffies;

    if (time_after(now, last_button_press + msecs_to_jiffies(300))) { // if its within the last 300 milliseconds
        pr_info("Button pressed! Sending signal to userspace\n");

        if (task != NULL) {
            memset(&signalInfo, 0, sizeof(signalInfo));
            signalInfo.si_signo = SIGNR; // pass the signal across
            signalInfo.si_code = SI_QUEUE;

            if (send_sig_info(SIGNR, &signalInfo, task) < 0) // send the signal and if it returns an error code
                pr_err("Error sending signal\n");
        }

        last_button_press = now;
    }

    return (irq_handler_t)IRQ_HANDLED;
}

static int button_open(struct inode *inode, struct file *file){
    pr_info("Device Connected.\n");
    return 0;
}
static int button_release(struct inode *inode, struct file *file){
    pr_info("Device Disconnected.\n");
    return 0;
}
static int button_ioctl(struct file *file, unsigned int cmd, unsigned long arg){
    if (cmd == REGISTER_SAPP) {
        task = get_current();
        pr_info("Listener registered under PID %d\n", task->pid);
    }
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = button_open,
    .release = button_release,
    .unlocked_ioctl = button_ioctl,
};

static int __init button_init(void)
{
    int errorCode = 0;
    pr_info("Loading module\n");

    if (!gpio_is_valid(BUTTON_GPIO)) { // gpio pin too high/low
        pr_err("Invalid GPIO pin\n");
        return -ENODEV;
    }
    if (gpio_direction_input(BUTTON_GPIO)) { // cant set to input
        pr_err("Unable to set the pin to input mode\n");
        return -1;
    }
    if ((errorCode = gpio_request(BUTTON_GPIO, "button_gpio"))) { // gpio isnt responding
        pr_err("Unable to request GPIO pin\n");
        return errorCode;
    }

    gpio_set_debounce(BUTTON_GPIO, 300); // set delay between presses
    irq_value = gpio_to_irq(BUTTON_GPIO); // get interrupt request 

    if ((errorCode = request_irq(irq_value, signalHandler, IRQF_TRIGGER_FALLING, "button_irq", NULL))) // if not responding
    {
        pr_err("Faile to request IRQ\n");
        gpio_free(BUTTON_GPIO);
        return errorCode;
    }

    alloc_chrdev_region(&dev, 0, 1, "gpio_irq_signal"); // allow character device memory region
    buttonListener_class = class_create(THIS_MODULE, "buttonListener_class"); // create our class

    cdev_init(&characterDevice, &fops); // initialise the character device
    characterDevice.owner = THIS_MODULE; // we own it so we can control it

    cdev_add(&characterDevice, dev, 1); // add our device to the character device
    device_create(buttonListener_class, NULL, dev, NULL, "gpio_irq_signal"); // create the device in /dev

    pr_info("Module loaded.\n");    
    pr_info("Pin is mapped to IRQ number %u\n", irq_value);

    return 0;
}


static void __exit button_exit(void){ //undo everything we did above
    pr_info("Unloading module\n");
    device_destroy(buttonListener_class, dev);
    cdev_del(&characterDevice);
    class_destroy(buttonListener_class);
    unregister_chrdev_region(dev, 1);
    free_irq(irq_value, NULL);
    gpio_free(BUTTON_GPIO);
    pr_info("Module unloaded\n");
}

module_init(button_init);
module_exit(button_exit);