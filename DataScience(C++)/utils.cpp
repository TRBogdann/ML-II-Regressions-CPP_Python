#include "utils.hpp"
#include <exception>

void trim(std::string &s)
{
    if (isspace(s[s.length() - 1]))
        s.pop_back();
}

DataException::DataException(std::string message):std::exception(),message(message)
{

}

const char* DataException::what() const noexcept
{
        return message.c_str();
}