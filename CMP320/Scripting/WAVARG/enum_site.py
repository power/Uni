import nmap
import pydirbuster
from prettytable import PrettyTable

def run_nmap(ip):
    pt = PrettyTable()
    pt.field_names = ["Port", "Name", "Service", "Additional Information"]

    # define a PT instance and define our column headings
    nmap_data = ""
    nm = nmap.PortScanner()
    args = "-sCV"

    # define an nmap instance and generate our query
    nm.scan(hosts=ip, arguments=args)

    # run our scan
    for host in nm.all_hosts(): # for every IP scanned
        for proto in nm[host].all_protocols(): # for every protocol
            print("-" * 50) # create a barrier
            lport = nm[host][proto].keys() # a list of all open ports
            for port in lport: # for each open port
                #nmap_data = '\nport:%s\t name:%s\t service:%s\t extra info:%s\t' % (port, nm[host][proto][port]['name'], nm[host][proto][port]['product'], nm[host][proto][port]['extrainfo'])
                pt.add_row([port, nm[host][proto][port]['name'], nm[host][proto][port]['product'], nm[host][proto][port]['extrainfo']]) # add a row containing useful information
    
    pt.sortby = "Port" # show them in ascending order, same as how nmap would normally show them
    nmap_data = pt.get_string()
    return nmap_data

def run_dirb(ip):
    ip =  "http://" + ip
    dirb = pydirbuster.Pybuster(url=ip, wordfile="./support_files/common.txt", exts=['php', 'txt', 'zip', 'html']) # cmd-line equiv: dirb -u $IP -w ./support_files/common.txt -x php,txt,zip,html
    dirb_temp = dirb.Run() # run it
    return dirb_temp


if __name__ == "__main__":
    run_nmap(ip)