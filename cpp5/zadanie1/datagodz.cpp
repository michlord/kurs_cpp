#include "datagodz.hpp"
bool DataGodz::czyGodzinaPoprawna(){
    return (godzina >= 0 && godzina <= 23);
}
DataGodz::DataGodz() : Data(), godzina(teraz->tm_hour){
    if(czyGodzinaPoprawna() == false)
        throw std::string("Godzina jest niepoprawna");
}
DataGodz::DataGodz(int dzien_, int miesiac_, int rok_, int godzina_): Data(dzien_,miesiac_,rok_), godzina(godzina_){
    if(czyGodzinaPoprawna() == false)
        throw std::string("Godzina jest niepoprawna");
}
DataGodz::DataGodz(const DataGodz &inny_):Data(inny_), godzina(inny_.godzina){
    if(czyGodzinaPoprawna() == false)
        throw std::string("Godzina jest niepoprawna");
}
bool operator==(const DataGodz &d1, const DataGodz &d2){
    return (d1.godzina == d2.godzina) &&
           (d1.dzien == d2.dzien) &&
           (d1.miesiac == d2.miesiac) &&
           (d1.rok == d2.rok);
}
bool operator<(const DataGodz &d1, const DataGodz &d2){
    if(d1.rok < d2.rok)
        return true;
    if(d1.rok == d2.rok &&
       d1.miesiac < d2.miesiac)
        return true;
    if(d1.rok == d2.rok &&
       d1.miesiac == d2.miesiac &&
       d1.dzien < d2.dzien)
        return true;
    if(d1.rok == d2.rok &&
       d1.miesiac == d2.miesiac &&
       d1.dzien == d2.dzien &&
       d1.godzina < d2.godzina)
       return true;
    return false;
}
bool operator<=(const DataGodz &d1, const DataGodz &d2){
    return (d1 < d2) || (d1 == d2);
}
bool operator>(const DataGodz &d1, const DataGodz &d2){
    return !(d1 <= d2);
}
bool operator>=(const DataGodz &d1, const DataGodz &d2){
    return (d1 > d2) || (d1 == d2);
}
