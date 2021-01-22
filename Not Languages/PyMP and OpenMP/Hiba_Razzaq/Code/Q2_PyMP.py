import pymp
from time import sleep

count = 0
COUNT_DONE = 10
COUNT_HALT1 = 3
COUNT_HALT2 = 6


def function1(p):
    global count
    while(True):
        while(count >= COUNT_HALT1 and count <= COUNT_HALT2):
            sleep(1)

        with p.lock:
            count += 1
            print("Function 1, Counter Value: ",count,"\n")
        if(count >= COUNT_DONE):
            return


def function2(p):
    global count
    while(True):
        while(count < COUNT_HALT1 or count > COUNT_HALT2):
            sleep(1)
        
        with p.lock:
            count += 1
            print("Function 2, Counter Value: ",count,"\n")
        if(count >= COUNT_DONE):
            return
            

with pymp.Parallel(2) as p:
    for sec_idx in p.xrange(2):
        if sec_idx == 0:
            function1(p)
        elif sec_idx == 1:
            function2(p)
        