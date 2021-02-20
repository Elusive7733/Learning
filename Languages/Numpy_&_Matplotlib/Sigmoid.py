import matplotlib.pyplot as plt 
import numpy as np 

#sigmoid function
def sigmoid(num):
  return (1/(1 + np.exp(-num)))


  
x = np.linspace(-10, 10, 100)
y = []
for i in range(len(x)):
  y.append(sigmoid(x[i]))
  

plt.plot(x, y, "^") 
plt.xlabel("x") 
plt.ylabel("Sigmoid Function") 
  
plt.show() 

