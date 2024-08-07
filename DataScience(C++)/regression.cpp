
#include "regression.hpp"
#include "math.hpp"
#include <cmath>
#include <random>

Regression::Regression(int nrOfWeights,int nrOfBiases,double dx,double learning_rate,int max_iterations,int batchSize):
weights(nrOfWeights),biases(nrOfBiases),dx(dx),learning_rate(learning_rate),max_iterations(max_iterations),batchSize(batchSize)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-0.01,+0.01);
    for(int i=0;i<weights.getSize();i++)
    {
        weights[i]+=distribution(generator);
    }
    for(int i=0;i<biases.getSize();i++)
    {
        biases[i]+=distribution(generator);
    }
}

Regression::Regression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations,int batchSize):
weights(w),biases(b),learning_rate(learning_rate),max_iterations(max_iterations),batchSize(batchSize),dx(dx)
{

}

void Regression::ajust(int batchFist,int batchEnd,NumericDataSet& set)
{
    int iter = 0;
    double gradDx = 1000;
    double current_cost = MAXFLOAT;
    do
    {
        prev_cost = current_cost;
        current_cost = cost(set,weights,biases);
        auto it = gradient(set,weights,biases);

        weights-=it.first*learning_rate;
        biases-=it.second*learning_rate;
       // std::cout<<current_cost<<"\n";
       // std::cout<<it.first.ToString()<<it.second.ToString()<<"\n";

        double mag1 = it.first.getMagnitude();
        double mag2 = it.second.getMagnitude();
        gradDx = std::sqrt(mag1*mag1+mag2*mag2);
        iter++;
    }
    while(iter!=max_iterations && std::abs(current_cost-prev_cost)>dx && gradDx>dx);

}

void Regression::train(NumericDataSet& set)
{
    int batchBegin=0;
    int batchEnd;
    int step = std::max(1,batchSize);
    if(batchSize<=0)
    {
        batchEnd=set.getSize();
    }
    else
        batchEnd = batchBegin+batchSize;

    while(batchEnd<=set.getSize())
    {
        batchEnd=std::min(batchEnd,set.getSize());
        ajust(batchBegin,batchEnd,set);
        batchBegin=batchEnd;
        batchEnd+=step;
    }
}

void Regression::showParameters()
{
    std::cout<<weights.ToString()<<"\n"<<biases.ToString()<<"\n";
}

LinearRegression::LinearRegression(int nrOfWeights,double dx,double learning_rate,int max_iterations,int batchSize):
Regression(nrOfWeights,1,dx,learning_rate,max_iterations,batchSize)
{

}

LinearRegression::LinearRegression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations,int batchSize):
Regression(w,b,dx,learning_rate,max_iterations,batchSize)
{

}

void Regression::confusion_matrix(std::vector<std::pair<double,double>> vals)
{
    float tp1=0;
    float med1=0;
    float tp2=0;
    float med2=0;

    for(auto it=vals.begin();it!=vals.end();it++)
    {
        if(it->first==std::round(it->second) && it->first==0)
            tp1++;
        else if(it->first==std::round(it->second) && it->first==1)
            tp2++;
        else if(it->first!=std::round(it->second) && it->first==1) 
            med1++;
        else med2++;     
    }
    std::cout<<"["<<tp1<<","<<med1<<"]"<<'\n';
    std::cout<<"["<<med2<<","<<tp2<<"]"<<'\n';
}

double LinearRegression::function(Math::Vector w,Math::Vector b,Math::Vector x)
{
    return w*x+b[0];
}

double LinearRegression::cost(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst,int batchLast)
{
    int outputIndex = set.getOutputIndex();

    if(batchLast<batchFirst)
        batchLast = set.getSize();

    int m = (batchLast-batchFirst)*2;
    double sum = 0;

    for(int i=batchFirst;i<batchLast;i++)
    {
        auto vec = set[i].split(outputIndex);
        double diff = function(w,b,vec.first)-set[i][outputIndex];
        sum+=diff*diff;
    }

    return sum/m;
}


std::pair<Math::Vector,Math::Vector> LinearRegression::gradient(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst,int batchLast)
{
    if(batchLast<batchFirst)
        batchLast = set.getSize();

    int outputIndex = set.getOutputIndex();
    std::vector<double> diffs(batchLast-batchFirst);

    for(int i=0;i<batchLast-batchFirst;i++)
    {
        auto vec = set[i+batchFirst].split(outputIndex);
        diffs[i]=function(w,b,vec.first)-set[i+batchFirst][outputIndex];
    }

    Math::Vector v1(w.getSize());
    for(int i=0;i<w.getSize();i++)
    {
        for(int j=0;j<diffs.size();j++)
        {
            auto vec = set[j+batchFirst].split(outputIndex);
            v1[i]+=diffs[j]*vec.first[i];
        }
    }
    Math::Vector v2(1);
    for(int j=0;j<diffs.size();j++)
    {
        v2[0]+=diffs[j];
    }

    return {v1/(batchLast-batchFirst),v2/(batchLast-batchFirst)};
}

double Regression::predict(NumericRow r,int outputIndex)
{
    auto it = r.split(outputIndex);
    return function(weights,biases,it.first);
}

std::vector<std::pair<double,double>> Regression::true_pred(NumericDataSet& set)
{
    std::vector<std::pair<double,double>> resultVector;

    int outputIndex = set.getOutputIndex();
    for(int i=0;i<set.getSize();i++)
    {
        auto it = set[i].split(outputIndex);
        resultVector.push_back({set[i][outputIndex],function(weights,biases,it.first)});
    }

    return  resultVector;
}

double Regression::r2_score(std::vector<std::pair<double,double>> vals)
{
    double mean = 0;
    double s1 = 0;
    double s2 = 0;
    for(auto it = vals.begin();it!=vals.end();it++)
    {
        mean+=it->first;
    }
    mean = mean/vals.size();
    for(auto it = vals.begin();it!=vals.end();it++)
    {
        s1+=(it->first-it->second)*(it->first-it->second);
        s2+=(it->first-mean)*(it->first-mean);
    }

    return 1-s1/s2;
}

double Regression::mean_absolute(std::vector<std::pair<double,double>> vals)
{
    double mean = 0;
    for(auto it = vals.begin();it!=vals.end();it++)
    {
        mean+=std::abs(it->first-it->second);
    }

    return mean/vals.size();
}

double Regression::mean_squared_error(std::vector<std::pair<double,double>> vals)
{
    double mean = 0;
    for(auto it = vals.begin();it!=vals.end();it++)
    {
        mean+=(it->first-it->second)*(it->first-it->second);
    }
    
    return mean/vals.size();
}

double Regression::root_mean_squared_error(std::vector<std::pair<double,double>> vals)
{
    return std::sqrt(mean_squared_error(vals));
}

double Regression::test_accuracy(std::vector<std::pair<double,double>> vals)
{
    double predicted=0;
    for(auto it=vals.begin();it!=vals.end();it++)
    {
        if(it->first==std::round(it->second))
        predicted++;
    }

    return predicted/vals.size();
}


LogisticRegression::LogisticRegression(int nrOfWeights,double dx,double learning_rate,int max_iterations,int batchSize):
Regression(nrOfWeights,1,dx,learning_rate,max_iterations,batchSize)
{

}

LogisticRegression::LogisticRegression(Math::Vector w,Math::Vector b,double dx,double learning_rate,int max_iterations,int batchSize):
Regression(w,b,dx,learning_rate,max_iterations,batchSize)
{

}

double LogisticRegression::function(Math::Vector w,Math::Vector b,Math::Vector x)
{
    double alpha = -(w*x+b[0]);
    return 1.0f/(1.0f+std::exp(alpha));
}

double LogisticRegression::cost(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst,int batchLast)
{
    int outputIndex = set.getOutputIndex();

    if(batchLast<batchFirst)
        batchLast = set.getSize();

    int m = (batchLast-batchFirst);
    double sum = 0;

    for(int i=batchFirst;i<batchLast;i++)
    {
        auto vec = set[i].split(outputIndex);
        double y = set[i][outputIndex];
        double diff;
        if(y==0)
            diff = -std::log(1-function(w,b,vec.first)+0.00001);
        else
            diff = -std::log(function(w,b,vec.first)+0.00001);
        sum+=diff;
    }

    return sum/m;
}

std::pair<Math::Vector,Math::Vector> LogisticRegression::gradient(NumericDataSet set,Math::Vector w,Math::Vector b,int batchFirst,int batchLast)
{
    if(batchLast<batchFirst)
        batchLast = set.getSize();

    int outputIndex = set.getOutputIndex();
    int m = batchLast-batchFirst;
    Math::Vector v1(w.getSize());
    Math::Vector v2(1);
    for(int i=0;i<w.getSize();i++)
    {
        for(int j=batchFirst;j<batchLast;j++)
        {
            auto vec = set[j].split(outputIndex);
            double y=vec.second;
            double y_pred=function(w,b,vec.first);
            v1[i]-=y*(1-y_pred)*vec.first[i]-(1-y)*y_pred*vec.first[i];
            v2[0]-=y*(1-y_pred)-(1-y)*y_pred;
        }
    }
    

    return {v1/m,v2/m};
}