import pymp
import math

pwr = []
fact = []
x = int(input("Exponential: Enter value of x (between 0 and 100): "))

def power():
    for i in range(0, 150):
        pwr.append(pow(x, i))


def factorial():
    fact.append(1.0)
    for i in range(1, 150):
        num = 1.0
        for j in range(i, 0, -1):
            num *= j
        fact.append(num)


def exp():
    s = 0
    for i in range(0, 150):
        s += (pwr[i]/fact[i])
    
    return s


# with pymp.Parallel(4) as p:
#     p.print(p.num_threads, p.thread_num)


power()
factorial()
sum = exp()
print(sum)