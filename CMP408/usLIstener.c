#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

#define SIGTX 44 // specifies signal number to listen for
#define REGISTER_SAPP _IO('R', 'g')

void runPrograms(int sig)
{
    printf("Signal received, running scripts.\n");
    system("python3 /home/pi/proj/getSysInfo.py");
    system("python3 /home/pi/proj/sendMqtt.py");
    printf("Scripts complete, check for output.\n");
}

int main()
{
    int devFile;
    signal(SIGTX,runPrograms); // when signal received, do this

    printf("Running under Process ID: %d\n", getpid());

    devFile = open("/dev/gpio_irq_signal", O_RDONLY); //open the device we've created
    ioctl(devFile, REGISTER_SAPP, NULL); // register our listener

    printf("Setup complete, waiting for signals.\n");


    while (1) // check every second for whether we have our signal
        sleep(1);

    return 0;
}