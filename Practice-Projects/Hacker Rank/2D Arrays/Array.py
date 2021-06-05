import os
import numpy as np
import math

#________________Collecting Outputs_________________
path = os.getcwd()
path += '\output'

expected_outputs = []

for filename in os.listdir(path):
    output_file = open(path + f'\{filename}', 'r')
    expected_outputs.append(int(output_file.read()))
    output_file.close()

print(expected_outputs, "\n")

#________________Collecting Inputs_________________
path = os.getcwd()
path += '\input'

all_inputs = []

for filename in os.listdir(path):
    input_file = open(path + f'\{filename}', 'r')
    all_inputs.append( np.fromfile(input_file, dtype=int, count=-1, sep=' ') )
    input_file.close()

#________________Formating Inputs_________________
array_inputs = []

for unformatted_array in all_inputs:
    array_inputs.append(np.reshape(unformatted_array, (6,6)))

array_inputs = np.array(array_inputs)

#________________Calculating Highest_________________
higest = -math.inf
array_filter = [[1, 1, 1],
                [0, 1, 0],
                [1, 1, 1]]
array_filter = np.array(array_filter)

print(array_inputs)
print("\n\n")

for array in array_inputs:
    #Do this inside loop
    for i in range(3):
        temp = []
        for row in array[i:i+3]:
            temp.append(row[i:i+3])

        temp = np.array(temp)
        print(np.nonzero(temp))
        pattern_exists = True
        # for small_array1, small_array2 in temp, array_filter:
        #     for element1, element2 in small_array1, small_array2:
        #         if element2 == 1:
        #             if element1 == 0:
        #                 pattern_exists = False
        if pattern_exists:
            # print("\nTemp:", temp)
            # print("Dot Product: ", np.sum(np.multiply(temp, array_filter)))
            if higest < np.sum(np.multiply(temp, array_filter)):
                higest = np.sum(np.multiply(temp, array_filter))
        
    # print("Highest: ", higest)
    
    
# print("Highest: ", higest)
