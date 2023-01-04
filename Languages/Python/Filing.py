name = input("Enter file name to read: ")

file = open(name, "rt")
print(file.read())
print("\n\n")

# print(file.read(5)) #reads only 5 characters
# print("\n\n")

# print(file.readline()) #reads a line
# print("\n\n")

# for i in file: #read all lines by looping
#     print(i)

file.close()

name = input("Enter file name to append: ")
file = open(name,"a")

file.write(input("Enter data in file: "))
file.close()
