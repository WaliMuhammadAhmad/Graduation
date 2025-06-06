import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.neighbors import KNeighborsClassifier
import os
os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')

data = pd.read_csv("kNN_Dataset.csv")
print(data.head())
h = np.array(data['Height'])
w = np.array(data['Weight'])
label = np.array(data['Shirt'])
features=list(zip(h,w))

# df_X = pd.DataFrame(data, columns=['Glucose','BP','SkinThickness','Insulin','BMI','DPF','Age'])
# print(df_X.head())
# features = df_X
# label = data['Diabetes']
################# PLOT ############
sns.relplot(x=h, y=w, hue=label, s=100, data = data)
plt.show()
#

# # Get Model
model = KNeighborsClassifier(n_neighbors=5)
# # Train the model using the training sets
model.fit(features,label)
# #Predict Output
predicted= model.predict([[163.5,62.5]]) # h, w
# predicted= model.predict([[150,70,22,456,35.7,0.32,48]]) # h, w
print(predicted)

