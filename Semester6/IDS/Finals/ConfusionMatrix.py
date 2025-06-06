import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score, ConfusionMatrixDisplay
from sklearn import metrics
import os
####################################
os.chdir(r'E:\BS Teaching\Fall2022\IDS\PyProgs\CSV_Files')
data = pd.read_csv("ConfusionMatrix2.csv")
# print(data.head())
f1 = np.array(data['Age'])
f2 = np.array(data['RestingBP'])
f3 = np.array(data['Cholesterol'])
f4 = np.array(data['MaxHR'])
label = np.array(data['HeartDisease'])
########## Scaling ###########
features=list(zip(f1, f2, f3, f4))
X_train, X_test, y_train, y_test = train_test_split(features, label, test_size=0.2, random_state=0)
print(len(X_train))
print(len(X_test))
######## Get Model
model = KNeighborsClassifier(n_neighbors=3)
# Train the model using the training sets
model.fit(X_train, y_train)
#Predict Output
y_pred= model.predict(X_test)
# for i in range(len(y_test)):
#    print(X_test[i], "A:",y_test[i],"P:", y_pred[i], "\n")
cm = confusion_matrix(y_test, y_pred)
ac  = accuracy_score(y_test, y_pred)
cm_report = metrics.classification_report(y_test,y_pred)
print(cm_report)
# print(np.transpose(cm))
# print(ac)
# print(cm_report)
# cmd = ConfusionMatrixDisplay(cm, display_labels=['0','1'])
# cmd.plot(colorbar=False, cmap='Blues')
# plt.show()