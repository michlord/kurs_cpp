#include "struktury.hpp"
#include <string>
#include <iostream>
Lista::Wezel::Wezel(const Para &wartosc_):wartosc(wartosc_){
    nastepny = 0;
}

void Lista::init(const Para& p_){
    glowa = new Wezel(p_);
}

Lista::Lista(){
    glowa = 0;
}
Lista::Lista(const Lista &inna_){
    kopiujInnaListe(inna_);
}
//zakladam ze lista jest wyczyszczona
void Lista::kopiujInnaListe(const Lista &inna_){
    Wezel *tmp = inna_.glowa;
    if(tmp == 0)
        return;
    glowa = new Wezel(tmp->wartosc);
    Wezel * tmp_glowa = glowa;
    while(tmp->nastepny != 0){
        tmp_glowa->nastepny = new Wezel(tmp->nastepny->wartosc);
        tmp_glowa = tmp_glowa->nastepny;
        tmp = tmp->nastepny;
    }
}
void Lista::wyczysc(){
    Wezel * nastepny = 0;
    while(glowa != 0){
        nastepny = glowa->nastepny;
        delete glowa;
        glowa = nastepny;
    }
    glowa = 0;
}

Lista::~Lista(){
    wyczysc();
    std::cout << "Destruktor listy\n";
}
Lista& Lista::operator=(const Lista &inna_){
    wyczysc();
    kopiujInnaListe(inna_);
    return *this;
}
std::istream& operator>>(std::istream &we, Lista &w){
    int dzien,mies,rok,godz;
    std::string zdarzenie;
    std::cout << "dzien: ";
    we >> dzien;
    std::cout << "miesiac: ";
    we >> mies;
    std::cout << "rok: ";
    we >> rok;
    std::cout << "godzina: ";
    we >> godz;
    std::cout << "zdarzenie: ";
    we >> zdarzenie;
    DataGodz d(dzien,mies,rok,godz);
    Para p(d,zdarzenie);
    int index;
    std::cout << "index: ";
    we >> index;
    w.wstaw(p,index);
    return we;
}
std::ostream& operator<<(std::ostream &wy, const Lista &w){
    const Lista::Wezel *tmp = w.glowa;
    const Para *wartosc;
    while(tmp != 0){
        wartosc = &(tmp->wartosc);
        wy  << wartosc->first.dzien << "." << wartosc->first.miesiac  << "."
            << wartosc->first.rok << " godzina: " << wartosc->first.godzina << " Zdarzenie: "
            << wartosc->second << std::endl;
        tmp = tmp->nastepny;
    }
    return wy;
}

void Lista::wstaw(const Para& wartosc_,int index_){
    Wezel *tmp = glowa;
    if(index_ == 0){
        glowa = new Wezel(wartosc_);
        glowa->nastepny = tmp;
    }else{
        while((tmp != 0) && ((index_-1) > 0))
        {
            --index_;
            tmp = tmp->nastepny;
        }
        if(tmp == 0)
            throw std::string("Wyjscie poza zakres");
        Wezel *nowy_tmp = new Wezel(wartosc_);
        nowy_tmp->nastepny = tmp->nastepny;
        tmp->nastepny = nowy_tmp;
    }
}
Para Lista::usun(int index_){
    Wezel *tmp = glowa;
    if(index_ == 0){
        if(glowa == 0)
            throw std::string("Wyjscie poza zakres");
        Para wartosc = glowa->wartosc;
        tmp = glowa->nastepny;
        delete glowa;
        glowa = tmp;
        return wartosc;
    }else{
        while((tmp != 0) && ((index_-1) > 0))
        {
            --index_;
            tmp = tmp->nastepny;
        }
        if(tmp == 0 || tmp->nastepny == 0)
            throw std::string("Wyjscie poza zakres");
        Wezel *tmp_nast = tmp->nastepny->nastepny;
        Para wartosc = tmp->nastepny->wartosc;
        delete tmp->nastepny;
        tmp->nastepny = tmp_nast;
        return wartosc;
    }
}
Para& Lista::operator[](int i){
    Wezel *tmp = glowa;
    while((tmp != 0) && (i > 0))
    {
        --i;
        tmp = tmp->nastepny;
    }
    if(tmp == 0)
        throw std::string("Wyjscie poza zakres");
    return tmp->wartosc;
}
const Para& Lista::operator[](int i) const{
    const Wezel *tmp = glowa;
    while((tmp != 0) && (i > 0))
    {
        --i;
        tmp = tmp->nastepny;
    }
    if(tmp == 0)
        throw std::string("Wyjscie poza zakres");
    return tmp->wartosc;
}
int Lista::rozmiar() const{
    int counter = 0;
    Wezel *tmp = glowa;
    while(tmp != 0)
    {
        ++counter;
        tmp = tmp->nastepny;
    }
    return counter;
}

Kolejka::Kolejka():Lista(){
}
Kolejka::Kolejka(const Kolejka &inna_):Lista(inna_){
}
//nie trzeba wywolywac destrukora listy bo kompilator sam to robi
Kolejka::~Kolejka(){
    std::cout << "Destruktor kolejki\n";
}
Kolejka& Kolejka::operator=(const Kolejka &inna_){
    Lista::operator=(inna_);
    return *this;
}
std::istream& operator>>(std::istream &we, Kolejka &w){
    int dzien,mies,rok,godz;
    std::string zdarzenie;
    std::cout << "dzien: ";
    we >> dzien;
    std::cout << "miesiac: ";
    we >> mies;
    std::cout << "rok: ";
    we >> rok;
    std::cout << "godzina: ";
    we >> godz;
    std::cout << "zdarzenie: ";
    we >> zdarzenie;
    DataGodz d(dzien,mies,rok,godz);
    Para p(d,zdarzenie);
    w.wstaw(p);
    return we;
}
std::ostream& operator<<(std::ostream &wy, const Kolejka &w){
    wy << (const Lista &) w;
    return wy;
}
//najpozniejsza wartosc na poczatek
void Kolejka::wstaw(const Para& wartosc_){
    if(glowa == 0)
    {
        glowa = new Wezel(wartosc_);
        glowa->nastepny = 0;
        return;
    }
    Wezel *tmp = glowa;
    if(glowa->wartosc.first < wartosc_.first)
    {
        glowa = new Wezel(wartosc_);
        glowa->nastepny = tmp;
        return;
    }
    while(tmp->nastepny != 0)
    {
        if(tmp->nastepny->wartosc.first < wartosc_.first)
        {
            Wezel *tmp_nast = tmp->nastepny;
            tmp->nastepny = new Wezel(wartosc_);
            tmp->nastepny->nastepny = tmp_nast;
            return;
        }
        tmp = tmp->nastepny;
    }
    tmp->nastepny = new Wezel(wartosc_);
}
Para Kolejka::zdejmij(){
    return Lista::usun(0);
}
