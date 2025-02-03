import json,psutil, platform, datetime

def convert(val):
    return "{}MB".format(round(val / (1024*1024))) #convert from bytes to MB

def getInfo():
    timestamp = {
        'Timestamp': str(datetime.datetime.now()) 
    }

    hostname = {
        'Hostname': platform.node()
    }
    
    architecture = {
        'Architecture': platform.platform()
    }
    
    
    #ram=str(psutil.virtual_memory().total / (1024 ** 3))
    ram_usage = {
        'Total': convert(psutil.virtual_memory().total),
        'Available': convert(psutil.virtual_memory().available),
        "Percent": psutil.virtual_memory().percent
    }

    disk_usage = {
        'Total': convert(psutil.disk_usage('/').total),
        'Percent': psutil.disk_usage('/').percent
    }

    network_usage = {
        'traffic_sent': convert(psutil.net_io_counters().bytes_sent),
        'traffic_recv': convert(psutil.net_io_counters().bytes_recv)
    }


    return { #return in JSON format for proper formatting
        'timestamp': timestamp,
        'hostname': hostname,
        'architecture': architecture,
        'RAM': ram_usage,
        'disk': disk_usage,
        'network': network_usage
    }

def writeToFile(jsonData):    
    with open("usage.json", "w") as jsonFile:
        json.dump(jsonData, jsonFile, indent=4) # write in proper format


jsonData = getInfo()
writeToFile(jsonData)