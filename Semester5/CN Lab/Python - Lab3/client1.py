import socket

host = '127.0.0.1'
port = 5000

obj = socket.socket()
obj.connect((host, port))
message = input("Hello, please enter your message: ")

while message.lower().strip() != 'bye':
    obj.send(message.encode())
    data = obj.recv(1024).decode()
    print("Recieved from server: ", data)
    message = input("Enter your messege: ")
obj.send(message.encode())
obj.close()
