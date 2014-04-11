#include <iostream>
#include "data.hpp"
#include <string>
#include <sstream>
template <typename T>
T czytajLiczbe(){
    std::string input = "";
    T number;
    while(1){
        std::getline(std::cin, input);
        std::stringstream stream(input);
        if (stream >> number)
            break;
        std::cout << "Niepoprawna liczba, podaj jeszcze raz.\n";
    }
    return number;
}

int main()
{   Data data_systemowa = Data();
    try{
        while(1){
            int dzien,miesiac,rok;
            std::cout << "Dzien: ";
            dzien = czytajLiczbe<int>();
            std::cout << "Miesiac: ";
            miesiac = czytajLiczbe<int>();
            std::cout << "Rok: ";
            rok = czytajLiczbe<int>();
            Data nowa_data(dzien,miesiac,rok);
            std::cout << "Roznica pomiedzy datami: " << Data::roznicaPomiedzyDatami(nowa_data,data_systemowa)
                      << "\n" << nowa_data.dzien << "." << nowa_data.miesiac << "." << nowa_data.rok
                      << " jest w: " << nowa_data.dzienTygodniaSlownie() <<"\n";
        }
    }catch(std::string &s){
        std::cerr << s;
    }
    return 0;
}
