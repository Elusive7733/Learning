hrs = input("Enter Hours: ")
rate = input("Enter Rate per hour: ")


try:
    hrs = int(hrs)
except:
    hrs = input("Enter integer: ")
    hrs = int(hrs)

try:
    rate = float(rate)
except:
    rate = input("Enter float: ")
    rate = float(rate)

total = 0.0


if hrs > 40:
    total = total + 40*rate
    hrs = hrs - 40
    total = total + hrs*1.5*rate
else:
    total = hrs*rate

print("Total: ", total)

