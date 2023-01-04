import numpy as np 

# array 6 elements that are = 0
a = np.zeros(6)
print("Array with Zeros: ", a)

# (no of dimensions, no of elements in each dimension)
a.shape = (3, 2)
print("\n\nChanging Shape of Array: \n", a)


# creates a range (start, end, no of elements)
b = np.linspace(2, 10, 5)
print("\n\nArray of Range: ", b)

# creates a numpy array using a python list 
c = np.array([10, 20, 30]) 
print("\n\nnp Array using the list syntax: ", c)

p_list = [[0,1,2,3,4,5,6,7,8,9], [9,8,7,6,5,4,3,2,1,0]]
c = np.array(p_list) 
print("\n\nnp Array using the an already created list: \n", c)
print("\nShape: ", c.shape)

# expressions in numpy
print("\nExpression c > 4: \n", c > 4)
print("\nExpression on Array c[c > 4]: ", c[c > 4])
print("Sort Array c[c > 4]: ", np.sort(c[c > 4]))


# creates a numpy array using a random integers  (max, no of elements)
np.random.seed(0)
d = np.random.randint(10, size = 5) 
print("\n\nnp Array using the Random integers: ", d)

# mathematical Functions on np Arrays
print("Sum: ", np.sum(d))
print("Prod: ", np.prod(d))
print("Mean: ", np.mean(d))
print("Standard Deviation: ", np.std(d))
print("Variance: ", np.var(d))
print("Minimum: ", np.min(d))
print("Maximum: ", np.max(d))
print("Argument of Minimum: ", np.argmin(d))
print("Argument of Maximum:", np.argmax(d))

e = np.sin(c)
print("\n\nSin Array: ", e)


# dot product (size should be same)
print("\n\nArray 1: ", b)
print("Array 2: ", d)
print("Dot product of 1 and 2: ", b @ d)

#transpose
print("\n\nArray C:\n", c)
print("\nTranspose of Array C:\n", c.T)