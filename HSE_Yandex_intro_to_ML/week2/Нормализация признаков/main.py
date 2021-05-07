{
 "metadata": {
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.7.6-final"
  },
  "orig_nbformat": 2,
  "kernelspec": {
   "name": "python37664bit55e3c30dd1704996afb54c2864177791",
   "display_name": "Python 3.7.6 64-bit"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2,
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {},
   "outputs": [],
   "source": [
    "import numpy as no\n",
    "import pandas as pd\n",
    "from sklearn.linear_model import perceptron\n",
    "from sklearn.preprocessing import StandardScaler"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {},
   "outputs": [],
   "source": [
    "data = pd.read_csv('data/perceptron-test.csv', header=None)\n",
    "y = data[0] # классы\n",
    "X = data.drop(0, 1) # признаки"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 21,
   "metadata": {},
   "outputs": [
    {
     "output_type": "execute_result",
     "data": {
      "text/plain": [
       "            1            2\n",
       "0    1.651437  1337.453826\n",
       "1   -0.866495  1191.232457\n",
       "2    0.789828  -475.647768\n",
       "3    0.179549  1959.095353\n",
       "4   -0.434351   568.504207\n",
       "..        ...          ...\n",
       "195  1.150206  2559.850231\n",
       "196 -0.732462   159.748695\n",
       "197  0.412912 -1587.206427\n",
       "198 -0.098685   682.034777\n",
       "199  0.760949 -1577.448794\n",
       "\n",
       "[200 rows x 2 columns]"
      ],
      "text/html": "<div>\n<style scoped>\n    .dataframe tbody tr th:only-of-type {\n        vertical-align: middle;\n    }\n\n    .dataframe tbody tr th {\n        vertical-align: top;\n    }\n\n    .dataframe thead th {\n        text-align: right;\n    }\n</style>\n<table border=\"1\" class=\"dataframe\">\n  <thead>\n    <tr style=\"text-align: right;\">\n      <th></th>\n      <th>1</th>\n      <th>2</th>\n    </tr>\n  </thead>\n  <tbody>\n    <tr>\n      <th>0</th>\n      <td>1.651437</td>\n      <td>1337.453826</td>\n    </tr>\n    <tr>\n      <th>1</th>\n      <td>-0.866495</td>\n      <td>1191.232457</td>\n    </tr>\n    <tr>\n      <th>2</th>\n      <td>0.789828</td>\n      <td>-475.647768</td>\n    </tr>\n    <tr>\n      <th>3</th>\n      <td>0.179549</td>\n      <td>1959.095353</td>\n    </tr>\n    <tr>\n      <th>4</th>\n      <td>-0.434351</td>\n      <td>568.504207</td>\n    </tr>\n    <tr>\n      <th>...</th>\n      <td>...</td>\n      <td>...</td>\n    </tr>\n    <tr>\n      <th>195</th>\n      <td>1.150206</td>\n      <td>2559.850231</td>\n    </tr>\n    <tr>\n      <th>196</th>\n      <td>-0.732462</td>\n      <td>159.748695</td>\n    </tr>\n    <tr>\n      <th>197</th>\n      <td>0.412912</td>\n      <td>-1587.206427</td>\n    </tr>\n    <tr>\n      <th>198</th>\n      <td>-0.098685</td>\n      <td>682.034777</td>\n    </tr>\n    <tr>\n      <th>199</th>\n      <td>0.760949</td>\n      <td>-1577.448794</td>\n    </tr>\n  </tbody>\n</table>\n<p>200 rows × 2 columns</p>\n</div>"
     },
     "metadata": {},
     "execution_count": 21
    }
   ],
   "source": [
    "X"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ]
}