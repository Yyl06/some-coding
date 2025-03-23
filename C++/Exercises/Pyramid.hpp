#ifndef PYRAMID_H
#define PYRAMID_H
#include <cmath>
class Pyramid{
    private :
        double length , width , height;

    public :
    Pyramid(double l , double w, double h){
        length = l;
        width = w;
        height = h;
    }

    double GetVolume(double length , double height){
        return (length * length * height) / 3;
    }

    double GetVolume(double length , double width , double height){
        return (length * width * height) / 3;
    }

    double GetArea(double length , double height){
        return (length * length) + (2 * length * sqrt((length / 2) * (length / 2) + height * height));
    }

    double GetArea(double length , double width , double height){
        return (length * width) + (length * sqrt((width / 2) * (width / 2) + height * height)) + (width * sqrt((length / 2) * (length / 2) + height * height));
    }
};

#endif
