#include <iostream>
#include "wielomian.hpp"
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
{
    std::cout << "1 - dodaj dwa wielomiany\n"
                 "2 - odejmij jeden wielomian od drugiego\n"
                 "3 - przemnoz wielomian przez wielomian\n"
                 "4 - przemnoz wielomian przez stala\n";
    try{
        int action;
        while(1){
            action = czytajLiczbe<int>();
            switch(action){
            case 1:
                {
                    Wielomian w1,w2;
                    std::cout << "Podaj stopien i wielomian 1:\n";
                    std::cin >> w1;
                    std::cout << "Podaj stopien i wielomian 2:\n";
                    std::cin >> w2;
                    std::cout << "Wynik:\n";
                    std::cout << w1+w2 << "\n";
                }
                break;
            case 2:
                {
                    Wielomian w1,w2;
                    std::cout << "Podaj stopien i wielomian 1:\n";
                    std::cin >> w1;
                    std::cout << "Podaj stopien i wielomian 2:\n";
                    std::cin >> w2;
                    std::cout << "Wynik:\n";
                    std::cout << w1-w2 << "\n";
                }
                break;
            case 3:
                {
                    Wielomian w1,w2;
                    std::cout << "Podaj stopien i wielomian 1:\n";
                    std::cin >> w1;
                    std::cout << "Podaj stopien i wielomian 2:\n";
                    std::cin >> w2;
                    std::cout << "Wynik:\n";
                    std::cout << w1*w2 << "\n";
                }
                break;
            case 4:
                {
                    Wielomian w1;
                    double k;
                    std::cout << "Podaj stopien i wielomian 1:\n";
                    std::cin >> w1;
                    std::cout << "Podaj stala:\n";
                    k = czytajLiczbe<int>();
                    std::cout << "Wynik:\n";
                    std::cout << w1*k << "\n";
                }
                break;
            default:
                std::cout << "Niepoprawne dane!\n";
            }
            while(std::cin.get()!='\n');

        }

    }catch(std::string &s){
        std::cerr << s;
    }
    return 0;
}
