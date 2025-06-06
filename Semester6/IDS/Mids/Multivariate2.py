import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt
import os
os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
myData = pd.read_csv("tips.csv") # use USD_PKR2.csv for line & heatmap plots
# print(myData.head())
# print(myData.columns)
# print(myData.shape)
######### Line Plot #########
# sns.lineplot(data = myData, x='Week', y='USD', ci=None, marker='o')
# sns.lineplot(data = myData, x='Week', y='AUD', ci=None, marker='*')
# sns.lineplot(data = myData, x='Week', y='EUR', ci=None, marker='*', color='red')
# sns.lineplot(data = myData, x='Week', y='AUD', ci=None, marker='d', color='green')
# sns.lineplot(data = myData, x='Month', y='USD', ci=95, marker='d', estimator = np.mean, err_style='bars')
# plt.legend(labels=["USD","EUR","AUD"])
# plt.show()
########### Heat Map ##############
# Jan_Data = myData.iloc[0:180,3:4] # [rows,cols], [r_s:r_e,c_s:c_e]
# Jan_DataR = np.array(Jan_Data).reshape(9,20)
# sns.heatmap(Jan_DataR, cmap='Blues', linewidths=0.5)
# plt.show()
# sns.heatmap(Jan_DataR, annot = True, fmt = '0.2f', linewidths=0.5, square= True, cmap='Blues',annot_kws={"size": 8})
# plt.show()
############# Correlation Heatmap ##########
print(myData.corr())
# sns.heatmap(myData.corr(method ='pearson'))
# sns.heatmap(myData.corr(), annot = True, fmt = '0.2f', linewidths=0.5,cmap='Blues')
# myData2 = myData.iloc[:,0:2] # Skip outcome column
# sns.heatmap(myData2.corr(), annot = True, fmt = '0.2f', linewidths=0.5,cmap='Blues')
# plt.show()
########### Pair Plot ###############
# sns.pairplot(myData)
# plt.show()
########### Stacked Bar chart ###########
# sns.histplot(data=myData, x="day", hue="gender", multiple="fill", stat="count")
# plt.show() # stat = 'count', probability, percent