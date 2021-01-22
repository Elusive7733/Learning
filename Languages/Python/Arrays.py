name = input("Enter file name to open: ")
words = list()
lst = list()
flag = False
while flag == False:
    try:
        file = open(name)
        flag = True
    except:
        name = input("File does not exist\nEnter file name again: ")

for line in file:
    line = line.rstrip()
    lst = line.split()
    for i in lst:
        if i in words: continue
        words.append(i)

words.sort()
print(words)