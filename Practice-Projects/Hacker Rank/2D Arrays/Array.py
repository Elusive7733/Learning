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
higest = []
array_filter = [[1, 1, 1],
                [0, 1, 0],
                [1, 1, 1]]

array_filter = np.array(array_filter)

print(array_inputs)
print("\n\n")

array_number = 0
for array in array_inputs:
    hourglasses = []
    # Collecting the Hourglasses
    for i in range(4):
        for j in range(4):
            hourglasses.append(array[i:i+3, j:j+3])

    # Displaying the Hourglasses
    # print(f"Hourglasses for array {array_number}") 
    hourglasses = np.array(hourglasses)
    # print(hourglasses, "\n")

    for hourglass in hourglasses:
        higest_number = -9999
        pattern_exists = True
        for index, row in enumerate(hourglass):
            if row[0] == 0 and array_filter[index, 0] != 0:
                pattern_exists = False
            if row[1] == 0 and array_filter[index, 1] != 0:
                pattern_exists = False
            if row[2] == 0 and array_filter[index, 2] != 0:
                pattern_exists = False

        if pattern_exists:
            if higest_number < np.sum(np.multiply(hourglass, array_filter)):
                higest_number = np.sum(np.multiply(hourglass, array_filter))
    
    higest.append(higest_number)
    array_number += 1
    
print("Highest: ", higest)
