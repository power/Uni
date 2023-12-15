from socket import *
# importing the libraries we're going to use 

ip = "localhost"
port = 11001
# defining our ip and port

clientSocket = socket(AF_INET, SOCK_DGRAM)
# creates a socket 

calc = input("Please input your calculation: ")
# asking the user for their calculation and storing as a string, we dont need to convert it as the server will do that 

clientSocket.sendto(calc.encode(), (ip, port))
# convert the string to bytes so it can be sent across the network

response = clientSocket.recv(2048)
# receive a response from the server

print (response.decode())
#print the response

clientSocket.close()
#close the connection