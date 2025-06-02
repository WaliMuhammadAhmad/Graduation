import socket
s = socket.socket()
host = input(str("Please enter the host address of the sender: "))
port = 8080
s.connect((host,port))
print("Connected ... ")
filename = input(str("Please enter a filename for the incoming file: "))
file = open(filename, 'wb') # Opens a file for writing only in binary format
file_data = s.recv(1024)
file.write(file_data)
file.close()
print("File DESKTOP-6N409VEhas been received successfully.")