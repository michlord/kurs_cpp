#ifndef NEWSTRING_H_
#define NEWSTRING_H_

#include <string>

namespace obliczenia{

class NewString : private std::string{
public:
    NewString();
    NewString(const NewString &other);
    NewString(const char *other);
    NewString(const std::string &other);
    NewString &operator=(const NewString &other);
    virtual ~NewString();

    operator int();
    operator double();
    operator bool();
    operator char();
    NewString(int number);
    NewString(double number);
    NewString(bool number);
    NewString(char character);

    NewString& operator+=(const NewString &rhs);
    friend NewString operator+(const NewString &lhs, const NewString &rhs);

    /*Normalnie bym tego nie definiowal*/
    NewString& operator+=(int rhs);
    friend NewString operator+(const NewString &lhs, int rhs);
    friend NewString operator+(int lhs, const NewString &rhs);
    NewString& operator+=(double rhs);
    friend NewString operator+(const NewString &lhs, double rhs);
    friend NewString operator+(double lhs, const NewString &rhs);
    NewString& operator+=(bool rhs);
    friend NewString operator+(const NewString &lhs, bool rhs);
    friend NewString operator+(bool lhs, const NewString &rhs);
    NewString& operator+=(char rhs);
    friend NewString operator+(const NewString &lhs, char rhs);
    friend NewString operator+(char lhs, const NewString &rhs);
    /*---------------------------------*/

    friend bool operator==(const NewString &lhs, const NewString &rhs);
    friend bool operator<(const NewString &lhs, const NewString &rhs);
    friend bool operator<=(const NewString &lhs, const NewString &rhs);
    friend bool operator>(const NewString &lhs, const NewString &rhs);
    friend bool operator>=(const NewString &lhs, const NewString &rhs);

    using std::string::operator[];
    using std::string::append;
    using std::string::length;
    using std::string::insert;
    using std::string::erase;
    using std::string::substr;
    using std::string::c_str;

    friend std::istream & operator>> (std::istream &we, NewString &x);
    friend std::ostream & operator<< (std::ostream &wy, const NewString &x);

};

}
#endif
