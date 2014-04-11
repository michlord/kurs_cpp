#include "newstring.h"
#include "string_converter.h"
namespace obliczenia{

NewString::NewString(){}
NewString::NewString(const NewString &other):std::string(other){}
NewString::NewString(const char *other):std::string(other){}
NewString::NewString(const std::string &other):std::string(other){}
NewString &NewString::operator=(const NewString &other){
    std::string::operator=(other);
    return *this;
}
NewString::~NewString(){}

NewString::operator int(){
    return convertFromStdString<int>(*this);
}
NewString::operator double(){
    return convertFromStdString<double>(*this);
}
NewString::operator bool(){
    return convertFromStdString<bool>(*this);
}
NewString::operator char(){
    return convertFromStdString<char>(*this);
}
NewString::NewString(int number){
    std::string::operator=(convertToStdString(number));
}
NewString::NewString(double number){
    std::string::operator=(convertToStdString(number));
}
NewString::NewString(bool number){
    std::string::operator=(convertToStdString(number));
}
NewString::NewString(char character){
    std::string::operator=(convertToStdString(character));
}

NewString& NewString::operator+=(const NewString &rhs){
    std::string::operator+=(rhs);
    return *this;
}
NewString operator+(const NewString &lhs, const NewString &rhs){
    NewString tmp = lhs;
    tmp += rhs;
    return tmp;
}

bool operator==(const NewString &lhs, const NewString &rhs){
    return operator==(std::string(lhs),std::string(rhs));
}
bool operator<(const NewString &lhs, const NewString &rhs){
    return operator<(std::string(lhs),std::string(rhs));
}
bool operator<=(const NewString &lhs, const NewString &rhs){
    return operator<=(std::string(lhs),std::string(rhs));
}
bool operator>(const NewString &lhs, const NewString &rhs){
    return operator>(std::string(lhs),std::string(rhs));
}
bool operator>=(const NewString &lhs, const NewString &rhs){
    return operator>=(std::string(lhs),std::string(rhs));
}


NewString& NewString::operator+=(int rhs){
    return operator+=(NewString(rhs));
}
NewString operator+(const NewString &lhs, int rhs){
    return operator+(lhs,NewString(rhs));
}
NewString operator+(int lhs, const NewString &rhs){
    return operator+(NewString(lhs),rhs);
}
NewString& NewString::operator+=(double rhs){
    return operator+=(NewString(rhs));
}
NewString operator+(const NewString &lhs, double rhs){
    return operator+(lhs,NewString(rhs));
}
NewString operator+(double lhs, const NewString &rhs){
    return operator+(NewString(lhs),rhs);
}
NewString& NewString::operator+=(bool rhs){
    return operator+=(NewString(rhs));
}
NewString operator+(const NewString &lhs, bool rhs){
    return operator+(lhs,NewString(rhs));
}
NewString operator+(bool lhs, const NewString &rhs){
    return operator+(NewString(lhs),rhs);
}
NewString& NewString::operator+=(char rhs){
    return operator+=(NewString(rhs));
}
NewString operator+(const NewString &lhs, char rhs){
    return operator+(lhs,NewString(rhs));
}
NewString operator+(char lhs, const NewString &rhs){
    return operator+(NewString(lhs),rhs);
}

std::istream & operator>> (std::istream &we, NewString &x){
    std::string str;
    we >> str;
    x += str;
    return we;
}
std::ostream & operator<< (std::ostream &wy, const NewString &x){
    wy << x.c_str();
    return wy;
}

}//namespace obliczenia
