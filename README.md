# -Machine-Learning-III-CPP_Python

Compile C++:<br />
<br />
bash sh command exemple(linux):<br />
g++ -o program main_india.cpp utils.cpp encoder.cpp math.cpp numeric_data.cpp regression.cpp<br />
<br />
I still need to improve my c++ models,but still a good learning experience<br />
<br />
1.Advertising:<br />
<br />
Both C++ and python model performed good, but the python model had better performances<br />
<br />
C++<br />
<br />
[0.066896,0.154360,0.032748]<br />
[0.018382]<br />
Score: 85.7697<br />
Mean Absolute Error: 1.71058<br />
Mean Squared Error: 4.62365<br />
Root Mean Squared Error: 2.15027<br />
<br />
Python+Optimiations<br />
<br />
Model choice:<br />
check Model_Decision_adv.png<br />
<br />
Optimization:<br />
Sales and Newspaper are not strongly correlated(Based on correlation matrix and plots)<br />
so I was able to get more performance by dropping newspaper<br />
<br />
Metrics:<br />
[0.05629162 0.10595119]<br />
[4.4910921578363965]<br />
R2: 90.33140996752245<br />
Mean Aboslute: 1.23924038194498<br />
MSE: 2.6276441435484172<br />
RMSE: 1.6210009696321643<br />
<br />
2.Social Network<br />
<br />
The C++ model cheated by choosing the dominant class. Python model<br />
had a better performance , but it seemed like a logistic regression<br />
model is not the right model, so i had to find a better model.<br />
<br />
Initial Model(Logistic Regression):<br />
<br />
C++<br />
Social Media:<br />
Train Accuracy: 63.3117<br />
Accuracy: 67.3913<br />
[62,30]<br />
[0,0]<br />
<br />
Python+Optimization:<br />
<br />
Optimization:<br />
Less overfitting by removing m1 coluns<br />
<br />
Metrics:<br />
Train Accuracy:84.61538461538461<br />
Test Accuracy:84.0<br />
Confusion Matrix:<br />
[61 2]<br />
[14 23]<br />
<br />
Final Model:<br />
<br />
Python:<br />
<br />
Choosing model:<br />
The the m3,m4 plot can be patition in four diffrent areas and most of the 0 class<br />
elements lie in the bottom left area.Based on this information a decision tree classifier<br />
seems like the right choice<br />
<br />
Check: Model_Decision_social.png<br />
<br />
Metrics:<br />
Train Accuracy:92.3076923076923<br />
Test Accuracy:92.0<br />
[58 5]<br />
[ 3 34]<br />
<br />
Highest Performance obtained by using entropy as splitting criteria<br />
and a minimum of 10 samples per leaves<br />
<br />
Model without Optimization(Major signs of overfitting):<br />
Train Accuracy:100.0<br />
Test Accuracy:89.0<br />
<br />
3.India:<br />
<br />
The C++ had major over fitting problems.At first the python logistic regression model<br />
didn t perform as good either,but i was able to get some extra performance.<br />
<br />
C++<br />
<br />
[-0.000145,0.010884,-0.025128,-0.000429,0.001137,-0.002761,-0.009039]<br />
[-0.007623]<br />
Train Accuracy: 65.7673<br />
Accuracy: 72<br />
[105,35]<br />
[14,21]<br />
<br />
Python+Optimisation:<br />
<br />
Optimisation:<br />
Correlation Matrix showed a weak corelation between the next columns 'SkinThickness','BloodPressure','Pregnancies'<br />
and Outcome.By removing this columns i and using liblinear solver was able to increace the accuracy from 71% to 74%<br />
<br />
Metrics:<br />
[ 0.02509492 -0.00072515 0.04985525 0.30016214 0.02602032]<br />
[-6.27068356]<br />
Train Accuracy: 77.95138888888889<br />
Test Accuracy: 74.47916666666666<br />
Confusion Matrix:<br />
[103 20]<br />
[ 29 40]<br />
<br />
4.Numbers(Generic Case):<br />
<br />
C++ Underfitting when using mean but 100 prediction otherwise<br />
<br />
C++<br />
Train Accuracy:100<br />
Accuracy: 100<br />
(When the /m is removed, else categorizes either everything as 0 or everything as 1 for some reason)<br />
<br />
Python:<br />
Train Accuracy:100<br />
Accuracy: 100<br />
