#include <math.h>
#include "Cone.h"

using std::sqrt;
using std::cout;
using std::endl;

Cone::Cone(string newName, int newRadius, int newHeight) 
{
    this->name = newName;
    this->radius = newRadius;
    height = newHeight;
}

double Cone::getArea() 
{
    double area = 3.14*radius(radius+sqrt((height*height)+(radius*radius)));
    return area;
}

virtual double Cone::getVolume() 
{
    double volume = 3.14*(radius*radius)(height/3); 
    return volume;
}

void Cone::print() 
{
    cout << Circle::print() << ", " << height << ", " << getVolume() << endl;
}
