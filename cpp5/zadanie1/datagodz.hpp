#ifndef DATA_GODZ_H_
#define DATA_GODZ_H_
#include "data.hpp"
#include <utility>
#include <string>

class DataGodz : public Data {
private:
    bool czyGodzinaPoprawna();
public:
    const int godzina;
    DataGodz();
    DataGodz(int dzien_, int miesiac_, int rok_, int godzina_);
    DataGodz(const DataGodz &inny_);
    friend bool operator==(const DataGodz &d1, const DataGodz &d2);
    friend bool operator<(const DataGodz &d1, const DataGodz &d2);
    friend bool operator<=(const DataGodz &d1, const DataGodz &d2);
    friend bool operator>(const DataGodz &d1, const DataGodz &d2);
    friend bool operator>=(const DataGodz &d1, const DataGodz &d2);
};

typedef std::pair<DataGodz,std::string> Para;

#endif
