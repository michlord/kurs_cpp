#ifndef WIELOMIAN_H_
#define WIELOMIAN_H_

#include <iostream>
#include <string>

class Wspolczynnik{
private:
    double &wartosc;
    bool nie_moze_byc_zero;
public:
    Wspolczynnik(double &wartosc_, bool nie_moze_byc_zero_)
         :wartosc(wartosc_), nie_moze_byc_zero(nie_moze_byc_zero_){}
    operator double() const{
        return wartosc;
    }
    double operator=(double wartosc_){
        if(nie_moze_byc_zero == true && wartosc_ == 0)
            throw std::string("Podany wspolczynnik nie moze byc zero");
        wartosc = wartosc_;
		return wartosc;
    }
};

class Wielomian{
private:
    int n;
    double *a;
public:
    Wielomian(int st=0, double wsp=1.0);
    Wielomian(int st, double *wsp);
    Wielomian(const Wielomian &w);
    Wielomian& operator=(const Wielomian &w);
    ~Wielomian();
    friend std::istream& operator>>(std::istream &we, Wielomian &w);
    friend std::ostream& operator<<(std::ostream &wy, const Wielomian &w);
    int stopien();

    Wspolczynnik operator[](int i);
    const Wspolczynnik operator[](int i) const;

    //int& operator[](int i);
    //int operator[](int i) const;

    friend Wielomian operator+(const Wielomian &w1, const Wielomian &w2);
    friend Wielomian operator-(const Wielomian &w1, const Wielomian &w2);
    friend Wielomian operator*(const Wielomian &w1, double k_);
    friend Wielomian operator*(const Wielomian &w1, const Wielomian &w2);
    double operator()(double x)const;

    Wielomian& operator+=(const Wielomian &w1);
    Wielomian& operator-=(const Wielomian &w1);
    Wielomian& operator*=(double k_);
    Wielomian& operator*=(const Wielomian &w1);

    bool czyZero() const;

};

#endif
