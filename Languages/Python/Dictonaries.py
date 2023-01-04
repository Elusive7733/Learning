name = input("Enter file name to open: ")
emails = dict()
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
        emails[words[1]] = emails.get(words[1], 0) + 1

print(max(emails, key=emails.get), emails[max(emails, key=emails.get)])

