# def length(str):
#     x = 0
#     while int(x) != int(len(str)):
#         x += 1
#     return x

# x = input("Enter A string: ")

# print("Length: ", length(x))

def computepay(h, r):
    if h > 40:
        pay = 40*r
        h -= 40
        pay += h*1.5*r
    else:
        pay = h*r
    return pay

hrs = int(input("Enter hours: "))
rate = float(input("Enter rate/hr : "))

pay = computepay(hrs, rate)

print("Pay", pay)