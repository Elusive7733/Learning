import socket
import threading

HEADER = 2048
PORT = 8080
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
QUIT_MESSAGE = "!quit"
isAuth = False;
# isAuth is a boolean variable to check if the user is authenticated or not



server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET is an address family IPv4 socket
server.bind(ADDR)


# Used for Client Authentication
def authenticateClient(conn, addr):
    connectionString = conn.recv(2048).decode(FORMAT)

    # Split the connectionString into username and password
    connectionString = connectionString.split(",")
    username = connectionString[0].split(":")[1]
    password = connectionString[1].split(":")[1]

    print(username, password)

    # Check if the username and password are correct
    if username == "admin" and password == "admin":
        # isAuth = True
        conn.send("Authenticated".encode(FORMAT))
    else:
        # isAuth = False
        conn.send("Invalid Username or Password".encode(FORMAT))
        conn.close()



# If authenticated then connect client to the server
def connectClient(conn, addr):
    authenticateClient(conn, addr)
    if isAuth:
        print("{} connected.".format(addr))

        connected = True
        while connected:
            msg = conn.recv(2048).decode(FORMAT)

            print(msg)
            if msg == QUIT_MESSAGE:
                connected = False
                conn.close()
                return
                
            # print("{} sent {}".format(addr[0], msg))
            conn.send("Message Received!".encode(FORMAT))
    else:
        conn.send("User not Authenticated".encode(FORMAT))
        conn.close()


def startServer():
    server.listen()
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=connectClient, args=(conn, addr))
        thread.start()

print("Server Running on Port {}".format(PORT))
startServer();