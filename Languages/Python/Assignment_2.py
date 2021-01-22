# name = input("Enter file name to open: ")
# flag = False
# count = 0
# words = list()
# while flag == False:
#     try:
#         file = open(name)
#         flag = True
#     except:
#         name = input("File does not exist\nEnter file name again: ")
# for line in file:
#     for word in line.split(" "):
#         if word not in words:
#             words.append(word.split("\n")[0].lower())

# words.sort()
# print(words)










name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
di = dict()
for line in handle :
    if line.startswith("From ") and not line.startswith("From:"):
        words = line.split()
        # print(words[5])
        hour = words[5].split(":")[0]
        # print(hour)
        di[hour] = di.get(hour, 0) + 1

temp = list()
for element in di:
    temp.append(element)
    # print(element)
temp.sort()
for element in temp:
    print(element, di[element])
