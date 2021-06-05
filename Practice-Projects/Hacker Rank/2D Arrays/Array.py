import os
import numpy as np

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
# print(all_inputs)
array_inputs = []

for unformatted_array in all_inputs:
    array_inputs.append(np.reshape(unformatted_array, (6,6)))



for array in array_inputs:
    print(array)