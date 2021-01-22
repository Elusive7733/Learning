def maximum(list):
    max = -99999
    for i in list:
        if i > max:
            max = i
    return max

def minimum(list):
    min = 99999
    for i in list:
        if i < min:
            min = i
    return min

lst = []


while True:
    x = input()
    if x == 'done':
        break
    else:
        try:
            x = int(x)
            lst.append(x)
        except:
            print("Invalid input")

print("Maximum is", maximum(lst))
print("Minimum is", minimum(lst))