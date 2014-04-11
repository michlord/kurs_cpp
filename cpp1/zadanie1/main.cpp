#include <iostream>
#include "kolo.h"
#include "punkt.h"
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>
int testy(){

    Punkt p1,p2;
    Kolo k1,k2;

    //punkt w kole
    k1 = Kolo(Punkt(0,0),5);
    p1 = Punkt(4.9,0);
    if(czyPunktWKole(p1,k1) == false)
        return 1;
    //punkt na obwodzie kola
    p1 = Punkt(5,0);
    if(czyPunktWKole(p1,k1) == false)
        return 2;
    //punkt poza kolem
    p1 = Punkt(5.1,0);
    if(czyPunktWKole(p1,k1) == true)
        return 3;
    //okregi rozlacznie zewnetrzne
    k2 = Kolo(Punkt(10,0),4.9);
    if(czyPunktyWspolneKola(k1,k2) == true)
        return 4;
    //okregi styczne zewnetrznie
    k2 = Kolo(Punkt(10,0),5);
    if(czyPunktyWspolneKola(k1,k2) == false)
        return 5;
    //okregi przecinajace sie
    k2 = Kolo(Punkt(10,0),5.1);
    if(czyPunktyWspolneKola(k1,k2) == false)
        return 6;
    //okregi styczne wewnetrznie
    k2 = Kolo(Punkt(2.5,0),2.5);
    if(czyPunktyWspolneKola(k1,k2) == false)
        return 7;
    //okregi rozlaczne wewnetrznie
    k2 = Kolo(Punkt(2.5,0),2.4);
    if(czyPunktyWspolneKola(k1,k2) == true)
        return 8;
    //okregi wspolsrodkowe o roznych promieniach
    k2 = Kolo(Punkt(0,0),2);
    if(czyPunktyWspolneKola(k1,k2) == true)
        return 9;
    //okregi wspolsrodkowe o takim samym promieniu
    k2 = Kolo(Punkt(0,0),5);
    if(czyPunktyWspolneKola(k1,k2) == false)
        return 10;
    //pole kola
    const double EPSILON = 0.000001;
    k1 = Kolo(Punkt(123.123,456.456),0.123456);
    if(fabs(k1.pole()-0.0478822198) > EPSILON)
        return 11;
    //przesuniecie srodka kola
    k1 = Kolo(Punkt(1.5,2.5),6);
    k1.przesun(1.5,1.0);
    if(fabs(k1.srodek.x - 3.0) > EPSILON || fabs(k1.srodek.y - 3.5) > EPSILON)
        return 12;
    //przesuniecie punktu
    p1 = Punkt(1.5,2.5);
    p1.przesun(1.5,1.0);
    if(fabs(p1.x - 3.0) > EPSILON || fabs(p1.y - 3.5) > EPSILON)
        return 13;
    return 0;
}


int czytajInteger(){
    std::string input = "";
    int number;
    while(1){
        std::getline(std::cin, input);
        std::stringstream stream(input);
        if (stream >> number)
            break;
        std::cout << "Niepoprawna liczba, podaj jeszcze raz.\n";
    }
    return number;
}

double czytajDouble(){
    std::string input = "";
    double number;
    while(1){
        std::getline(std::cin, input);
        std::stringstream stream(input);
        if (stream >> number)
            break;
        std::cout << "Niepoprawna liczba, podaj jeszcze raz.\n";
    }
    return number;
}

std::vector< std::pair< int, int> > wylistujPunktyZawarteWKolach(const std::vector<Punkt> &punkty, const std::vector<Kolo> &kola){
    std::vector< std::pair< int, int> > lista;
    for(int i=0;i<punkty.size();++i)
    {
        for(int j=0;j<kola.size();++j)
        {
            if(czyPunktWKole(punkty[i],kola[j]) == true)
            {
                lista.push_back(std::make_pair(i,j));
            }
        }
    }
    return lista;
}
std::vector< std::pair< int, int> > wylistujKolaZPunktamiWspolnymi(const std::vector<Kolo> &kola){
    std::vector< std::pair< int, int> > lista;
    for(int i=0;i<kola.size();++i)
    {
        for(int j=0;j<kola.size();++j)
        {
            if(i==j)
                continue;
            if(czyPunktyWspolneKola(kola[i],kola[j])==true)
                lista.push_back(std::make_pair(i,j));

        }
    }
    //musi byc posortowane, zeby dzialalo unique
    std::sort(lista.begin(),lista.end());
    // unique - signals new size of the shortened range by returning
    // an iterator to the element that should be considered its new past-the-end element.
    lista.erase(std::unique(lista.begin(),lista.end()),lista.end());
    return lista;
}

int main(){

    int res = testy();
    if(res!=0)
        std::cout << "Nie przeszlo testow!!! Wynik: " << res << "\n";

    std::vector<Kolo> kola;
    std::vector<Punkt> punkty;
    while(1){
        std::cout << "1 - dodaj kolo\n"
                    "2 - dodaj punkt\n"
                    "3 - wypisz, ktore punkty zawieraja sie w kolach\n"
                    "4 - wypisz, ktore kola maja punkty wspolne\n"
                    "5 - wypisz wszystkie kola i punkty\n\n";
        int action = czytajInteger();
        if(action < 1 || action > 6){
            std::cout << "Zla komenda!\n";
            continue;
        }
        if(action == 1){
            double x,y,r;
            std::cout << "x: ";
            x = czytajDouble();
            std::cout << "y: ";
            y = czytajDouble();
            std::cout << "r: ";
            r = czytajDouble();
            try{
                Kolo k(Punkt(x,y),r);
                kola.push_back(k);
            }catch(std::string &str){
                std::cout << str <<" Kolo nie zostalo dodane.\n";
            }

        }
        else if(action == 2){
            double x,y;
            std::cout << "x: ";
            x = czytajDouble();
            std::cout << "y: ";
            y = czytajDouble();
            Punkt p(x,y);
            punkty.push_back(p);
        }
        else if(action == 3){
            std::vector< std::pair< int, int> > v = wylistujPunktyZawarteWKolach(punkty,kola);
            for(int i=0;i<v.size();++i)
            {
                std::cout << "Punkt ( " << punkty[v[i].first].x << ", " << punkty[v[i].first].y << ") w kole ( " << kola[v[i].second].srodek.x <<
                             ", " << kola[v[i].second].srodek.y << ", " << kola[v[i].second].r << ")\n";
            }
        }
        else if(action == 4){
            std::vector< std::pair< int, int> > v = wylistujKolaZPunktamiWspolnymi(kola);
            for(int i=0;i<v.size();++i)
            {
                std::cout << "Kolo ( "<< kola[v[i].first].srodek.x << ", " << kola[v[i].first].srodek.y << ", " << kola[v[i].first].r << ") w kole (" <<
                             kola[v[i].second].srodek.x << ", " << kola[v[i].second].srodek.y << ", " << kola[v[i].second].r << " )\n";
            }
        }
        else if(action == 5){
            for(int i=0;i<kola.size();++i)
            {
                Kolo &k = kola[i];
                std::cout << "Kolo (x = " << k.srodek.x << " y = " << k.srodek.y << " r = " << k.r << " pole = " << k.pole() << " )\n";
            }
            for(int i=0;i<punkty.size();++i)
            {
                Punkt &p = punkty[i];
                std::cout << "Punkt (x = " << p.x << " y = " << p.y << " )\n";
            }
        }
    }
    return 0;
}
