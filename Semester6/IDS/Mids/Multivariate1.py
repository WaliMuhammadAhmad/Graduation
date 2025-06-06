import pandas as pd
import seaborn as sns
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import os
os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
tipsData = pd.read_csv("tips.csv")
# print(tipsData.head())
# print(tipsData.columns)
# print(tipsData.shape)

####### Scatter Plot #####
# sns.relplot(data = tipsData, x='total_bill', y='tip' )
# sns.relplot(data = tipsData, x='total_bill', y='tip', hue='gender' )
# sns.relplot(data = tipsData, x='total_bill', y='tip', hue='gender', style = 'time' )
# sns.relplot(data = tipsData, x='total_bill', y='tip', hue='gender', col='day')
# sns.relplot(data = tipsData, x='total_bill', y='tip', hue='gender', col='day', row='time')
# sns.relplot(data = tipsData, x='total_bill', y='tip', hue='gender', col='time', row='day', style = 'smoker')
# plt.show()
###### Box Plot ########
# sns.boxplot(data = tipsData, x='gender', y='total_bill')
# sns.boxplot(data = tipsData, x='gender', y='total_bill', hue='day')
# sns.catplot(data = tipsData,kind='swarm', x='gender', y='total_bill', hue='day')
# sns.catplot(data = tipsData,kind='box', x='gender', y='total_bill', hue='day', col='time')
# sns.catplot(data = tipsData,kind='box', x='gender', y='total_bill', hue='time', col='day',row='smoker')
# plt.show()

###### Bar Plot #########
# sns.catplot(data = tipsData,kind='bar', x='day', y='total_bill')
# sns.catplot(data = tipsData,kind='bar', x='gender', y='total_bill', hue='day',col = 'time', ci=None)
# sns.catplot(data = tipsData,kind='bar', x='gender', y='total_bill', hue='day', col='time', row='smoker')
# plt.show()