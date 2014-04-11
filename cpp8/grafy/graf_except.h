#ifndef GRAF_EXCEPT_H_
#define GRAF_EXCEPT_H_

#include <exception>

class ujemna_liczba_wierzcholkow : public std::exception{
};
class nieprawidlowa_krawedz : public std::exception{
};

#endif
