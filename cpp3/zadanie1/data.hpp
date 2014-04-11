#ifndef DATA_H_
#define DATA_H_
#include <string>
class Data{
private:
    bool czyDataPoprawna() const;
    int ileDniUplyneloOdDaty() const;
    static int dniwmiesiacach[2][13];
    static int dniodpoczroku[2][13];
protected:
    static bool czyRokPrzestepny(const int rok_);
    static int aktualnyDzien();
    static int aktualnyMiesiac();
    static int aktualnyRok();
public:
    std::string dzienTygodniaSlownie() const;
    enum {poniedzialek=1,wtorek=2,sroda=3,czwartek=4,piatek=5,sobota=6,niedziela=7};
    const int dzien;
    const int miesiac;
    const int rok;
    Data();
    Data(int dzien_, int miesiac_, int rok_);
    Data(const Data &inny_);
    static int roznicaPomiedzyDatami(const Data &data_wczesniejsza_, const Data &data_pozniejsza_);

};
#endif
