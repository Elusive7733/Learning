import os
import numpy as np
# 1 1 1 0 0 0
# 0 1 0 0 0 0
# 1 1 1 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0

#________________Collecting Outputs_________________
path = os.getcwd()
path += '\output'

expected_outputs = []

for filename in os.listdir(path):
    output_file = open(path + f'\{filename}', 'r')
    expected_outputs.append(int(output_file.read()))
    output_file.close()

print(expected_outputs)

#________________Collecting Inputs_________________
path = os.getcwd()
path += '\input'

all_inputs = []

for filename in os.listdir(path):
    input_file = open(path + f'\{filename}', 'r')
    all_inputs.append(input_file.read())
    input_file.close()


print(all_inputs)

array_