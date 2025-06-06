import pandas as pd
import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt
import os

os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
data = pd.read_csv("SalesData.csv")
# print(data.head(4))
# print(data.columns)
# print(data.shape)
fig = plt.figure(figsize=(7,8)) # figsize = (4,4) default is 6.4, 4.8
ax = fig.add_subplot(111)
###### PIE PLOT ####################
values = data['City'].value_counts()
mylabels = data['City'].unique()
# myexplode = [0,0.05,0,0,0,0]
# mycolors = ["red", "green", "blue"]
# plt.pie(values, labels=mylabels)
# plt.pie(values, labels=mylabels, autopct='%1.2f%%',startangle=90, explode=myexplode)
# plt.pie(values, labels=mylabels, startangle=0,
#         autopct='%1.2f%%',
#         textprops={'color':"White"},
#         wedgeprops={'linewidth': 2.0, 'edgecolor': 'white'})
# ax.legend(title = 'Sales Data', loc = 'upper right', bbox_to_anchor=(1.1, 1.1))
# plt.show()
################## BAR PLOT #######
values = data['Product type'].value_counts(sort=False)
mylabels = data['Product type'].unique()
# print(values)
# print(mylabels)
# mycolors = ["red", "yellow", "blue"]
# # # # function to add value labels
# def addValuelabels(mylabels,values):
#        for i in range(len(mylabels)):
#            plt.text(x = i, y = 100, s = values[i], ha = 'center')
# plt.bar(x= mylabels,height=values, width=0.3)
# addValuelabels(mylabels, values)
# plt.show()
################## HISTOGRAM #######
# np.random.seed(0)
# x = np.random.randn(1000)
# values = data['Quantity']
# mycolors = ['black']
# plt.hist(values)
# plt.hist(x= values, bins=5, ec = 'red', rwidth=0.5)
# plt.hist(values, bins= int((max(values)-min(values))/2), ec = 'white', rwidth=0.8)
# plt.xlim([1, 10])
# plt.ylim([100, 700])
# ax.set_xlabel('Quantity Sold')
# ax.set_ylabel('Frequency')
# plt.show()
################# BOX PLOT ###############
values = data['Quantity']
mylabels = ['Quantity']
# plt.boxplot(values, vert=1)
plt.boxplot(values, vert=1, labels = mylabels)
plt.show()
###############