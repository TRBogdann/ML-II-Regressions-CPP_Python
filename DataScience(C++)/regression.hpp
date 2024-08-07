
#include "math.hpp"
#include "numeric_data.hpp"
#include <cmath>

class Regression
{
    public:
    virtual double function(Math::Vector w,Math::Vector b,Math::Vector x)=0;
    virtual double cost(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1)=0;
    virtual std::pair<Math::Vector,Math::Vector> gradient(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1)=0;
    
    Regression(int nrOfWeights,int nrOfBiases,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);
    Regression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);
    
    void train(NumericDataSet& set);
    double predict(NumericRow r,int outputIndex);
    std::vector<std::pair<double,double>> true_pred(NumericDataSet& set);

    void showParameters();

    static void confusion_matrix(std::vector<std::pair<double,double>> vals);
    static double test_accuracy(std::vector<std::pair<double,double>> vals);
    static double r2_score(std::vector<std::pair<double,double>> vals);
    static double mean_absolute(std::vector<std::pair<double,double>> vals);
    static double mean_squared_error(std::vector<std::pair<double,double>> vals);
    static double root_mean_squared_error(std::vector<std::pair<double,double>> vals);

    protected:
    void ajust(int batchFist,int batchEnd,NumericDataSet& set);
    Math::Vector weights;
    Math::Vector biases;
    double learning_rate;
    double dx;
    int max_iterations;
    int batchSize;
    double prev_cost = MAXFLOAT;
};

class LinearRegression:public Regression
{
    public:
    LinearRegression(int nrOfWeights,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);
    LinearRegression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);

    virtual double function(Math::Vector w,Math::Vector b,Math::Vector x) override;
    virtual double cost(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1) override;
    virtual std::pair<Math::Vector,Math::Vector> gradient(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1) override;
    
    private:
};

class LogisticRegression:public Regression
{
    public:
    LogisticRegression(int nrOfWeights,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);
    LogisticRegression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations=-1,int batchSize=-1);

    virtual double function(Math::Vector w,Math::Vector b,Math::Vector x) override;
    virtual double cost(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1) override;
    virtual std::pair<Math::Vector,Math::Vector> gradient(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst=0,int batchLast=-1) override;
    
    private:
};