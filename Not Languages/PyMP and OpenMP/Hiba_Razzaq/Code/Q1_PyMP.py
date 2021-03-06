import pymp
import math

pwr = pymp.shared.array((150,), dtype='float64')
fact = pymp.shared.array((150,), dtype='float64')
x = int(input("Exponential: Enter value of x (between 0 and 100): "))

def power():
    for i in range(0, 150):
        pwr[i] = pow(x, i)


def factorial():
    fact[0] = 1.0
    for i in range(1, 150):
        num = 1.0
        for j in range(i, 0, -1):
            num *= j
        fact[i] = num


def exp():
    s = 0
    for i in range(0, 150):
        s += (pwr[i]/fact[i])
    
    return s


print(".....Creating Threads.....\n");
with pymp.Parallel(2) as p:
    for sec_idx in p.xrange(2):
        if sec_idx == 0:
            power()
        elif sec_idx == 1:
            factorial()

print(".....Threads Created.....\n");
print(".....Result Collected.....\n\n");


sum = exp()
print("Exponential: Value of ",x," is: ",sum,"\n\n")
