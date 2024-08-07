#include "regression.hpp"

int main()
{
    NumericDataSet set("social_meta.txt");
    Encoder* encoder = NULL;
    
    set.addData("social_network.xls",encoder);
    set.shuffleData();

    auto train_test = set.TrainTestSplit(0.75);
    LogisticRegression regression(4,0.000001,0.000000000001,10000,50);
    
    regression.train(*train_test.first);
    regression.showParameters();

    auto true_pred = regression.true_pred(*train_test.second);
    auto train_pred = regression.true_pred(*train_test.first);
   
    std::cout<<"Train Accuracy: "<<100*regression.test_accuracy(train_pred)<<"\n";
    std::cout<<"Accuracy: "<<100*regression.test_accuracy(true_pred)<<"\n";
    regression.confusion_matrix(true_pred);
    regression.confusion_matrix(train_pred);
}   