#ifndef WYRAZENIE_H_
#define WYRAZENIE_H_

#include <string>
#include <vector>
#include <utility>
#include <cmath>

class Wyrazenie{
    public:
        virtual double oblicz() const = 0;
        virtual std::string opis() const = 0;
        virtual ~Wyrazenie(){};
};

class Liczba : public Wyrazenie{
    private:
        double wartosc;
    public:
        Liczba(int wartosc_);
        /*override*/ double oblicz() const;
        /*override*/ std::string opis() const;
};

class Zmienna : public Wyrazenie{
    public:
        typedef std::vector< std::pair<std::string,double> > zbior;
    private:
        static zbior::iterator pobierzIteratorZmiennej(const char *nazwa_);
        static zbior zmienne;
        std::string nazwa;
    public:
        Zmienna(const char *nazwa_);
        /*override*/ double oblicz() const;
        /*override*/ std::string opis() const;
        static bool dodajZmienna(const char *nazwa_, double wartosc_);
        static bool usunZmienna(const char *nazwa_);
        static double pobierzWartoscZmiennej(const char *nazwa_);

};

//Ta klasa tez jest abstrakcyjna
class Operator1Arg : public Wyrazenie{
    protected:
         Wyrazenie *operand;
    public:
        Operator1Arg(Wyrazenie *operand_):
            operand(operand_){}
        /*override*/ ~Operator1Arg(){
            if(operand != nullptr)
                delete operand;
        }
};

//Ta klasa tez jest abstrakcyjna
class Operator2Arg : public Wyrazenie{
    protected:
        Wyrazenie *operand_lewy;
        Wyrazenie *operand_prawy;
    public:
        Operator2Arg(Wyrazenie *operand_lewy_, Wyrazenie *operand_prawy_):
            operand_lewy(operand_lewy_),operand_prawy(operand_prawy_){}
        /*override*/ ~Operator2Arg(){
            if(operand_lewy != nullptr)
                delete operand_lewy;
            if(operand_prawy != nullptr)
                delete operand_prawy;
        }
};

class PrzeciwnyZnak : public Operator1Arg{
    public:
        PrzeciwnyZnak(Wyrazenie *operand_):
            Operator1Arg(operand_){};
        /*override*/ double oblicz() const{
            return (-1) * operand->oblicz();
        }
        /*override*/ std::string opis() const{
            return "-(" + operand->opis() + ")";
        }
};

class WartoscBezwzgledna : public Operator1Arg{
    public:
        WartoscBezwzgledna(Wyrazenie *operand_):
            Operator1Arg(operand_){};
        /*override*/ double oblicz() const{
            return fabs(operand->oblicz());
        }
        /*override*/ std::string opis() const{
            return "abs(" + operand->opis() + ")";
        }
};

class Sin : public Operator1Arg{
    public:
        Sin(Wyrazenie *operand_):
            Operator1Arg(operand_){};
        /*override*/ double oblicz() const{
            return sin(operand->oblicz());
        }
        /*override*/ std::string opis() const{
            return "sin(" + operand->opis() + ")";
        }
};

class Cos : public Operator1Arg{
    public:
        Cos(Wyrazenie *operand_):
            Operator1Arg(operand_){};
        /*override*/ double oblicz() const{
            return cos(operand->oblicz());
        }
        /*override*/ std::string opis() const{
            return "cos(" + operand->opis() + ")";
        }
};

class Dodaj : public Operator2Arg{
    public:
        Dodaj(Wyrazenie *operand_lewy_, Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            return operand_lewy->oblicz() + operand_prawy->oblicz();
        }
        /*override*/ std::string opis() const{
            return "(" + operand_lewy->opis() + "+" + operand_prawy->opis() + ")";
        }
};

class Odejmij : public Operator2Arg{
    public:
        Odejmij(Wyrazenie *operand_lewy_, Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            return operand_lewy->oblicz() - operand_prawy->oblicz();
        }
        /*override*/ std::string opis() const{
            return "(" + operand_lewy->opis() + "-" + operand_prawy->opis() + ")";
        }
};

class Mnoz : public Operator2Arg{
    public:
        Mnoz( Wyrazenie *operand_lewy_,  Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            return operand_lewy->oblicz() * operand_prawy->oblicz();
        }
        /*override*/ std::string opis() const{
            return "(" + operand_lewy->opis() + "*" + operand_prawy->opis() + ")";
        }
};

class Dziel : public Operator2Arg{
    public:
        Dziel( Wyrazenie *operand_lewy_,  Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            //dzielenie przez zero da NaN
            return operand_lewy->oblicz() / operand_prawy->oblicz();
        }
        /*override*/ std::string opis() const{
            return "(" + operand_lewy->opis() + "/" + operand_prawy->opis() + ")";
        }
};

class Logarytm : public Operator2Arg{
    public:
        Logarytm( Wyrazenie *operand_lewy_,  Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            return log(operand_prawy->oblicz())/log(operand_lewy->oblicz());
        }
        /*override*/ std::string opis() const{
            //podstawa i liczba
            return "log(" + operand_lewy->opis() + "," + operand_prawy->opis() + ")";
        }
};

class Modulo : public Operator2Arg{
    public:
        Modulo( Wyrazenie *operand_lewy_, Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            //dzielenie przez zero da NaN
            return (int)operand_lewy->oblicz() % (int)operand_prawy->oblicz();
        }
        /*override*/ std::string opis() const{
            return "((int)" + operand_lewy->opis() + "%" + "(int)" + operand_prawy->opis() + ")";
        }
};

class Potega : public Operator2Arg{
    public:
        Potega( Wyrazenie *operand_lewy_,  Wyrazenie *operand_prawy_):
            Operator2Arg(operand_lewy_,operand_prawy_){};
        /*override*/ double oblicz() const{
            //dzielenie przez zero da NaN
            return powf(operand_lewy->oblicz(),operand_prawy->oblicz());
        }
        /*override*/ std::string opis() const{
            return "(" + operand_lewy->opis() + "^" + operand_prawy->opis() + ")";
        }
};


#endif
