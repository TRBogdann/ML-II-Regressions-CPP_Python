
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score,mean_absolute_error,mean_squared_error,root_mean_squared_error
import category_encoders as ce
import matplotlib.pyplot as plt


def show_graph(frame, col1, col2):
    scatter = plt.scatter(x=frame[col1], y=frame[col2], c=frame['Sales'], cmap='viridis')
    plt.colorbar(scatter, label='Sales')
    plt.title('Check')
    plt.xlabel(col1)
    plt.ylabel(col2)
    plt.show()


df = pd.read_csv('advertising.csv')
print(df.corr)
cols = df.columns.copy()

for i in range(0, len(cols)-1):
    for j in range(i+1, len(cols)):
        show_graph(df, cols[i], cols[j])

x = df.drop(columns=['Sales','Newspaper'], axis=1)
y = df['Sales']

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.75, random_state=42)

model = LinearRegression()
model.fit(x_train, y_train)

y_pred = model.predict(x_test)

print(model.intercept_)
print(model.coef_)
print("R2: ", r2_score(y_test, y_pred)*100)
print("Mean Aboslute: ", mean_absolute_error(y_test, y_pred))
print("MSE: ", mean_squared_error(y_test, y_pred))
print("RMSE: ", root_mean_squared_error(y_test, y_pred))

plt.clf()
