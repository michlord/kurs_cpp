#include "wielomian.hpp"
#include <string>
#include <algorithm>
#include <cmath>
Wielomian::Wielomian(int st, double wsp){
    //stopien nie moze byc inny niz 0
    n = 0;
    a = new double[1];
    a[0] = wsp;
}
Wielomian::Wielomian(int st, double *wsp){
    if(st<0)
        throw std::string("Ujemny wspolczynnik");
    if(wsp[st]==0 && st!= 0)
        throw std::string("Zero w najwyzszym wspolczynniku");
    a = new double[st+1];
    n = st;
    std::copy(wsp,wsp+st+1,a);
}
Wielomian::Wielomian(const Wielomian &w){
    this->n = w.n;
    this->a = new double[this->n+1];
    std::copy(w.a,w.a+w.n+1,this->a);
}
Wielomian& Wielomian::operator=(const Wielomian &w){
    if(this->a != 0)
        delete [] this->a;
    this->n = w.n;
    this->a = new double[this->n+1];
    std::copy(w.a,w.a+w.n+1,this->a);
    return *this;
}
Wielomian::~Wielomian(){
    if(this->a != 0)
        delete [] this->a;
}
std::istream& operator>>(std::istream &we, Wielomian &w){
    //wczytaj stopien, a potem tyle wspolczynnikow co stopien+1
    int stopien;
    we >> stopien;
    double *tmp_wsp = new double[stopien+1];
    for(int i=0;i<=stopien;++i)
    {
        we >> tmp_wsp[i];
    }
    w = Wielomian(stopien,tmp_wsp);
    delete [] tmp_wsp;
    return we;
}
std::ostream& operator<<(std::ostream &wy, const Wielomian &w){
    wy << w.n << " ";
    for(int i=0;i<=w.n;++i)
    {
        wy << w[i] << " ";
    }
    return wy;
}
int Wielomian::stopien(){
    return n;
}

Wspolczynnik Wielomian::operator[](int i){
    if(i<0 || i>n)
        throw std::string("Wyjscie poza zakres");
    if(i==n && n!=0)
        return Wspolczynnik(a[i],true);
    return Wspolczynnik(a[i],false);
}

const Wspolczynnik Wielomian::operator[](int i) const{
    if(i<0 || i>n)
        throw std::string("Wyjscie poza zakres");
    if(i==n && n!=0)
        return Wspolczynnik(a[i],true);
    return Wspolczynnik(a[i],false);
}


Wielomian operator+(const Wielomian &w1, const Wielomian &w2){
    int max_deg = std::max(w1.n,w2.n);
    double *tmp_wsp1 = new double[max_deg+1];
    double *tmp_wsp2 = new double[max_deg+1];
    std::fill(tmp_wsp1,tmp_wsp1+max_deg+1,0.0);
    std::fill(tmp_wsp2,tmp_wsp2+max_deg+1,0.0);
    std::copy(w1.a,w1.a+w1.n+1,tmp_wsp1);
    std::copy(w2.a,w2.a+w2.n+1,tmp_wsp2);
    for(int i=0;i<=max_deg;++i)
    {
        tmp_wsp1[i] += tmp_wsp2[i];
    }
    Wielomian tmp(max_deg,tmp_wsp1);
    delete [] tmp_wsp1;
    delete [] tmp_wsp2;
    return tmp;
}
Wielomian operator-(const Wielomian &w1, const Wielomian &w2){
    int max_deg = std::max(w1.n,w2.n);
    double *tmp_wsp1 = new double[max_deg+1];
    double *tmp_wsp2 = new double[max_deg+1];
    std::fill(tmp_wsp1,tmp_wsp1+max_deg+1,0.0);
    std::fill(tmp_wsp2,tmp_wsp2+max_deg+1,0.0);
    std::copy(w1.a,w1.a+w1.n+1,tmp_wsp1);
    std::copy(w2.a,w2.a+w2.n+1,tmp_wsp2);
    for(int i=0;i<=max_deg;++i)
    {
        tmp_wsp1[i] -= tmp_wsp2[i];
    }
    while(fabs(tmp_wsp1[max_deg]) < 0.0001 && max_deg > 0)
        --max_deg;
    Wielomian tmp(max_deg,tmp_wsp1);
    delete [] tmp_wsp1;
    delete [] tmp_wsp2;
    return tmp;
}
Wielomian operator*(const Wielomian &w1, double k_){
    if ( fabs(k_) < 0.0001 )
        return Wielomian(0,0.0);
    Wielomian tmp(w1);
    for(int i=0;i<=tmp.n;++i)
    {
        tmp.a[i]*=k_;
    }
    return tmp;
}
Wielomian operator*(const Wielomian &w1, const Wielomian &w2){
    if(w1.czyZero() || w2.czyZero())
        return Wielomian(0,0.0);
    int max_deg = w1.n + w2.n;
    double *tmp_wsp1 = new double[max_deg+1];
    std::fill(tmp_wsp1,tmp_wsp1+max_deg+1,0.0);
    //std::copy(w1.a,w1.a+w1.n+1,tmp_wsp1);
    for(int i=0;i<=w2.n;++i)
    {
        for(int j=0;j<=w1.n;++j)
        {
            tmp_wsp1[j+i]+=w1.a[j]*w2.a[i];
        }
    }
    Wielomian tmp(max_deg,tmp_wsp1);
    delete [] tmp_wsp1;
    return tmp;
}
double Wielomian::operator()(double x)const{
    if(n == 0)
        return a[0];
    int i = n-1;
    double sum = a[i] + a[i+1]*x;
    for(i=i-1; i>=0; --i)
    {
        sum = a[i] + sum*x;
    }
    return sum;
}

Wielomian& Wielomian::operator+=(const Wielomian &w1){
    *this = *this + w1;
    return *this;
}
Wielomian& Wielomian::operator-=(const Wielomian &w1){
    *this = *this - w1;
    return *this;
}
Wielomian& Wielomian::operator*=(double k_){
    *this = *this * k_;
    return *this;
}
Wielomian& Wielomian::operator*=(const Wielomian &w1){
    *this = *this * w1;
    return *this;
}

inline bool Wielomian::czyZero() const{
    return n==0 && a[0]==0;
}
