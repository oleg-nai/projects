import numpy as np
import cv2
import os


def noisy(noise_typ,image):
   if noise_typ == "gauss":
      row,col,ch= image.shape
      mean = 51
      var = 0.1
      sigma = var**0.5
      gauss = np.random.normal(mean,sigma,(row,col,ch))
      gauss = gauss.reshape(row,col,ch)
      noisy = image + gauss
      return noisy
      # row,col,ch= image.shape
      # mean = 0.1
      # var = 5000
      # sigma = var**0.5
      # gauss = np.random.normal(mean,sigma,(row,col,ch))
      # gauss = gauss.reshape(row,col,ch)
      # noisy = image + gauss
      # return noisy
   elif noise_typ == "s&p":
      row,col,ch = image.shape
      s_vs_p = 0.5
      amount = 0.25
      out = np.copy(image)
      # Salt mode
      num_salt = np.ceil(amount * image.size * s_vs_p)
      coords = [np.random.randint(0, i - 1, int(num_salt))
              for i in image.shape]
      out[coords] = 1

      # Pepper mode
      num_pepper = np.ceil(amount* image.size * (1. - s_vs_p))
      coords = [np.random.randint(0, i - 1, int(num_pepper))
              for i in image.shape]
      out[coords] = 0
      return out
   elif noise_typ == "poisson":
      noise_mask = np.random.poisson(image)
      noisy_img = image + noise_mask
      return noisy_img
   elif noise_typ =="speckle":
      row,col,ch = image.shape
      gauss = np.random.randn(row,col,ch)
      gauss = gauss.reshape(row,col,ch)        
      noisy = image + image * gauss
      return noisy
      


files = os.listdir("clear")
for i in files:
   im = cv2.imread("clear/" + i)
   out = noisy("gauss", im) 
   cv2.imwrite("noisy/" + i, out)
