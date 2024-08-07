#include "encoder.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <exception>
#include <fstream>
#include <map>
#include <unordered_set>
#include <string.h>
#include <string>
#include "utils.hpp"
#include <iostream>
#include <utility>

Encoding_List::Encoding_List(int size,std::string* list)
{
    this->size = std::max(size,0);
    if(size>0)
    {
        this->encoding = new std::string[size];
        for(int i=0;i<size;i++)
        {
            this->encoding[i] = list[i];
        }
    }
    else
        this->encoding = nullptr;
}

Encoding_List::Encoding_List()
{
    this->size = 0;
    this->encoding = nullptr;
}

Encoding_List::~Encoding_List()
{
    if(this->size>0 && this->encoding!=nullptr)
        delete [] this->encoding;
}

Encoding_List* Encoding_List::parse(std::string str)
{
    Encoding_List* list = new Encoding_List();
    int size = std::count(str.begin(),str.end(),',')+1;
    list->size = size;
    list->encoding = new std::string[size];
    char* unformatted = new char[str.size()+1];
    strcpy(unformatted,str.c_str());
    char* token = strtok(unformatted,",");
    int i=0;
    while(token!=NULL)
    {
        list->encoding[i] = token;
        token = strtok(NULL,",");
        i++;
    }
    delete[] unformatted;
    return list;
}

std::string Encoding_List::toString()
{
    std::string res = "[";
    if(size>0)
    {
        res+=encoding[0];
        for(int i=1;i<size;i++)
        {
            res+=","+encoding[i];
        }
    }
    res+="]";
    return res;
}

int Encoding_List::getSize()
{
    return this->size;
}

Encoder::Encoder(std::string filename)
{
    std::ifstream f(filename);
    if(!f.good())
        throw DataException("Could not open file");
    else
    {
        std::string line;
        int numberOfLines = 0;
        while(std::getline(f,line))
        {
            numberOfLines++;
        }
        if(numberOfLines==0)
        {
            this->nrOfValues=0;
            this->list=NULL;
            return;
        }

        this->nrOfValues = numberOfLines;
        this->list = new Encoding_List*[this->nrOfValues]();
        f.clear();
        f.seekg(0);
        int i=0;
        while(getline(f,line))
        {
            if(line.size()!=0)
            {
                trim(line);
                this->list[i] = Encoding_List::parse(line);
            }
            i++;
        }
    }
}

Encoder::Encoder()
{
    this->nrOfValues = 0;
    this->list = NULL;
}

Encoder::~Encoder()
{
    if(this->nrOfValues>0 && this->list!=NULL)
    {
        for(int i=0;i<nrOfValues;i++)
        {
            if(this->list[i]!=NULL)
                delete this->list[i];
        }
        delete[] list; 
    }
}

Encoder::Encoder(int size,Encoding_List** list)
{
    this->nrOfValues = std::max(size,0);
    if(size<=0)
        this->list = NULL;
    else
    {
        this->list = new Encoding_List*[size];
        for(int i=0;i<size;i++)
        {
            if(list[i]==NULL)
                this->list[i] = NULL;
            else
                this->list[i] = new Encoding_List(list[i]->size,list[i]->encoding);
        }
    };
}

Encoder* Encoder::genEncoder(int size,std::vector<int> row_nums,std::string filename)
{
    if(size<=0)
        return new Encoder();

    Encoder* encoder = new Encoder();
    std::map<int,std::unordered_set<std::string>> values;
    std::ifstream f(filename);

    if(!f.good())
        throw DataException("Could not open file");
    
    std::string line;
    
    while(std::getline(f,line))
    {
        int i=0;
        trim(line);
        char* unformatted = new char[line.size()+1];
        strcpy(unformatted,line.c_str());
        char* token = strtok(unformatted,",");
        while(token!=NULL)
        {
            if(std::count(row_nums.begin(),row_nums.end(),i)!=0)
            {
                if(values.find(i)==values.end())
                {
                    values.insert(std::pair<int,std::unordered_set<std::string>>(i,std::unordered_set<std::string>()));
                }
                values.at(i).insert(token);
            }
            token = strtok(NULL,",");
            i++;
        }
    }

    encoder->nrOfValues=size;
    encoder->list = new Encoding_List*[size]();
    for(int i=0;i<size;i++)
    {
        if(std::count(row_nums.begin(),row_nums.end(),i)!=0)
        {
            auto it = values.at(i).begin();
            std::string res=*it;
            it++;
            while(it!=values.at(i).end())
            {
                res = *it+","+res;
                it++;
            }   
            encoder->list[i] = Encoding_List::parse(res);
        }
    }

    return encoder;
}

float Encoder::codify(int index,std::string value)
{
    if(index>=this->nrOfValues)
    {
        throw  DataException("Index out of bounds [Size:"+std::to_string(this->nrOfValues)+",Index:"+
        std::to_string(index)+"]");
    }
    if(list[index]==nullptr)
    {
        try
        {
            float codif = std::stof(value);
            return codif;
        }
        catch(std::exception e){
            throw DataException("Value is not numeric ["+value+"]");
        }
    }
    for(int i=0;i<list[index]->size;i++)
    {
        if(list[index]->encoding[i]==value)
            return i;
    }
    std::cout<<"Warning a value was not found[Index:"+std::to_string(index)+","+"Value:"+value+"]"<<"\n";
    return 0.0f;
}

std::string Encoder::ToString()
{
    std::string res="";
    for(int i=0;i<this->nrOfValues;i++)
    {
        if(this->list[i]==NULL)
            res+="[NULL]\n";
        else 
            res+=list[i]->toString()+"\n";
    }
    return  res;
}