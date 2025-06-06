import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt
import os

os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
tipsData = pd.read_csv("tips.csv")
# print(tipsData.head())
# print(tipsData.columns)
# print(tipsData.shape)
#### Density / Distribution Plot ######
# sns.displot(data = tipsData, x = 'total_bill', kind='kde') # kind=hist, kde, ecdf
# sns.displot(data = tipsData, x = 'total_bill', y='tip', cbar=True)
# sns.displot(data = tipsData, x = 'day', y='total_bill', cbar=True)
# sns.displot(data = tipsData, x = 'total_bill', hue='gender', kind='ecdf')
# sns.displot(data = tipsData, x = 'total_bill', col='day', kind='hist')
# mean = tipsData['total_bill'].mean()
# median = tipsData['total_bill'].median()
# mode = tipsData['total_bill'].mode()
# plt.axvline(mean,color='r',label='mean')
# plt.axvline(median,color='b',label='median')
# plt.axvline(mode[0],color='g',label='mode')
# plt.legend()
# plt.show()
####### Joint Plot #####
# sns.jointplot(data=tipsData, x='total_bill', y='tip', marginal_ticks=True)
# sns.jointplot(data=tipsData, x='total_bill', y='tip', kind='resid') # scatter, reg, hist,  resid
# plt.show()

