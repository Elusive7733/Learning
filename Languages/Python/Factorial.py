def factorial(x):
    if x == 0:
        return 1
    else:
        return x*factorial(x-1)

val = int(input("Enter value: "))
print(val,"! = ", factorial(val))