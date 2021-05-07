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
    "import pandas as pd"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {},
   "outputs": [],
   "source": [
    "data_tmp = pd.read_csv(\"titanic/test.csv\", index_col=\"PassengerId\")\n",
    "gender_data = pd.read_csv(\"titanic/gender_submission.csv\", index_col=\"PassengerId\")\n",
    "data = pd.concat([data_tmp,gender_data], axis=1)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {},
   "outputs": [
    {
     "output_type": "execute_result",
     "data": {
      "text/plain": [
       "             Pclass                                          Name     Sex  \\\n",
       "PassengerId                                                                 \n",
       "892               3                              Kelly, Mr. James    male   \n",
       "893               3              Wilkes, Mrs. James (Ellen Needs)  female   \n",
       "894               2                     Myles, Mr. Thomas Francis    male   \n",
       "895               3                              Wirz, Mr. Albert    male   \n",
       "896               3  Hirvonen, Mrs. Alexander (Helga E Lindqvist)  female   \n",
       "897               3                    Svensson, Mr. Johan Cervin    male   \n",
       "898               3                          Connolly, Miss. Kate  female   \n",
       "899               2                  Caldwell, Mr. Albert Francis    male   \n",
       "900               3     Abrahim, Mrs. Joseph (Sophie Halaut Easu)  female   \n",
       "901               3                       Davies, Mr. John Samuel    male   \n",
       "\n",
       "              Age  SibSp  Parch     Ticket     Fare Cabin Embarked  Survived  \n",
       "PassengerId                                                                   \n",
       "892          34.5      0      0     330911   7.8292   NaN        Q         0  \n",
       "893          47.0      1      0     363272   7.0000   NaN        S         1  \n",
       "894          62.0      0      0     240276   9.6875   NaN        Q         0  \n",
       "895          27.0      0      0     315154   8.6625   NaN        S         0  \n",
       "896          22.0      1      1    3101298  12.2875   NaN        S         1  \n",
       "897          14.0      0      0       7538   9.2250   NaN        S         0  \n",
       "898          30.0      0      0     330972   7.6292   NaN        Q         1  \n",
       "899          26.0      1      1     248738  29.0000   NaN        S         0  \n",
       "900          18.0      0      0       2657   7.2292   NaN        C         1  \n",
       "901          21.0      2      0  A/4 48871  24.1500   NaN        S         0  "
      ],
      "text/html": "<div>\n<style scoped>\n    .dataframe tbody tr th:only-of-type {\n        vertical-align: middle;\n    }\n\n    .dataframe tbody tr th {\n        vertical-align: top;\n    }\n\n    .dataframe thead th {\n        text-align: right;\n    }\n</style>\n<table border=\"1\" class=\"dataframe\">\n  <thead>\n    <tr style=\"text-align: right;\">\n      <th></th>\n      <th>Pclass</th>\n      <th>Name</th>\n      <th>Sex</th>\n      <th>Age</th>\n      <th>SibSp</th>\n      <th>Parch</th>\n      <th>Ticket</th>\n      <th>Fare</th>\n      <th>Cabin</th>\n      <th>Embarked</th>\n      <th>Survived</th>\n    </tr>\n    <tr>\n      <th>PassengerId</th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n      <th></th>\n    </tr>\n  </thead>\n  <tbody>\n    <tr>\n      <th>892</th>\n      <td>3</td>\n      <td>Kelly, Mr. James</td>\n      <td>male</td>\n      <td>34.5</td>\n      <td>0</td>\n      <td>0</td>\n      <td>330911</td>\n      <td>7.8292</td>\n      <td>NaN</td>\n      <td>Q</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>893</th>\n      <td>3</td>\n      <td>Wilkes, Mrs. James (Ellen Needs)</td>\n      <td>female</td>\n      <td>47.0</td>\n      <td>1</td>\n      <td>0</td>\n      <td>363272</td>\n      <td>7.0000</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>1</td>\n    </tr>\n    <tr>\n      <th>894</th>\n      <td>2</td>\n      <td>Myles, Mr. Thomas Francis</td>\n      <td>male</td>\n      <td>62.0</td>\n      <td>0</td>\n      <td>0</td>\n      <td>240276</td>\n      <td>9.6875</td>\n      <td>NaN</td>\n      <td>Q</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>895</th>\n      <td>3</td>\n      <td>Wirz, Mr. Albert</td>\n      <td>male</td>\n      <td>27.0</td>\n      <td>0</td>\n      <td>0</td>\n      <td>315154</td>\n      <td>8.6625</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>896</th>\n      <td>3</td>\n      <td>Hirvonen, Mrs. Alexander (Helga E Lindqvist)</td>\n      <td>female</td>\n      <td>22.0</td>\n      <td>1</td>\n      <td>1</td>\n      <td>3101298</td>\n      <td>12.2875</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>1</td>\n    </tr>\n    <tr>\n      <th>897</th>\n      <td>3</td>\n      <td>Svensson, Mr. Johan Cervin</td>\n      <td>male</td>\n      <td>14.0</td>\n      <td>0</td>\n      <td>0</td>\n      <td>7538</td>\n      <td>9.2250</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>898</th>\n      <td>3</td>\n      <td>Connolly, Miss. Kate</td>\n      <td>female</td>\n      <td>30.0</td>\n      <td>0</td>\n      <td>0</td>\n      <td>330972</td>\n      <td>7.6292</td>\n      <td>NaN</td>\n      <td>Q</td>\n      <td>1</td>\n    </tr>\n    <tr>\n      <th>899</th>\n      <td>2</td>\n      <td>Caldwell, Mr. Albert Francis</td>\n      <td>male</td>\n      <td>26.0</td>\n      <td>1</td>\n      <td>1</td>\n      <td>248738</td>\n      <td>29.0000</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>900</th>\n      <td>3</td>\n      <td>Abrahim, Mrs. Joseph (Sophie Halaut Easu)</td>\n      <td>female</td>\n      <td>18.0</td>\n      <td>0</td>\n      <td>0</td>\n      <td>2657</td>\n      <td>7.2292</td>\n      <td>NaN</td>\n      <td>C</td>\n      <td>1</td>\n    </tr>\n    <tr>\n      <th>901</th>\n      <td>3</td>\n      <td>Davies, Mr. John Samuel</td>\n      <td>male</td>\n      <td>21.0</td>\n      <td>2</td>\n      <td>0</td>\n      <td>A/4 48871</td>\n      <td>24.1500</td>\n      <td>NaN</td>\n      <td>S</td>\n      <td>0</td>\n    </tr>\n  </tbody>\n</table>\n</div>"
     },
     "metadata": {},
     "execution_count": 6
    }
   ],
   "source": [
    "data.head(10)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {},
   "outputs": [
    {
     "output_type": "stream",
     "name": "stdout",
     "text": [
      "266 152\n"
     ]
    }
   ],
   "source": [
    "# task 1 \n",
    "print (data[\"Sex\"].value_counts()[0], data[\"Sex\"].value_counts()[1])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "metadata": {},
   "outputs": [
    {
     "output_type": "stream",
     "name": "stdout",
     "text": [
      "36.36\n"
     ]
    }
   ],
   "source": [
    "# task 2, 0-die, 1 - Survived\n",
    "print (\"%.2f\" % (gender_data[\"Survived\"].value_counts()[1]/data[\"Survived\"].count() * 100))\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 15,
   "metadata": {},
   "outputs": [
    {
     "output_type": "stream",
     "name": "stdout",
     "text": [
      "25.60\n"
     ]
    }
   ],
   "source": [
    "# task 3, Pclass: 1 - upper\n",
    "print(\"%.2f\" % (data[\"Pclass\"].value_counts()[1] / data[\"Survived\"].count() * 100))\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "metadata": {},
   "outputs": [
    {
     "output_type": "error",
     "ename": "AttributeError",
     "evalue": "'Series' object has no attribute 'mxean'",
     "traceback": [
      "\u001b[1;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[1;31mAttributeError\u001b[0m                            Traceback (most recent call last)",
      "\u001b[1;32m<ipython-input-16-be32e134f223>\u001b[0m in \u001b[0;36m<module>\u001b[1;34m\u001b[0m\n\u001b[0;32m      1\u001b[0m \u001b[1;31m# task 4\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m----> 2\u001b[1;33m \u001b[0mprint\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mdata\u001b[0m\u001b[1;33m[\u001b[0m\u001b[1;34m\"Age\"\u001b[0m\u001b[1;33m]\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0mmxean\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mdata\u001b[0m\u001b[1;33m[\u001b[0m\u001b[1;34m\"Age\"\u001b[0m\u001b[1;33m]\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0mmedian\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m",
      "\u001b[1;32m~\\AppData\\Local\\Programs\\Python\\Python37\\lib\\site-packages\\pandas\\core\\generic.py\u001b[0m in \u001b[0;36m__getattr__\u001b[1;34m(self, name)\u001b[0m\n\u001b[0;32m   5137\u001b[0m             \u001b[1;32mif\u001b[0m \u001b[0mself\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m_info_axis\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m_can_hold_identifiers_and_holds_name\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mname\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   5138\u001b[0m                 \u001b[1;32mreturn\u001b[0m \u001b[0mself\u001b[0m\u001b[1;33m[\u001b[0m\u001b[0mname\u001b[0m\u001b[1;33m]\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m-> 5139\u001b[1;33m             \u001b[1;32mreturn\u001b[0m \u001b[0mobject\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0m__getattribute__\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mself\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mname\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m   5140\u001b[0m \u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   5141\u001b[0m     \u001b[1;32mdef\u001b[0m \u001b[0m__setattr__\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mself\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mname\u001b[0m\u001b[1;33m:\u001b[0m \u001b[0mstr\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mvalue\u001b[0m\u001b[1;33m)\u001b[0m \u001b[1;33m->\u001b[0m \u001b[1;32mNone\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n",
      "\u001b[1;31mAttributeError\u001b[0m: 'Series' object has no attribute 'mxean'"
     ]
    }
   ],
   "source": [
    "# task 4\n",
    "print(data[\"Age\"].mxean(), data[\"Age\"].median())"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "metadata": {},
   "outputs": [
    {
     "output_type": "execute_result",
     "data": {
      "text/plain": [
       "             SibSp  Parch\n",
       "PassengerId              \n",
       "892              0      0\n",
       "893              1      0\n",
       "894              0      0\n",
       "895              0      0\n",
       "896              1      1\n",
       "...            ...    ...\n",
       "1305             0      0\n",
       "1306             0      0\n",
       "1307             0      0\n",
       "1308             0      0\n",
       "1309             1      1\n",
       "\n",
       "[418 rows x 2 columns]"
      ],
      "text/html": "<div>\n<style scoped>\n    .dataframe tbody tr th:only-of-type {\n        vertical-align: middle;\n    }\n\n    .dataframe tbody tr th {\n        vertical-align: top;\n    }\n\n    .dataframe thead th {\n        text-align: right;\n    }\n</style>\n<table border=\"1\" class=\"dataframe\">\n  <thead>\n    <tr style=\"text-align: right;\">\n      <th></th>\n      <th>SibSp</th>\n      <th>Parch</th>\n    </tr>\n    <tr>\n      <th>PassengerId</th>\n      <th></th>\n      <th></th>\n    </tr>\n  </thead>\n  <tbody>\n    <tr>\n      <th>892</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>893</th>\n      <td>1</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>894</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>895</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>896</th>\n      <td>1</td>\n      <td>1</td>\n    </tr>\n    <tr>\n      <th>...</th>\n      <td>...</td>\n      <td>...</td>\n    </tr>\n    <tr>\n      <th>1305</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>1306</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>1307</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>1308</th>\n      <td>0</td>\n      <td>0</td>\n    </tr>\n    <tr>\n      <th>1309</th>\n      <td>1</td>\n      <td>1</td>\n    </tr>\n  </tbody>\n</table>\n<p>418 rows × 2 columns</p>\n</div>"
     },
     "metadata": {},
     "execution_count": 17
    }
   ],
   "source": [
    "# task 5\n",
    "\n",
    "#  Коррелируют ли число братьев/сестер/супругов с числом родителей/детей? Посчитайте корреляцию Пирсона между признаками SibSp и Parch.\n",
    "\n",
    "# r = sum((x_i - x ) * (y_i - y)) / sqrt(sum(x_i - x)^2 * sum(y_i - y)^ 2)\n",
    "data_pearson = pd.concat([data[\"SibSp\"],data[\"Parch\"]], axis =1)\n",
    "data_pearson\n",
    "# data_pearson.corr(method=\"pearson\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 251,
   "metadata": {},
   "outputs": [
    {
     "output_type": "execute_result",
     "data": {
      "text/plain": [
       "'John'"
      ]
     },
     "metadata": {},
     "execution_count": 251
    }
   ],
   "source": [
    "# task 6\n",
    "# Какое самое популярное женское имя на корабле? Извлеките из полного имени пассажира (колонка Name) его личное имя (First Name). Это задание — типичный пример того, с чем сталкивается специалист по анализу данных. Данные очень разнородные и шумные, но из них требуется извлечь необходимую информацию. Попробуйте вручную разобрать несколько значений столбца Name и выработать правило для извлечения имен, а также разделения их на женские и мужские.\n",
    "\n",
    "data[data[\"Sex\"] == \"female\"][\"Name\"].str.split(\" \").str[2].value_counts(sort=True).index[0]"
   ]
  }
 ]
}