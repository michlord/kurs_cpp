#ifndef KOLO_H_
#define KOLO_H_

#include "punkt.h"

class Kolo{
private:

public:
    Kolo();
    Kolo(const Punkt &srodek_, double r_);
    void przesun(double dx_, double dy_);
    double pole();
    Punkt srodek;
    double r;
};

bool czyPunktWKole(const Punkt &punkt_,const Kolo &kolo_);
bool czyPunktyWspolneKola(const Kolo &kolo1_, const Kolo &kolo2_);

#endif
