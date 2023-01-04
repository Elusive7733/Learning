import re
flag = False
fname = input("Enter file name: ")
numbers = list()
while flag == False:
    try:
        file = open(fname)
        flag = True
    except:
        fname = input("File does not exist\nEnter a valid file name: ")

for line in file:
    line = line.strip()
    for num in re.findall('[0-9]+', line):
        numbers.append(int(num))

print(sum(numbers))