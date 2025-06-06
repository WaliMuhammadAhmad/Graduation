from sklearn.metrics import confusion_matrix,classification_report
from sklearn.metrics import  ConfusionMatrixDisplay
import numpy as np
import matplotlib.pyplot as plt
# #### Classes ##########
y_actual =['Dog','Dog','Cat','Dog','Cat','Cat','Cat','Dog','Dog','Cat']
y_predict=['Cat','Dog','Cat','Dog','Dog','Cat','Cat','Dog','Cat','Cat']
cm = confusion_matrix(y_true=y_actual, y_pred=y_predict)
cm = np.transpose(cm)
print(cm)
cm_report = classification_report(y_actual,y_predict, digits=3)
print(cm_report)
cmd = ConfusionMatrixDisplay(cm, display_labels=['Cat','Dog'])
cmd.plot(colorbar=False, cmap='Blues')
cmd.ax_.set(xlabel='Actual', ylabel='Predicted', title='Confusion Matrix Actual vs Predicted')
plt.show()
