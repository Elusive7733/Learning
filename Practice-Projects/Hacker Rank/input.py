import string
x,k = input("Enter Numbers: ").split(" ")

x = int(x)
k = int(k)

input_str  = input()

array = []
array = input_str.split("+")
temp_array = []

for element in array:
    temp_array.append(element.strip())

array = temp_array
temp_array = []
sum = 0

for element in array:
    if len(element) == 1:
        if element != 'x':
            sum += int(element)
        else: 
            sum += x
    else:
        #do work here
        temp_num = 0
        temp_array = element.split('x')
        if len(temp_array[0]) < 1:
            coff = 1
        else:
            coff = int(temp_array[0])
        power = int(temp_array[1].split('^')[1])
        sum += coff * pow(x, power)

print(sum)


# 13x^3 + 3x^2 + x + 4