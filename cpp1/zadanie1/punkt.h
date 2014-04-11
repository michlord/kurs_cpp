#ifndef PUNKT_H_
#define PUNKT_H_

class Punkt{
private:
public:
    Punkt();
    Punkt(double x_, double y_);
    void przesun(double dx_, double dy_);
    double x;
    double y;
};

#endif
