import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
data = pd.read_csv("LinearRegression.csv")
x = np.array(data['x'])
y = np.array(data['y'])
y_pred = 0
def gradient_descent(x, y, learning_rate, iterate):
    m_curr = b_curr = 0
    iterations = iterate
    n = len(x)
    learning_rate = learning_rate

    for i in range(iterations):
        y_pred = m_curr * x + b_curr
        md = -(2 / n) * sum(x * (y - y_pred))
        bd = -(2 / n) * sum(y - y_pred)

        m_curr = m_curr - learning_rate * md
        b_curr = b_curr - learning_rate * bd


        print(f" m : {m_curr}  b: {b_curr} , iteration : {i}")
gradient_descent(x,y,0.001,15000)

