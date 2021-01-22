import os
clear = lambda: os.system('cls') #on Windows System
pause = lambda: os.system('pause')#on Windows System

x = input("Enter a number: ")
try:
    x = int(x)
except:
    x = -1

clear()

while x == -1:
    print("Invalid Input\n")
    pause()
    clear()
    x = input("Enter a number: ")
    try:
        x = int(x)
    except:
        x = -1