#include "regression.hpp"
#include <cstddef>

int main()
{
    NumericDataSet set("adv_meta.txt");
    Encoder* encoder = NULL;
 
    set.addData("advertising.csv",encoder);
    set.shuffleData();

    auto train_test = set.TrainTestSplit(0.75);
    LinearRegression regression(3,0.00001,0.00001,-1,50);
    
    regression.train(*train_test.first);
    regression.showParameters();

    auto true_pred = regression.true_pred(*train_test.second);

    std::cout<<"Score: "<<100*regression.r2_score(true_pred)<<"\n";    
    std::cout<<"Mean Absolute Error: "<<regression.mean_absolute(true_pred)<<"\n";
    std::cout<<"Mean Squared Error: "<<regression.mean_squared_error(true_pred)<<"\n";
    std::cout<<"Root Mean Squared Error: "<<regression.root_mean_squared_error(true_pred)<<"\n";
}   