n = int(input('Enter a number: '))

x,y = 1,2

print("The Series is: ", end='')
while y <= n:
    if(x == 1):
        print(x,'/',y,end='')
    else:
        print(', ', x,'/',y,end='')
    x += 2
    y += 2
