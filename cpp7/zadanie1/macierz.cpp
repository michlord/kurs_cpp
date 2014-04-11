#include "macierz.h"
#include <algorithm>

Macierz::Macierz(){
    kolumny = 0;
    wiersze = 0;
    tb = nullptr;
}
Macierz::Macierz(int kolumny_,int wiersze_){
    kolumny = kolumny_;
    wiersze = wiersze_;
    int calkowity_rozmiar = kolumny_ * wiersze_;
    tb = new scalar_t[calkowity_rozmiar];
    std::fill(tb,tb+calkowity_rozmiar,0);
}
Macierz::Macierz(const Macierz &inna_){
    kolumny = inna_.kolumny;
    wiersze = inna_.wiersze;
    int calkowity_rozmiar = kolumny * wiersze;
    tb = new scalar_t[calkowity_rozmiar];
    std::copy(inna_.tb,inna_.tb+calkowity_rozmiar,tb);
}
Macierz &Macierz::operator=(const Macierz &inna_){
    if(tb != nullptr)
        delete [] tb;
    kolumny = inna_.kolumny;
    wiersze = inna_.wiersze;
    int calkowity_rozmiar = kolumny * wiersze;
    tb = new scalar_t[calkowity_rozmiar];
    std::copy(inna_.tb,inna_.tb+calkowity_rozmiar,tb);
    return *this;
}
Macierz::~Macierz(){
    if(tb != nullptr)
        delete [] tb;
}
std::istream &operator>>(std::istream &we, Macierz &x) throw (RozmiarNiePasujeException){
    int kolumny,wiersze;
    we >> kolumny >> wiersze;
    if(kolumny <= 0 || wiersze <= 0)
        throw RozmiarNiePasujeException(std::string("Ujemny rozmiar"));
    x.kolumny = kolumny;
    x.wiersze = wiersze;
    int calkowity_rozmiar = kolumny * wiersze;
    if(x.tb != nullptr)
        delete [] x.tb;
    x.tb = new Macierz::scalar_t[calkowity_rozmiar];
    for(int i=0;i<calkowity_rozmiar;++i){
        we >> x.tb[i];
    }
    return we;
}
std::ostream &operator<<(std::ostream &wy, const Macierz &x){
    wy << "Kolumny: " << x.kolumny << " Wiersze: " << x.wiersze << std::endl;
    for(int i=0;i<x.wiersze;++i){
        for(int j=0;j<x.kolumny;++j){
            wy << x.tb[i*x.kolumny+j] << " ";
        }
        wy << std::endl;
    }
    return wy;
}
Macierz operator+(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException){
    if(x.kolumny != y.kolumny || x.wiersze != y.wiersze)
        throw RozmiarNiePasujeException(std::string("Rozne rozmiary macierzy"));
    int calkowity_rozmiar = x.kolumny * x.wiersze;
    Macierz nowa(x.kolumny,x.wiersze);
    std::transform(x.tb,x.tb + calkowity_rozmiar,y.tb,nowa.tb,
                   [](Macierz::scalar_t x, Macierz::scalar_t y) -> Macierz::scalar_t{
                    return x+y;});
    return nowa;
}
Macierz operator-(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException){
    if(x.kolumny != y.kolumny || x.wiersze != y.wiersze)
        throw RozmiarNiePasujeException(std::string("Rozne rozmiary macierzy"));
    int calkowity_rozmiar = x.kolumny * x.wiersze;
    Macierz nowa(x.kolumny,x.wiersze);
    std::transform(x.tb,x.tb + calkowity_rozmiar,y.tb,nowa.tb,
                   [](Macierz::scalar_t x, Macierz::scalar_t y) -> Macierz::scalar_t{
                    return x-y;});
    return nowa;
}
Macierz operator*(const Macierz &x, const Macierz &y) throw (RozmiarNiePasujeException){
    if(x.kolumny != y.wiersze)
        throw RozmiarNiePasujeException("Nie da sie pomnozyc macierzy");
    Macierz nowa(y.kolumny,x.wiersze);
    for(int i=0;i<x.wiersze;++i){
        for(int j=0;j<y.kolumny;++j){
            for(int k=0;k<x.kolumny;++k){
                nowa.tb[i*y.kolumny+j] += x.tb[i*x.kolumny+k]*y.tb[k*y.kolumny+j];
            }
        }
    }
    return nowa;
}
Macierz operator*(const Macierz &x, Macierz::scalar_t skalar){
    int calkowity_rozmiar = x.kolumny * x.wiersze;
    Macierz nowa(x.kolumny,x.wiersze);
    std::transform(x.tb,x.tb + calkowity_rozmiar,nowa.tb,
                   [skalar](Macierz::scalar_t x) -> Macierz::scalar_t{
                    return x*skalar;});
    return nowa;
}
Macierz operator*(Macierz::scalar_t skalar, const Macierz &x){
    return operator*(x,skalar);
}

Macierz Macierz::transponowana(){
    Macierz nowa(wiersze,kolumny);
    for(int i=0;i<wiersze;++i){
        for(int j=0;j<kolumny;++j){
            nowa.tb[j*wiersze+i] = tb[i*kolumny+j];
        }
    }
    return nowa;
}
