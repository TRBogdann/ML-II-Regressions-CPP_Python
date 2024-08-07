
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score,accuracy_score,confusion_matrix, roc_curve, roc_auc_score
import matplotlib.pyplot as plt


def show_graph(frame, col1, col2):
    scatter = plt.scatter(x=frame[col1], y=frame[col2], c=frame['Outcome'], cmap='viridis')
    plt.colorbar(scatter, label='Outcome')
    plt.title('Check')
    plt.xlabel(col1)
    plt.ylabel(col2)
    plt.show()


df = pd.read_csv('diabetes_india.csv')

print(df.describe())

print(df.corr())

x = df.drop(columns=['Outcome'],axis=1)
Y = df['Outcome']

cols = x.columns

for i in range(0, len(cols)-1):
    for j in range(i+1, len(cols)):
        show_graph(df, cols[i], cols[j])


x = x.drop(columns=['SkinThickness','BloodPressure','Pregnancies'],axis=1)

x_train, x_test, Y_train, Y_test = train_test_split(x, Y, test_size=0.25, random_state=42)

model = LogisticRegression(max_iter=10000,random_state=42,solver='liblinear')

model.fit(x_train, Y_train)

y_pred = model.predict(x_test)
y_train_pred = model.predict(x_train)

print(accuracy_score(Y_train, y_train_pred)*100)
print(accuracy_score(Y_test, y_pred)*100)


print(model.intercept_)
print(model.coef_)
plt.clf()

confusion_matrix = confusion_matrix(Y_test, y_pred)
print(confusion_matrix)

