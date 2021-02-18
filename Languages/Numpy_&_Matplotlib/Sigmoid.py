# import numpy as np
# from matplotlib import pyplot as plt
# import math

# #sigmoid function
# def sigmoid(num):
#   return (1/(1 + np.exp(-num)))

# x = np.random.sample(100)*5 + 1
# print("x: ", x)
# print("\n\n")
# y = []

# for i in range(len(x)):
#   y.append(sigmoid(x[i]))
    
# print("y: ", y)


import matplotlib.pyplot as plt 
import numpy as np 
import math 
  
x = np.linspace(-10, 10, 100) 
z = 1/(1 + np.exp(-x)) 
  
print("x: ", x)
print("\n\n")
print("z: ", z)
plt.plot(x, z) 
plt.xlabel("x") 
plt.ylabel("Sigmoid(X)") 
  
plt.show() 