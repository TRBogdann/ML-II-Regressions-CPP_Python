#include "regression.hpp"


int main()
{
    NumericDataSet set("car_meta.txt");
    Encoder* encoder = new Encoder("car_encodings.txt");
 
    set.addData("car_evaluation.csv",encoder);
    set.shuffleData();

    auto train_test = set.TrainTestSplit(0.75);
    LinearRegression regression(6,0.00001,0.00001,500,100);
    
    regression.train(*train_test.first);
    regression.showParameters();

   auto true_pred = regression.true_pred(*train_test.second);

    std::cout<<"Score: "<<100*regression.r2_score(true_pred)<<"\n";    
    std::cout<<"Mean Absolute Error: "<<regression.mean_absolute(true_pred)<<"\n";
    std::cout<<"Mean Squared Error: "<<regression.mean_squared_error(true_pred)<<"\n";
    std::cout<<"Root Mean Squared Error: "<<regression.root_mean_squared_error(true_pred)<<"\n";
}   