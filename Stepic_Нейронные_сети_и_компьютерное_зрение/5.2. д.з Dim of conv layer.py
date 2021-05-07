import numpy as np


def calc_out_shape(input_matrix_shape, out_channels, kernel_size, stride, padding):
    
    out_shape = [list(input_matrix_shape)[0], out_channels] # т.к. кол-во картинок не изменяется
    weight = input_matrix_shape[2]
    out_weight = int((weight - kernel_size + 2 * padding) / stride + 1)
    out_shape.append(out_weight)
    out_shape.append(out_weight)
    return out_shape

print(np.array_equal(
    calc_out_shape(input_matrix_shape=[2, 3, 10, 10],
                   out_channels=10,
                   kernel_size=3,
                   stride=1,
                   padding=0),
    [2, 10, 8, 8]))

# ... и ещё несколько подобных кейсов