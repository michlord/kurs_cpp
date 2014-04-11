#include <iostream>
#include <typeinfo>
#include "newstring.h"
#include <string>



obliczenia::NewString pomnozStringa(obliczenia::NewString s,int amt){
    amt = amt >= 0 ? amt : -amt;
    obliczenia::NewString out = "";
    while(amt--)
        out += s;
    return out;
}

int fib(int i){
    if(i<=0)
        return 0;
    if(i==1)
        return 1;
    return fib(i-1)+fib(i-2);
}

obliczenia::NewString fibToString(int f){
    return fib(f);
}

void test1(){
    obliczenia::NewString str("lalala");
    str += 2;
    str += 2.3;
    obliczenia::NewString str2;
    //wg mnie takie podejscie jest ok
    str2 = obliczenia::NewString(7.98) + str;
    std::cout << (double)str2;
    obliczenia::NewString str3 = "Jeden";
    str3 += 4;
    //wynik nie jest oczywisty
    str3 = str3 + 2 + 5 + 5;
    std::cout << str3 << std::endl;
    obliczenia::NewString str4 = "";
    //wynik nie jest oczywisty
    str4 = 1 + 2 + 4;
    std::cout << str4 << std::endl;
}

void test2(){
    obliczenia::NewString f = fibToString(6);
    obliczenia::NewString b = pomnozStringa("Michal",3);
    obliczenia::NewString k = pomnozStringa(123,3);
    std::cout << f << std::endl << b << std::endl << k << std::endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
