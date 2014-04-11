#include <iostream>
#include <sstream>
#include "macierz.h"



void test(){
    try{
        std::stringstream s;
        s << "2 3 1 2 3 4 5 6 2 3 1 2 3 4 5 6";
        Macierz m1,m2;
        s >> m1 >> m2;
        std::cout << "m1:\n" << m1;
        std::cout << "m2:\n" << m2;
        std::cout << "m1+m2:\n" << m1 + m2;
        std::cout << "m1-m2:\n" << m1 - m2;
        std::cout << "m1 transponowana:\n" << m1.transponowana();
        std::cout << "m1 * 0.5:\n" << m1 * 0.5;

        //http://pl.wikipedia.org/wiki/Mno%C5%BCenie_macierzy
        s.clear();
        s << "3 2 1 0 2 -1 3 1 2 3 3 1 2 1 1 0";
        Macierz m3,m4;
        s >> m3 >> m4;
        std::cout << "m3:\n" << m3;
        std::cout << "m4:\n" << m4;
        std::cout << "m3 * m4:\n" << m3 * m4;

        //http://www.math.edu.pl/mnozenie-macierzy
        s.clear();
        s << "2 2 2 1 3 4 3 2 5 8 2 7 6 5";
        Macierz m5,m6;
        s >> m5 >> m6;
        std::cout << "m5:\n" << m5;
        std::cout << "m6:\n" << m6;
        std::cout << "m5 * m6:\n" << m5 * m6;
    }catch(RozmiarNiePasujeException &e){
        std::cout << e.what();
    }
}

void test2(){
    try{
        std::stringstream s;
        s << "2 4 1 2 3 4 5 6 7 8 3 2 1 2 3 4 5 6";
        Macierz m1,m2;
        s >> m1 >> m2;
        std::cout << m1 << m2;
        std::cout << m1 * m2;

    }catch(RozmiarNiePasujeException &e){
        std::cout << e.what();
    }
}

void test3(){
    try{
        std::stringstream s;
        s << "1 2 1 2 2 1 3 4";
        Macierz m1,m2;
        s >> m1 >> m2;
        std::cout << m1 << m2;
        std::cout << m1 * m2;

    }catch(RozmiarNiePasujeException &e){
        std::cout << e.what();
    }
}
void test4(){
    try{
        std::stringstream s;
        s << "2 1 3 4 1 2 1 2";
        Macierz m1,m2;
        s >> m1 >> m2;
        std::cout << m1 << m2;
        std::cout << m1 * m2;

    }catch(RozmiarNiePasujeException &e){
        std::cout << e.what();
    }
}



int main()
{
    //test();
    //test2();
    test3();
    test4();


    return 0;
}
