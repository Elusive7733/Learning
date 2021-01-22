import math

char1 = input("Which first variable you want to use: ")
char2 = input("Which second variable you want to use: ")

if (char1 == 'a' and char2 == 'b') or (char1 == 'b' and char2 == 'a'):

    try:
        a = float(input("Enter a: "))
    except:
        a = float(input("Enter a in float: "))

    try:
        b = float(input("Enter b: "))
    except:
        b = float(input("Enter b in float: "))

    if a < 0:
        a = float(input("Distance can not be negative\nEnter a in float: "))
    if b < 0:
        b = float(input("Distance can not be negative\nEnter b in float: "))
        
    c = math.sqrt(a*a + b*b)

elif (char1 == 'b' and char2 == 'c') or (char1 == 'c' and char2 == 'b'):

    try:
        b = float(input("Enter b: "))
    except:
        b = float(input("Enter b in float: "))
    
    try:
        c = float(input("Enter c: "))
    except:
        c = float(input("Enter c in float: "))

    if b < 0:
        a = float(input("Distance can not be negative\nEnter b in float: "))
    if c < 0:
        c = float(input("Distance can not be negative\nEnter c in float: "))

    a = math.sqrt(c*c - b*b)

elif (char1 == 'c' and char2 == 'a') or (char1 == 'a' and char2 == 'c'):
    try:
        a = float(input("Enter a: "))
    except:
        a = float(input("Enter a in float: "))
    
    try:
        c = float(input("Enter c: "))
    except:
        c = float(input("Enter c in float: "))

    if a < 0:
        a = float(input("Distance can not be negative\nEnter a in float: "))
    if c < 0:
        c = float(input("Distance can not be negative\nEnter c in float: "))

    b = math.sqrt(c*c - a*a)

else:
    print("Invalid variables\n")
    quit()

print("A: ", a)
print("B: ", b)
print("C: ", c)

