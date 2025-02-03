import time
import paho.mqtt.client as mqtt
import ssl
import json
import warnings

warnings.filterwarnings("ignore") # ignore deprecation warning, not my problem

def on_connect(client, userdata, flags, rc):
    print("Connected to AWS") # required for this to work so keep it simple

client = mqtt.Client()
client.on_connect = on_connect
client.tls_set(ca_certs="./certs/AmazonRootCA1.pem", certfile="./certs/cert.pem.crt", keyfile="./certs/private.pem.key", tls_version=ssl.PROTOCOL_SSLv23)
client.tls_insecure_set(True)
client.connect("a2ojfhq53wlo9z-ats.iot.us-east-1.amazonaws.com", 8883, 60)

def publishData():
    with open("usage.json", "r") as file:
        data = json.load(file)
        dts = json.dumps(data)
        client.publish("raspi/data", dts, qos=1) # topic, data, qos

publishData()
client.loop_start()
time.sleep(5)
client.disconnect()
client.loop_stop()
