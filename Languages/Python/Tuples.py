name = input("Enter file name to open: ")
hours = dict()
flag = False
words = list()

while flag == False:
    try:
        file = open(name)
        flag = True
    except:
        name = input("File does not exist\nEnter file name again: ")
for line in file:
    if line.startswith("From") and not line.startswith("From:"):
        words = line.split()
        temp = words[5].split(':')
        hours[temp[0]] = hours.get(temp[0], 0) + 1


for (k,v) in sorted([(k,v) for k,v in hours.items()]):
    print(k, v) 

