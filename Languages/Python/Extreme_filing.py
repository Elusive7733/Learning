name = input("Enter file name to open: ")
count = 0
avg = 0
flag = False
while flag == False:
    try:
        file = open(name, "rt")
        flag = True
    except:
        name = input("File does not exist\nEnter file name again: ")
for line in file:
    if "X-DSPAM-Confidence:" in line:
        count += 1
        pos = line.find(':')
        avg += float(line[pos+2:])

avg = avg/count
print("Average spam confidence:", avg)

