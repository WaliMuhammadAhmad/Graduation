import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import os

os.chdir(r'E:\BS Teaching\Fall2022\IDS\PyProgs\CSV_Files')
data = pd.read_csv("SalesData.csv")
# print(data.head())
# print(data.columns)
# print(data.shape)

###### HISTOGRAMS and DENSITY PLOTS ########

# values = data['Quantity']
# print(min(values))
# print(max(values))
# sns.histplot(values) # all numeric data
# ax = sns.histplot(x=values,  kde=False,
#               binwidth=2, color = 'blue', stat='probability') # bins,
# plt.grid()
# ax = sns.displot(data = values, kind='ecdf') # hist, kde, ecdf
# ax = sns.kdeplot(data = values, shade=True)
# plt.xlim([min(values), max(values)])

# plt.show()

# np.random.seed(0)
# x = np.random.randn(1000)
# ax = sns.displot(x, kind='kde')
# plt.show()
############# Bar Plot ##############
