
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score,accuracy_score

cols = ['m1', 'Outcome']
df = pd.read_csv('numbers.txt')
df.columns = cols

x = df.drop(columns=['Outcome'],axis=1)
Y = df['Outcome']

x_train, x_test, Y_train, Y_test = train_test_split(x, Y, test_size=0.25, random_state=42)

model = LogisticRegression(max_iter=10000)

model.fit(x_train, Y_train)

y_pred = model.predict(x_test)

print(accuracy_score(Y_test, y_pred)*100)