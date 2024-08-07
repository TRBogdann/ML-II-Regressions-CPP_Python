#include "regression.hpp"

int main()
{
    NumericDataSet set("numbers_meta.txt");
    Encoder* encoder = NULL;
    
    set.addData("numbers.txt",encoder);
    set.shuffleData();

    auto train_test = set.TrainTestSplit(0.75);

    LogisticRegression regression(1,0.000001,0.000001,-1,5);
    
    regression.train(*train_test.first);
    regression.showParameters();

    auto true_pred = regression.true_pred(*train_test.second);
    auto train_pred = regression.true_pred(*train_test.first);
   
    std::cout<<"Train Accuracy: "<<100*regression.test_accuracy(train_pred)<<"\n";
    std::cout<<"Accuracy: "<<100*regression.test_accuracy(true_pred)<<"\n";
    regression.confusion_matrix(true_pred);
}   