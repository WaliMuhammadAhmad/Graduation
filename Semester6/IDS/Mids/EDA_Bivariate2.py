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

# >>>>> Continuous Vs. Continuous <<<<<
######## Scatter & Line Plot #######
# sns.relplot(data = tipsData, x='total_bill', y='tip' )
# sns.regplot(data = tipsData, x='total_bill', y='tip', fit_reg = True)
# slope, intercept, r_value, p_value, std_err = stats.linregress(tipsData['total_bill'],tipsData['tip'])
# print("Slope ", slope)
# print("Intercept ",intercept)
# print("R-sq ", r_value)
# plt.text(x=20, y=7, s='y={:.2f}+{:.2f}x'.format(intercept, slope), fontsize=20)
# sns.regplot(data = tipsData, x=tipsData['group_size'], y='total_bill', x_estimator=np.mean, ci=95)
# sns.lmplot(data = tipsData, x='total_bill', y='tip' )
# sns.lmplot(data = tipsData, x='group_size', y='total_bill',x_estimator = np.mean, fit_reg = True )
# sns.lineplot(data = tipsData, x='group_size', y='total_bill', errorbar=('ci',95))
# plt.show()
#################################################################

# >>>>> Categorical Vs. Continuous <<<<<<
####### Count, Bar, and Box Plot #####
# sns.countplot(data = tipsData, x='day')
# sns.barplot(data = tipsData, x='day', y='total_bill')
# sns.barplot(data = tipsData, x='gender', y='tip',errorbar = ('ci',95), capsize=0.02, estimator=np.mean)
# sns.boxplot(data = tipsData, x='day', y='total_bill')
# sns.swarmplot(data = tipsData, x='day', y='total_bill')
# plt.show()

# >>>>> Categorical Vs. Categorical <<<<<<
############ Count Plots ###########
sns.countplot(data = tipsData, x='gender', hue='day')
plt.show()


