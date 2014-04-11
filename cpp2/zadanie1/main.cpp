#include <iostream>
#include "stos.hpp"
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

int main(){
    std::string wiadomosc = "1 - wloz liczbe\n"
                            "2 - sciagnij liczbe\n"
                            "3 - sprawdz liczbe na wierzchu\n"
                            "4 - liczba elementow na stosie\n?-";
    std::cout << "Podaj rozmiar stosu: ";
    int rozmiar_stosu = czytajLiczbe<int>();
    try{
        Stos stos(rozmiar_stosu);
        int wybor;
        while(true){
            std::cout << wiadomosc;
            wybor = czytajLiczbe<int>();
            switch(wybor){
                case 1:
                    {
                        std::cout << "Wartosc: ";
                        double wartosc = czytajLiczbe<double>();
                        try{
                            stos.wloz(wartosc);
                        }catch(std::string &str){
                            std::cout << str << "\n";
                        }
                    }
                    break;
                case 2:
                    {
                        try{
                            double wartosc = stos.sciagnij();
                            std::cout << "Sciagnieto wartosc: " << wartosc << "\n";
                        } catch(std::string &str){
                            std::cout << str << "\n";
                        }
                    }
                    break;
                case 3:
                    {
                        try{
                            double wartosc = stos.sprawdz();
                            std::cout << "Wartosc na wierzchu: " << wartosc << "\n";
                        } catch(std::string &str){
                            std::cout << str << "\n";
                        }

                    }
                    break;
                case 4:
                    {
                        int ilosc = stos.zapelnienie();
                        std::cout << "Ilosc elementow: " << ilosc << "\n";

                    }
                    break;
                default:
                    std::cout << "Zly wybor\n";
                    break;
            }
        }
    }catch(std::string &str){
        std::cout << str;
        return 1;
    }

    return 0;
}
