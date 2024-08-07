
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score, accuracy_score,confusion_matrix, roc_curve, roc_auc_score
import category_encoders as ce
import matplotlib.pyplot as plt

def show_graph(frame, col1, col2):
    scatter = plt.scatter(x=frame[col1], y=frame[col2], c=frame['result'], cmap='viridis')
    plt.colorbar(scatter, label='result')
    plt.title('Check')
    plt.xlabel(col1)
    plt.ylabel(col2)
    plt.show()

cols = ['m1', 'gender', 'm3', 'm4', 'result']

df = pd.read_csv('social.csv')

df.columns = cols

cols = ['m1', 'gender', 'm3', 'm4']

#for i in range(0, len(cols)-1):
#    for j in range(i+1, len(cols)):
#        show_graph(df, cols[i], cols[j])


x = df.drop(columns=['result','m1'], axis=1)
Y = df['result']

encoder = ce.OneHotEncoder(cols=['gender'])
df_encoded = encoder.fit_transform(df)
print(df_encoded.corr())

x_train, x_test, Y_train, Y_test = train_test_split(x, Y, test_size=0.25, random_state=42)

x_train = encoder.fit_transform(x_train)
x_test = encoder.transform(x_test)

model = DecisionTreeClassifier(criterion='entropy', random_state=42,min_samples_leaf=10)

model.fit(x_train, Y_train)

y_train_pred = model.predict(x_train)
y_pred = model.predict(x_test)

print(accuracy_score(Y_train, y_train_pred)*100)
print(accuracy_score(Y_test, y_pred)*100)

confusion_matrix = confusion_matrix(Y_test, y_pred)
print(confusion_matrix)