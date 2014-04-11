#include "string_converter.h"
#include <sstream>
#include <typeinfo>
std::string integerToStdString(long long int i){
    std::stringstream s;
    s << i;
    std::string out;
    s >> out;
    return out;
}
std::string floatToStdString(long double d){
    std::stringstream s;
    s << d;
    std::string out;
    s >> out;
    return out;
}
int stdStringToInt(std::string &s){

}
double stdStringToDouble(std::string &s){
}
bool stdStringToBool(std::string &s){
}
char stdStringToChar(std::string &s){

}
