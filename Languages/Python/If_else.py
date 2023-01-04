x = int(input("Input a value: "))

if x < 97 :
    if x >= 21 :
        print("[21, 96]")
    else:
        print("(-∞,20]\n")
else:
    print("[97, ∞)")


# largest = -999
# smallest = 999
# while True:
#     num = input("Enter a Number: ")
#     try:
#         num = int(num)
#         if num > largest:
#             largest = num
#         if num < smallest:
#             smallest = num
#     except:
#         if num == 'done':
#             break        

# print("\n\n")
# print("Largest Number: ", largest)
# print("Smallest Number: ", smallest)