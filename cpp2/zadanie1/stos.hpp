#ifndef STOS_H_
#define STOS_H_

class Stos{
private:
    double *tablica;
    int ile;
    //operator przypisywania - nie chce go uzywac...
    //Class_name & Class_name::operator=(const Class_name &);
    Stos &operator=(const Stos &inny_){return *this;}
public:
    const int rozmiar;
    //konstruktor z domyslnym parametrem
    Stos(int rozmiar_=1);
    //konstruktor kopiujacy
    //Class_name(const Class_name &);
    Stos(const Stos &inny_);

    //destruktor
    ~Stos();
    void wloz(double wartosc_);
    double sciagnij();
    double sprawdz();
    int zapelnienie();
    bool czyPusty();
};


#endif
