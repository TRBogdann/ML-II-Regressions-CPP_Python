#include "regression.hpp"

int main()
{
    NumericDataSet set("india_meta.txt");
    Encoder* encoder = NULL;
    
    set.addData("diabetes_india.csv",encoder);
    set.shuffleData();

    auto train_test = set.TrainTestSplit(0.75);
    LogisticRegression regression(7,0.000001,0.00001);
    
    regression.train(*train_test.first);
    regression.showParameters();

    auto true_pred = regression.true_pred(*train_test.second);
    auto train_pred = regression.true_pred(*train_test.first);
   
   // Math::Vector w(7,(double[]){0.06105258 ,0.03600261,-0.01261803, 0.00464927,-0.00157578 ,0.10178081,
   //0.45692849,0.03787888});
    //Math::Vector b(1,(double[]){-9.28764478}); 

    std::cout<<"Train Accuracy: "<<100*regression.test_accuracy(train_pred)<<"\n";
    std::cout<<"Accuracy: "<<100*regression.test_accuracy(true_pred)<<"\n";
    regression.confusion_matrix(true_pred);
}   