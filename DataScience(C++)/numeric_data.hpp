#include <string>
#include <vector>
#include "encoder.hpp"
#include "math.hpp"

enum columnType { inputCol, outputCol };
enum columnDataType { numericData, atrib };

struct ColumnMeta
{
    std::string label;
    columnType type;
    columnDataType dataType;
};

class NumericRow
{
    public:
    NumericRow(int size, double *values);
    ~NumericRow();
    NumericRow(const NumericRow &row);
    NumericRow& operator=(const NumericRow &row);
    std::pair<Math::Vector,double> split(int index);
    std::string toString() const;
    double& operator[](int index);
    int getSize();

    private:
    int size;
    double *values;
};

class NumericDataSet
{
    public:

    NumericDataSet(int columns, ColumnMeta *meta);
    NumericDataSet(std::string metaFile);
    NumericDataSet(const NumericDataSet& set);
    NumericDataSet& operator=(const NumericDataSet& set);
    ~NumericDataSet();

    
    NumericRow& operator[](int index); 
    int getOutputIndex();
    int getSize();
    void addRow(NumericRow row);
    void addRow(std::string line,Encoder& encoder);
    void addData(std::string filename,Encoder*& encoder);
    void shuffleData();
    void show() const;
    void head() const;
    void correlation_matrix()const;
    std::pair<NumericDataSet*,NumericDataSet*> TrainTestSplit(double train_sample_percentage);

    private:
    ColumnMeta *meta;
    std::vector<NumericRow> rows;
    int columns;
};

