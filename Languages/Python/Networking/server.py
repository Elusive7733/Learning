import socket
import threading

HEADER = 2048
PORT = 5050
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
QUIT_MESSAGE = "!quit"

#1st Mitigation - Maintain a list of IPs that have connected to the server
IP_POOl = [];

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET is an address family IPv4 socket
server.bind(ADDR)

def connectClient(conn, addr):
    print("{} connected.".format(addr))

    connected = True
    while connected:
        msg = conn.recv(2048).decode(FORMAT)
        if msg == QUIT_MESSAGE:
            connected = False
            # IP_POOl.remove(addr[0]) #Removes IP from IP_POOl if client disconnects
        print("{} sent {}".format(addr, msg))
        # conn.send("Message Received!".encode(FORMAT))
    conn.close()


def startServer():
    server.listen()
    while True:
        conn, addr = server.accept()
        #2nd Mitigation - Prevent multiple connections from the same IP
        if(addr[0] not in IP_POOl):
            IP_POOl.append(addr[0])
            thread = threading.Thread(target=connectClient, args=(conn, addr))
            thread.start()
        elif(addr[0] in IP_POOl):
            conn.send("You are already connected to the server. Please try again later.".encode(FORMAT))
            conn.close()
        print("Total Connects: {}".format(threading.active_count() - 1))

print("Server Running on Port {}".format(PORT))
startServer();