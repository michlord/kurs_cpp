#include "punkt.h"
Punkt::Punkt(){
}
Punkt::Punkt(double x_, double y_) : x(x_), y(y_){
}
void Punkt::przesun(double dx, double dy){
    x += dx;
    y += dy;
}
