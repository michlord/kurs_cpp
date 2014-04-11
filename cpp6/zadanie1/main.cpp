#include <iostream>
#include "wyrazenie.h"
void testyDlaWyrazenZZadania(){
    Wyrazenie * test1 = new Dodaj(new Liczba(3),new Liczba(5));
    std::cout << test1->opis();
    std::cout << "=" << test1->oblicz() << std::endl;
    Wyrazenie * test2 = new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7)));
    Zmienna::dodajZmienna("x",-3.14);
   // Zmienna::usunZmienna("x");
   // Zmienna::dodajZmienna("x",-3.14);
    std::cout << test2->opis();
    std::cout << "=" << test2->oblicz() << std::endl;
    std::cout << "x=" << Zmienna::pobierzWartoscZmiennej("x") << std::endl;
    Wyrazenie * test3 = new Dziel(
                                  new Odejmij(
                                              new Mnoz(
                                                       new Liczba(3),
                                                       new Liczba(11)
                                                       ),
                                              new Liczba(1)
                                              ),
                                  new Dodaj(
                                            new Liczba(7),
                                            new Liczba(5)
                                            )
                                  );
    std::cout << test3->opis();
    std::cout << "=" << test3->oblicz() << std::endl;
    Wyrazenie * test4 = new Dziel(
                                  new Mnoz(
                                           new Dodaj(
                                                     new Zmienna("x"),
                                                     new Liczba(1)
                                                     ),
                                           new  Zmienna("x")
                                           ),
                                  new Liczba(2)
                                  );
    std::cout << test4->opis();
    std::cout << "=" << test4->oblicz() << std::endl;
    Wyrazenie * test5 = new Sin(
                                new Dodaj(
                                          new Mnoz(
                                                   new Liczba(2),
                                                   new Zmienna("x")
                                                   ),
                                          new Liczba(1)
                                          )
                                );
    std::cout << test5->opis();
    std::cout << "=" << test5->oblicz() << std::endl;
}

int main()
{
    testyDlaWyrazenZZadania();
    return 0;
}
