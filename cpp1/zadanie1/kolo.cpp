#include "kolo.h"
#include <string>
#include <cmath>


const double PI = 3.14159265359;
const double EPSILON = 0.000001;

Kolo::Kolo(){
}
Kolo::Kolo(const Punkt &srodek_, double r_): srodek(srodek_), r(r_){
    if (r_<=0.0) throw std::string("Niedodatni promien kola!");
}
void Kolo::przesun(double dx, double dy){
    //srodek.x += dx;
    //srodek.y += dy;
    srodek.przesun(dx,dy);
}
double Kolo::pole(){
    return PI * r * r;
}
bool czyPunktWKole(const Punkt &punkt_,const Kolo &kolo_){
    double dystans_kw = (kolo_.srodek.x - punkt_.x) * (kolo_.srodek.x - punkt_.x) + (kolo_.srodek.y - punkt_.y) * (kolo_.srodek.y - punkt_.y);
    double promien_kw = kolo_.r * kolo_.r;
    return ( dystans_kw <= promien_kw + EPSILON );
}
bool czyPunktyWspolneKola(const Kolo &kolo1_, const Kolo &kolo2_){
    double x1,y1,x2,y2,r1,r2;
    x1 = kolo1_.srodek.x;
    y1 = kolo1_.srodek.y;
    r1 = kolo1_.r;
    x2 = kolo2_.srodek.x;
    y2 = kolo2_.srodek.y;
    r2 = kolo2_.r;
    double dystans_kw = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    double dystans = sqrt(dystans_kw);
    if ( dystans_kw < EPSILON && fabs(r1-r2) < EPSILON)
        return true; // takie same kola
    if ( fabs(dystans - r1 - r2) < EPSILON )
        return true; // styczne zewnetrznie
    if ( dystans < r1 + r2 && dystans > fabs(r1-r2) )
        return true; // przecinaja sie
    //std::cout << "dystans: " << dystans << " abs(r1-r2): " << fabs(r1-r2) << " \n";
    if ( fabs( dystans - fabs(r1-r2)) < EPSILON )
        return true; //styczne wewnetrznie
    return false;
}
