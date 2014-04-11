#include "stos.hpp"
#include <string>
#include <new>
#include <algorithm>
Stos::Stos(int rozmiar_):rozmiar(rozmiar_){
    if(rozmiar <= 0){
        throw std::string("Ujemny rozmiar stosu!");
    }
    try{
        tablica = new double[rozmiar_];
        ile     = 0;
    }catch(std::bad_alloc& ba){
        throw std::string("Nie udalo sie zaalokowac pamieci: ") + ba.what();
    }
}
Stos::Stos(const Stos &inny_):rozmiar(inny_.rozmiar){
    try{
        tablica = new double[rozmiar];
        ile     = inny_.ile;
        std::copy(inny_.tablica,inny_.tablica+inny_.ile,tablica);
    } catch(std::bad_alloc& ba){
        throw std::string("Nie udalo sie zaalokowac pamieci: ") + ba.what();
    }
}
Stos::~Stos(){
    delete [] tablica;
}
void Stos::wloz(double wartosc_){
    if(ile >= rozmiar){
        throw std::string("Stos pelny.");
    }
    tablica[ile] = wartosc_;
    ile += 1;
}
double Stos::sciagnij(){
    if(czyPusty() == true){
        throw std::string("Stos pusty.");
    }
    ile -= 1;
    return tablica[ile];
}
double Stos::sprawdz(){
    if(czyPusty() == true){
        throw std::string("Stos pusty.");
    }
    return tablica[ile-1];
}
int Stos::zapelnienie(){
    return ile;
}
bool Stos::czyPusty(){
    return ile <= 0;
}
