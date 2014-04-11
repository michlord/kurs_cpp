#ifndef MACIERZ_EXCEPTIONS_H_
#define MACIERZ_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

class RozmiarNiePasujeException : public std::out_of_range{
    public:
    RozmiarNiePasujeException(std::string what):std::out_of_range(what){}
};


#endif
