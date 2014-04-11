#ifndef STRUKTURY_H_
#define STRUKTURY_H_

#include "datagodz.hpp"

class Lista{


public:

    class Wezel{
    public:
        Wezel(const Para &wartosc_);
        Para wartosc;
        Wezel *nastepny;
    };
    Lista();
    Lista(const Lista &inna_);
    ~Lista();
    Lista& operator=(const Lista &inna_);
    friend std::istream& operator>>(std::istream &we, Lista &w);
    friend std::ostream& operator<<(std::ostream &wy, const Lista &w);

    void wstaw(const Para& wartosc_,int index_);
    Para usun(int index_);
    Para& operator[](int i);
    const Para& operator[](int i) const;
    int rozmiar() const;
    void wyczysc();
protected:
    Wezel *glowa;
    void init(const Para& p_);
    void kopiujInnaListe(const Lista &inna_);
};


//w glowie listy jest przechowywana najpozniejsza data
//daje to szybkie zdejmowanie, a zeby wstawic nowy element
//i tak trzeba przeszukac liste...
class Kolejka : private Lista{

public:
    Kolejka();
    Kolejka(const Kolejka &inna_);
    ~Kolejka();
    Kolejka& operator=(const Kolejka &inna_);
    friend std::istream& operator>>(std::istream &we, Kolejka &w);
    friend std::ostream& operator<<(std::ostream &wy, const Kolejka &w);
    using Lista::wyczysc;
    using Lista::rozmiar;
    void wstaw(const Para& wartosc_);
    Para zdejmij();
};

#endif
