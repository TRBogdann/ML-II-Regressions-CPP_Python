#include "numeric_data.hpp"
#include <fstream>
#include "math.hpp"
#include "utils.hpp"
#include <cstddef>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>


NumericRow::NumericRow(int size, double *values)
{

    if (values == NULL || size <= 0)
    {
        this->values = NULL;
        this->size = 0;
    }
    else
    {
        this->size = size;
        this->values = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->values[i] = values[i];
        }
    };
}

NumericRow::~NumericRow()
{
    if (this->values != NULL)
    {
        delete[] values;
        values = NULL;
    }
}
NumericRow::NumericRow(const NumericRow &row)
{
    this->size = row.size;
    if (row.values == NULL || row.size <= 0)
    {
        this->values = NULL;
        this->size = 0;
    }
    else
    {
        this->values = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->values[i] = row.values[i];
        }
    };
}

NumericRow& NumericRow::operator=(const NumericRow &row)
{
    if(this==&row)
        return *this;

    if(this->values!=NULL)
    {
        delete[] values;
    }

    this->size = row.size;
    if (row.values == NULL || row.size <= 0)
    {
        this->values = NULL;
        this->size = 0;
    }
    else
    {
        this->values = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->values[i] = row.values[i];
        }
    };
    return *this;
}

std::string NumericRow::toString() const
{
    std::string res = "";
    if (size > 0)
    {
        
        res += std::to_string(values[0]);

        for (int i = 1; i < size; i++)
        {
            res += "," + std::to_string(values[i]);  
        }
         
    }
    
    return res;
}

double& NumericRow::operator[](int index)
{
    if (index >= size)
    {
         throw DataException("Data Row Index out of bounds[Index:"+std::to_string(index)+",Size:"+std::to_string(size)+"]");
    }
    else
        return values[index];
}

int NumericRow::getSize(){return size;}

std::pair<Math::Vector,double> NumericRow::split(int index)
{
    Math::Vector vec(this->size-1);
    double y;
    int j=0;
    for(int i=0;i<size;i++)
    {
        if(i==index)
        {
            y = this->values[i];
        }
        else 
        {
            vec[j] = this->values[i];
            j++;
        }
    }
    return {vec,y};
}

NumericDataSet::NumericDataSet(int columns, ColumnMeta *meta)
{
    this->columns = columns;
    if (columns <= 0 || meta == NULL)
    {
        this->meta = NULL;
        this->columns = 0;
    }
    
    else
    {
        this->meta = new ColumnMeta[columns];
        
        for (int i = 0; i < columns; i++)
        {
            this->meta[i] = meta[i];
        }

    }
}

NumericDataSet::NumericDataSet(const NumericDataSet& set)
{
    this->columns = set.columns;
    if(columns<=0 || set.meta==NULL)
    {
        this->meta = NULL;
        this->columns = 0;
    }
    else
    {
        this->meta = new ColumnMeta[columns];
        for (int i = 0; i < columns; i++)
        {
            this->meta[i] = set.meta[i];
        }        
    }
    for(auto it=set.rows.begin();it!=set.rows.end();it++)
    {
        this->rows.push_back(*it);
    }
}

NumericDataSet& NumericDataSet::operator=(const NumericDataSet& set)
{
    if(this==&set)
        return *this;

    if(this->meta!=NULL)
    {
        delete[] this->meta;
    }

    if(!this->rows.empty())
    {
        this->rows.clear();
    }

    this->columns = set.columns;
    if(columns<=0 || set.meta==NULL)
    {
        this->meta = NULL;
        this->columns = 0;
    }
    else
    {
        this->meta = new ColumnMeta[columns];
        for (int i = 0; i < columns; i++)
        {
            this->meta[i] = set.meta[i];
        }        
    }
    for(auto it=set.rows.begin();it!=set.rows.end();it++)
    {
        this->rows.push_back(*it);
    }

    return *this;   
}

NumericDataSet::NumericDataSet(std::string metaFile)
{
    std::ifstream f(metaFile);
    std::string line;
    this->columns=0;
    if(!f.good())
        throw DataException("File "+ metaFile+" does not exist");

    while(std::getline(f,line))
    {
        this->columns++;
    } 

    if(this->columns==0)
    {
        throw DataException("Trying to read Meta from empty file");
    }

    f.clear();
    f.seekg(0);

    this->meta = new ColumnMeta[columns];
    int i=0;
    while(std::getline(f,line))
    {
        if(std::count(line.begin(),line.end(),',')!=2)
            throw DataException("Bad File format:"+metaFile+"\nLine:"+line);
        
        char* unformatted = new char[line.size()+1];
        
        strcpy(unformatted,line.c_str());
        
        char* label = strtok(unformatted,",");
        char* dataType = strtok(NULL,",");
        char* colType = strtok(NULL,"");
       
        this->meta[i].label = label;
        
        if(std::string(dataType)=="numeric")
        {
            this->meta[i].dataType = numericData;
        }
        else if (std::string(dataType)=="atribute") 
        {
            this->meta[i].dataType = atrib;
        }
        else 
            throw DataException("Bad File Format[Expected:numeric/atribute,Got:"+std::string(dataType)+"]");

        
        if(std::string(colType)=="input")
        {
            this->meta[i].type = inputCol;
        }
        else if (std::string(colType)=="output") 
        {
            this->meta[i].type = outputCol;
        }
        else 
            throw DataException("Bad File Format[Expected:input/output,Got:"+std::string(colType)+"]");
        
        
        delete[] unformatted;
        
        i++;
    } 

}

NumericDataSet::~NumericDataSet()
{
    if (meta != NULL)
    {
            delete[] meta;
            meta = NULL;
    }
}

NumericRow& NumericDataSet::operator[](int index)
{
    if(index>=rows.size())
        throw DataException("Data Set index out of bounds[Size:"+std::to_string(rows.size())+
    ",Index:"+std::to_string(index)+"]");

    return rows[index];
}

void NumericDataSet::addRow(NumericRow row)
{
    if(row.getSize()!=this->columns)
        throw DataException("Bad Row Size[Set:"+std::to_string(this->columns)+
    ",Row:"+std::to_string(row.getSize())+"]");

    this->rows.push_back(row);
}

void NumericDataSet::addRow(std::string line,Encoder& encoder)
{
    int count = std::count(line.begin(),line.end(),',')+1;
    if(count!=this->columns)
        throw DataException("Bad Row Size[Set:"+std::to_string(this->columns)+
    ",Line:"+std::to_string(count)+"]");

    double* values = new double[columns];
    int i=0;
    
    char* unformatted = new char[line.size()+1];
    strcpy(unformatted,line.c_str());
    char* token = strtok(unformatted,",");
   
    while(token!=NULL)
    {
        values[i] = encoder.codify(i, std::string(token));
        token = strtok(NULL,",");
        i++;
    }
     
    delete[] unformatted;
    
    this->rows.push_back(NumericRow(this->columns,values));
   
    delete[] values;

}

void NumericDataSet::addData(std::string filename,Encoder*& encoder)
{
    if(encoder==NULL)
    {
        std::vector<int> row_nums;
        for(int i=0;i<this->columns;i++)
        {
            if(this->meta[i].dataType==atrib)
                row_nums.push_back(i);
        }
        encoder = Encoder::genEncoder(this->columns,row_nums,filename);
    }

    std::ifstream f(filename);
    std::string line;
    
    if(!f.good())
        throw DataException("File "+filename+" does not exist");

    while(std::getline(f,line))
    {
        trim(line);
        this->addRow(line,*encoder);
    }

}

void NumericDataSet::shuffleData()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rows.begin(),rows.end(),g);
}

void NumericDataSet::show() const
{
    if(this->columns==0 || this->meta==nullptr)
        return;

    std::cout<<this->meta[0].label;

    for(int i=1;i<this->columns;i++)
        std::cout<<","<<this->meta[i].label;

    std::cout<<"\n";

    for(auto it=this->rows.begin();it!=this->rows.end();it++)
    {
        std::cout<<(*it).toString()<<"\n";
    }
}

void NumericDataSet::head() const
{   
    int end = std::min(5,(int)rows.size());
    auto it = rows.begin();
    for(int i=0;i<end;i++)
    {
        std::cout<<(*it).toString()<<"\n";
        it++;
    }
}

void NumericDataSet::correlation_matrix()const
{

}


std::pair<NumericDataSet*,NumericDataSet*> NumericDataSet::TrainTestSplit(double train_sample_percentage)
{
    NumericDataSet *train=new NumericDataSet(this->columns,this->meta);
    NumericDataSet *test=new NumericDataSet(this->columns,this->meta);
    

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    for(auto it = this->rows.begin();it!=this->rows.end();it++)
    {
        double p = distribution(generator);
        if(p<train_sample_percentage)
        {
            train->addRow(*it);
        }
        else 
            test->addRow(*it);
    }

    return {train,test};
}

int NumericDataSet::getOutputIndex()
{
    for(int i=0;i<columns;i++)
    {
        if(this->meta[i].type==outputCol)
            return i;
    }
    return columns-1;
};

int NumericDataSet::getSize()
{
    return rows.size();
}
