#ifndef MACIERZ_H_
#define MACIERZ_H_

#include "macierz_exceptions.h"
#include <iostream>

// Ciekawostka:
// Exception specifications are deprecated in C++11 - do not write
// exception specifications unless it is to specify that your function
// is guaranteed not to throw an exception.
// http://en.wikipedia.org/wiki/C++11#Features_removed_or_deprecated



class Macierz{
public:
    typedef double scalar_t;

    friend Macierz operator+(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException);
    friend Macierz operator-(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException);
    friend Macierz operator*(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException);
    friend Macierz operator*(const Macierz &x, scalar_t skalar);
    friend Macierz operator*(scalar_t skalar, const Macierz &x);

    Macierz &operator+=(const Macierz &y) throw (RozmiarNiePasujeException);
    Macierz &operator-=(const Macierz &y) throw (RozmiarNiePasujeException);
    Macierz &operator*=(const Macierz &y) throw (RozmiarNiePasujeException);
    Macierz &operator*=(scalar_t skalar);

    Macierz transponowana();

    friend std::istream &operator>>(std::istream &we, Macierz &x) throw (RozmiarNiePasujeException);
    friend std::ostream &operator<<(std::ostream &wy, const Macierz &x);

    Macierz();
    Macierz(int kolumny_,int wiersze_);
    Macierz(const Macierz &inna_);
    Macierz &operator=(const Macierz &inna_);
    virtual ~Macierz();

private:
    int kolumny;
    int wiersze;
    scalar_t *tb;
};

#endif
