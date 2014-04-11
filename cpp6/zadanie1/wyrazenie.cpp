#include "wyrazenie.h"
#include <string>
#include <algorithm>
#include <cmath>



Liczba::Liczba(int wartosc_):
    wartosc(wartosc_){
}
double Liczba::oblicz() const{
    return wartosc;
}
std::string Liczba::opis() const{
    return std::to_string(wartosc);
}

Zmienna::zbior Zmienna::zmienne;

Zmienna::Zmienna(const char *nazwa_):
    nazwa(nazwa_){
}
double Zmienna::oblicz() const{
    double wartosc = pobierzWartoscZmiennej(nazwa.c_str());
    return wartosc;
}
std::string Zmienna::opis() const{
    return nazwa;
}

Zmienna::zbior::iterator Zmienna::pobierzIteratorZmiennej(const char *nazwa_){
    return std::find_if(zmienne.begin(),zmienne.end(),
                        [nazwa_](std::pair<std::string,double> p){
                        return p.first == nazwa_;});
}

bool Zmienna::dodajZmienna(const char *nazwa_, double wartosc_){
    zbior::iterator it = pobierzIteratorZmiennej(nazwa_);
    if(it != zmienne.end())
        return false;
    zmienne.push_back(std::make_pair(std::string(nazwa_),wartosc_));
    return true;
}
bool Zmienna::usunZmienna(const char *nazwa_){
    zbior::iterator it = pobierzIteratorZmiennej(nazwa_);
    if(it == zmienne.end())
        return false;
    std::iter_swap(it,zmienne.end()-1);
    zmienne.pop_back();
    return true;
}
double Zmienna::pobierzWartoscZmiennej(const char *nazwa_){
    zbior::iterator it = pobierzIteratorZmiennej(nazwa_);
    if(it == zmienne.end())
        return NAN;
    return (*it).second;
}
