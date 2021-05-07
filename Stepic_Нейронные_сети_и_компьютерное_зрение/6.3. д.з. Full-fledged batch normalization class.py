# В данном шаге требуется реализовать полноценный класс батч-нормализации 
# без использования стандартной функции, принимающий на вход двумерный тензор. 
# Расчёт дисперсии ведётся по смещенной выборке, а расчет скользящего среднего по несмещенной.

import torch
import torch.nn as nn


input_size = 3
batch_size = 5
eps = 1e-1


class CustomBatchNorm1d:
    def __init__(self, weight, bias, eps, momentum):
        # Реализуйте в этом месте конструктор.
        self.weight = weight
        self.bias = bias
        self.eps = eps
        self.momentum = momentum
        self.training = True
        self.ema_mn = 0                                           # Скользящая средняя средних значений
        self.ema_var = 1                                          # Скользащяя средняя дисперсии

    def __call__(self, input_tensor):
        # Напишите в этом месте нормирование входного тензора.
        mn = torch.mean(input_tensor, 0)                           # Среднее значение батча
        var = torch.var(input_tensor, 0, unbiased=False)           # Дисперсия по батчу (var = std**2)
        m = input_tensor.size(0)                                   # Количество значений (размер батча)
        
        if self.training:
            # Если модель тренируется, то применяем средние значения по батчу
            self.ema_mn = (1 - self.momentum) * self.ema_mn + self.momentum * mn
            self.ema_var = (1 - self.momentum) * var * (m / (m - 1)) + self.momentum * self.ema_var
        else:
            # Если модель в режиме предсказания, то применяем накопленные скользящии среднии
            mn = self.ema_mn
            var = self.ema_var

        # Выполняем нормировку тензора
        normed_tensor = (input_tensor - mn) / (var + self.eps)**(1/2) * self.weight + self.bias
        return normed_tensor

    def eval(self):
        # В этом методе реализуйте переключение в режим предикта.
        self.training = False


batch_norm = nn.BatchNorm1d(input_size, eps=eps)
batch_norm.bias.data = torch.randn(input_size, dtype=torch.float)
batch_norm.weight.data = torch.randn(input_size, dtype=torch.float)
batch_norm.momentum = 0.5

custom_batch_norm1d = CustomBatchNorm1d(batch_norm.weight.data,
                                        batch_norm.bias.data, eps, batch_norm.momentum)

# Проверка происходит автоматически вызовом следующего кода
# (раскомментируйте для самостоятельной проверки,
#  в коде для сдачи задания должно быть закомментировано):
# all_correct = True

# for i in range(8):
#     torch_input = torch.randn(batch_size, input_size, dtype=torch.float)
#     norm_output = batch_norm(torch_input)
#     custom_output = custom_batch_norm1d(torch_input)
#     all_correct &= torch.allclose(norm_output, custom_output) \
#         and norm_output.shape == custom_output.shape

# batch_norm.eval()
# custom_batch_norm1d.eval()

# for i in range(8):
#     torch_input = torch.randn(batch_size, input_size, dtype=torch.float)
#     norm_output = batch_norm(torch_input)
#     custom_output = custom_batch_norm1d(torch_input)
#     all_correct &= torch.allclose(norm_output, custom_output) \
#         and norm_output.shape == custom_output.shape
# print(all_correct)