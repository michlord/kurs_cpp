#ifndef STRING_CONVERTER_H_
#define STRING_CONVERTER_H_

#include <sstream>
#include <typeinfo>
template<typename T>
std::string convertToStdString(T val){
    std::stringstream s;
    s << val;
    std::string out;
    s >> out;
    return out;
}
template<typename T>
T convertFromStdString(std::string str){
    std::stringstream s;
    s << str;
    T out;
    s >> out;
    if(s.good()==false)
        throw std::bad_cast();
    return out;
}

#endif
