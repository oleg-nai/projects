import numpy as np
import torch
import torch.nn as nn

def get_std(ten,average, eps):
    sum_all = 0
    for i in ten:
        sum_all += (i - average) ** 2
    sum_all = sum_all / len(ten)
    sum_all = sum_all + eps
    sum_all = torch.sqrt(sum_all)
    return sum_all

def get_average(ten):
    return torch.sum(ten) / len(ten)

def get_new_x(x, std, average):
    return  (x - average) / std

def custom_batch_norm1d(input_tensor, eps):
    normed_tensor = torch.clone(input_tensor)
    # normal = torch.sum(normed_tensor, dim=0) / normal.size() # dim =0 - по столбцам
    tmp = torch.transpose(input_tensor, 0, 1)
    j = 0
    for i in tmp:
        average = get_average(i)
        std = get_std(i, average, eps)
        for i in range(normed_tensor.size()[0]):
            normed_tensor[i][j] = get_new_x(normed_tensor[i][j], std, average)
        j += 1
    # tmp = torch.clone(normed_tensor, dim=0)
    return normed_tensor

input_tensor = torch.Tensor([[0.0, 0, 1, 0, 2], [0, 1, 1, 0, 10]])
batch_norm = nn.BatchNorm1d(input_tensor.shape[1], affine=False)

# Проверка происходит автоматически вызовом следующего кода
# (раскомментируйте для самостоятельной проверки,
#  в коде для сдачи задания должно быть закомментировано):
# import numpy as np
# all_correct = True
# for eps_power in range(10):
#     eps = np.power(10., -eps_power)
#     batch_norm.eps = eps
#     batch_norm_out = batch_norm(input_tensor)
#     custom_batch_norm_out = custom_batch_norm1d(input_tensor, eps)

#     all_correct &= torch.allclose(batch_norm_out, custom_batch_norm_out)
#     all_correct &= batch_norm_out.shape == custom_batch_norm_out.shape
# print(all_correct)