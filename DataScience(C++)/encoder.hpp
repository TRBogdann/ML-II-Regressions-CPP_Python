
#include <string>
#include <vector>

class Encoding_List
{
    public:
    Encoding_List(int size,std::string* list);
    ~Encoding_List();
    static Encoding_List* parse(std::string str);
    std::string toString();
    int getSize();
    private:
    Encoding_List();
    int size;
    std::string* encoding;
    friend class Encoder;
};

class Encoder
{
    public:

    Encoder(std::string filename);
    Encoder(int size,Encoding_List** list);
    ~Encoder();
    static Encoder* genEncoder(int size,std::vector<int> row_nums,std::string filename);
    float codify(int index,std::string value);
    std::string ToString();
    private:
    Encoder();
    Encoding_List** list;
    int nrOfValues;
};
