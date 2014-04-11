#include "data.hpp"
#include <ctime>
#include <string>

Data poczatek_kalendarza(15,10,1582);

int Data::dniwmiesiacach[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
    {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};
int Data::dniodpoczroku[2][13] = {
    {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
    {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};
//ile uplynelo od pierwszego dnia
int Data::ileDniUplyneloOdDaty() const{
    bool przestepny = czyRokPrzestepny(rok);
    int dodatkowe_dni = dniodpoczroku[przestepny][miesiac-1] + dzien;
    int ile_razy_rok_przestepny = (rok-1)/4 - (rok-1)/100 + (rok-1)/400;
    return ile_razy_rok_przestepny*dniodpoczroku[1][12] + (rok-1-ile_razy_rok_przestepny)*dniodpoczroku[0][12] + dodatkowe_dni;
}
bool Data::czyDataPoprawna() const{
    if((miesiac < 1) || (miesiac > 12))
        return false;
    bool przestepny = czyRokPrzestepny(rok);
    if(dniwmiesiacach[przestepny][miesiac] < dzien)
        return false;
    if(rok < poczatek_kalendarza.rok)
        return false;
    if((rok == poczatek_kalendarza.rok) && (miesiac < poczatek_kalendarza.miesiac))
        return false;
    if((rok == poczatek_kalendarza.rok) && (miesiac == poczatek_kalendarza.miesiac) && (dzien < poczatek_kalendarza.dzien))
        return false;
    return true;
}
bool Data::czyRokPrzestepny(const int rok_){
    return (rok_ % 400 == 0) || ((rok_ % 100 != 0) && (rok_ % 4 == 0));
}


tm* Data::teraz = 0;

int Data::aktualnyDzienIUstawCzas(){
    time_t t = time(0);
    Data::teraz = localtime(&t);
    return teraz->tm_mday;
}

Data::Data(): dzien(aktualnyDzienIUstawCzas()),miesiac(teraz->tm_mon + 1),rok(teraz->tm_year + 1900){
    if(czyDataPoprawna() == false)
        throw std::string("Data jest niepoprawna");

}
Data::Data(int dzien_, int miesiac_, int rok_):dzien(dzien_),miesiac(miesiac_),rok(rok_){
    if(czyDataPoprawna() == false)
        throw std::string("Data jest niepoprawna");
}
Data::Data(const Data &inny_):dzien(inny_.dzien),miesiac(inny_.miesiac),rok(inny_.rok){
    if(czyDataPoprawna() == false)
        throw std::string("Data jest niepoprawna");
}

int Data::roznicaPomiedzyDatami(const Data &data_wczesniejsza_, const Data &data_pozniejsza_){
    int delta = data_pozniejsza_.ileDniUplyneloOdDaty() - data_wczesniejsza_.ileDniUplyneloOdDaty();
    return delta;
    //return delta >= 0 ? delta : -1;
}
std::string Data::dzienTygodniaSlownie() const{
    static const int offset = 6;
    int dzien = (ileDniUplyneloOdDaty()+offset)%7 + 1;
    switch(dzien)
    {
        case 1:
            return std::string("Poniedzialek");
        case 2:
            return std::string("Wtorek");
        case 3:
            return std::string("Sroda");
        case 4:
            return std::string("Czwartek");
        case 5:
            return std::string("Piatek");
        case 6:
            return std::string("Sobota");
        case 7:
            return std::string("Niedziela");
        default:
            return std::string("NA");
    }
}
