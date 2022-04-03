import socket

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


send("Hello World!")
send(QUIT_MESSAGE)