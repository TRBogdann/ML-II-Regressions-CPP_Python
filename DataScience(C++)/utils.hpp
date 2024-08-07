#include <exception>
#include <string>

void trim(std::string &str);
class DataException:public std::exception
{
    public:
    DataException(std::string message);
    virtual const char* what() const noexcept override;
    private:
    std::string message;
};