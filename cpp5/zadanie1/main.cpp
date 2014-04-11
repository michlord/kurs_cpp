#include <iostream>
#include "datagodz.hpp"
#include "struktury.hpp"
using namespace std;


void testyAutomatyczne(){
    //DataGodz test;
    //std::cout << test.dzien << "." << test.miesiac << "." << test.rok << " godzina: " << test.godzina ;
    Lista lista;
    lista.wstaw(Para(DataGodz(),std::string("test1")),0);
    lista.wstaw(Para(DataGodz(),std::string("test2")),1);
    lista.wstaw(Para(DataGodz(),std::string("test3")),2);
    lista.wstaw(Para(DataGodz(),std::string("test4")),3);
    lista.wstaw(Para(DataGodz(),std::string("test5")),4);
    lista.wstaw(Para(DataGodz(),std::string("test6")),5);
    lista.wstaw(Para(DataGodz(),std::string("test2.5")),2);
    lista.wstaw(Para(DataGodz(),std::string("test0")),0);
    lista.wstaw(Para(DataGodz(),std::string("test7")),8);
    std::cout << lista.usun(0).second << std::endl;
    lista.usun(7);
    std::cout << lista;
    std::cout << lista.rozmiar() << std::endl;
    std::cout << lista[0].second << std::endl << lista[6].second<< std::endl << lista[3].second<< std::endl;

    DataGodz d1(10,1,2011,10);
    DataGodz d2(1,9,1700,14);
    DataGodz d3(5,10,1911,15);
    DataGodz d4(4,8,2000,10);
    DataGodz d5(14,4,1999,6);
    DataGodz d6(11,2,1887,13);

    Kolejka k;
    k.wstaw(Para(d1,"test1"));
    k.wstaw(Para(d2,"test2"));
    k.wstaw(Para(d3,"test3"));
    k.wstaw(Para(d4,"test4"));
    k.wstaw(Para(d5,"test5"));
    k.wstaw(Para(d6,"test6"));
    k.wstaw(Para(d5,"test5-2"));
    k.wstaw(Para(d1,"test1-2"));
    std::cout << k;
    std::cout << "po zdjeciu:\n";
    k.zdejmij();
    k.zdejmij();
    k.zdejmij();
    std::cout << k;
   // std::cin >> k;
   // std::cout << "po dodaniu:\n";
   // std::cout << k;
}

int main(){

    int action=0;
    std::cout << "1 wstaw element do listy\n"
                 "2 usun element z listy\n"
                 "3 sprawdz rozmiar listy\n"
                 "4 wypisz liste\n"
                 "5 wstaw do kolejki\n"
                 "6 zdejmij z kolejki\n"
                 "7 wypisz zawartosc kolejki\n";
    Lista lista;
    Kolejka kolejka;
    try{
        while(action != 42){
            std::cout << "?-";
            std::cin >> action;
            switch(action){
                case 1:{
                    std::cin >> lista;
                }break;
                case 2:{
                    int index;
                    std::cout << "Index: ";
                    std::cin >> index;
                    Para usunieta = lista.usun(index);
                    std::cout << "Usunieto: " << usunieta.first.dzien << "."
                              << usunieta.first.miesiac << "."
                              << usunieta.first.rok << " Zdarzenie: "
                              << usunieta.second << std::endl;
                }break;
                case 3:{
                    std::cout << "Rozmiar: " << lista.rozmiar();
                }break;
                case 4:{
                    std::cout << lista;
                }break;
                case 5:{
                    std::cin >> kolejka;
                }break;
                case 6:{
                    Para usunieta = kolejka.zdejmij();
                    std::cout << "Zdjeto: " << usunieta.first.dzien << "."
                              << usunieta.first.miesiac << "."
                              << usunieta.first.rok << " Zdarzenie: "
                              << usunieta.second << std::endl;
                }break;
                case 7:{
                    std::cout <<kolejka;
                }break;
                default:
                    std::cout << "Zly argument!\n";
            }
        }
    }catch(std::string e){
        std::cerr << e;
    }
    return 0;
}
