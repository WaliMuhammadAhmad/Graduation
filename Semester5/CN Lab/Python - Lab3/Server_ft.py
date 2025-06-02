import socket
s = socket.socket()
host = socket.gethostname() #Get localhost IP address
port = 8080 #assign port for session
s.bind((host,port)) #bind the socket to assigned host IP and port
s.listen(1) #put the socket into listening mode for 1 client
print(host)
print("Waiting for any incoming connection... ")
conn, addr = s.accept()
print(addr, "Has connected to the server")
filename = input(str("Enter the name of the file to be transmitted: "))
file = open(filename , 'rb') # Opens a file for reading only in binary format
file_data = file.read(1024)
conn.send(file_data)
print("File has been transmitted successfully")