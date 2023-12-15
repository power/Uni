from socket import *
import os 
import math
# libraries we're going to use 

ip = "localhost"
port = 11000
BUFFER = 512
total = 0
#packets have a max size of 512 so we can't send any packets bigger then that 

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((ip, port))
# self explanatory
filename = input("Please input your file name, with an extension: ")

if filename[-4:] != ".txt":
    filename = filename + ".txt"

size = os.path.getsize(filename)
result = size / BUFFER
result = math.ceil(result)
# gets the size of the file we're using in bytes and then divides it by the buffer, this tells the client how many times it needs to listen for a response because of the packet size limit 
# we then get the ceiling for that number (if its 3.4 it'll go to 4 because the ceiling means the highest whole value to the number, ensures the client listens and collects all the data

with open(filename, "rb") as a: # "rb" for read bytes 
    while True: # while there is bytes to read
        bytes_read = a.read(BUFFER) # read 512 bytes
        #print("Seperate bytes: ")
        #print (bytes_read) <-- debugging 
        clientSocket.send(bytes_read) # send the bytes to the server
        if not bytes_read: # if there is no bytes to read
            break # exit the loop


for i in range(result): # for as many 512's that fit into the size of the file
    modifiedMessage = clientSocket.recv(2048) # receieve a response from the server
    total += int(modifiedMessage.decode()) # convert it to an integer and then add it to our total

total -= 2 # take 2 off our total because there's some kind of error - look in to trying to fix this
print("There is a total of ",total," words in this text file.") # tell the user how many words there is in the file
clientSocket.close() # close the connection