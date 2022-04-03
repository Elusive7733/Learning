import socket
import threading

HEADER = 64
PORT = 5050
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
QUIT_MESSAGE = "!quit"


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET is an address family IPv4 socket
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msgLength = len(message)
    sendLength = str(msgLength).encode(FORMAT)
    sendLength += b' ' * (HEADER - len(sendLength))
    client.send(sendLength)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))


# send("Message 3 - New Connection Same IP")
# send(QUIT_MESSAGE)


#### Malicious Code ####

fakeIp = "192.23.20.32"

def attack():
    while True:
        #creating new sockets
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(ADDR)

        #sending spam messages
        msg = "Message From Attacker: 192.23.20.32"
        msg = msg.encode(FORMAT)
        s.send(msg)
        s.close()

for i in range(500):
    thread = threading.Thread(target=attack)
    thread.start()