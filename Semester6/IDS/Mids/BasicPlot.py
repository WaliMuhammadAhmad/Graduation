import pandas as pd
import matplotlib.pyplot as plt
import os

os.chdir(r'E:\BS Teaching\Fall 2023\IDS\PyProgs\CSV_Files')
data = pd.read_csv("LinearRegression.csv")
print(data.head())
x_val = data['x']
y_val = data['y']


fig = plt.figure()
p1 = fig.add_subplot(221) # Row Col Number
plt.scatter(x_val, y_val, color ='green', s=34, marker='*') # Size
p1.set_xlabel('Age')
p1.set_ylabel('Salary')
plt.title('My 1st Plot')
# plt.xlim([0, 25])
# plt.ylim([0, 700])
# p1.xaxis.label.set_color('red')    #setting up X-axis label color
# p1.tick_params(axis='x', colors='blue')
# p1.spines['left'].set_color('red')


p2 = fig.add_subplot(224) # Row Col Number
plt.scatter(x_val, y_val, color ='red', s=34) # Size
p2.set_xlabel('X Values')
p2.set_ylabel('Y Values')
# plt.title('My 2nd Plot')
# plt.xlim([1, 35])
# plt.ylim([100, 700])
# p2.xaxis.label.set_color('red')    #setting up X-axis label color
# p2.tick_params(axis='x', colors='blue')
# p2.spines['left'].set_color('red')


plt.suptitle("Univariate Analysis") # Super Title
plt.show()


# plt.grid(b=True, which='major', color='b', linestyle='-')
# plt.legend(['Data Points'], loc = 'upper left')
# fig.add_subplot(235) # Row Col Number
# plt.scatter(x_val, y_val)
# plt.show()
# plt.scatter(x_val, y_val, color ='green', s=y_val) # Size
# plt.scatter(x_val, y_val, color ='green', marker='d') # marker [*,d,s,<,>]
# plt.scatter(x_val, y_val, color ='green', alpha=0.2) # Transparency
# plt.show()
# ax.set_xlabel('Age')
# ax.set_ylabel('Salary ')
# plt.title('X Y Scatter Plot', color = 'green')
# plt.show()
#

# p1.xaxis.label.set_color('red')    #setting up X-axis label color
# ax.yaxis.label.set_color('blue')   #setting up Y-axis label color

#

# p1.tick_params(axis='x', colors='blue')    #setting up X-axis tick color
# ax.tick_params(axis='y', colors='red')  #setting up Y-axis tick color

# ax.spines['left'].set_color('red')
# ax.spines['top'].set_color('red')
# ax.spines['right'].set_color('blue')
# ax.spines['bottom'].set_color('blue')
#
# plt.xlim([1, 35])
# plt.ylim([100, 700])

# plt.grid(b=True, which='major', color='b', linestyle='-')
# plt.show()
# plt.grid(b=True, which='minor', color='r', linestyle='-')
# plt.show()

# plt.scatter(x_val, y_val, color ='green')
# plt.legend(['Data Points'], loc = 'upper left')
# plt.show()


