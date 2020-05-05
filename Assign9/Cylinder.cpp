#include <iostream>
#include "Cylinder.h"

using std::cout;
using std::endl;

Cylinder::Cylinder(string newName, int newRadius, int newHeight)
{
    this->name = newName;
    this->radius = newRadius;
    height = newHeight;
}

Cylinder::double getArea()
{
    double area = 2*3.14*radius*height+2*3.14*(radius*radius);
    return area;
}

virtual double Cylinder::getVolume()
{
    double volume = 3.14*(radius*radius)*height; 
    return volume;
}

void Cylinder::print()
{
    cout << Circle::print() << ", " << height << ", " << getVolume() << endl;
}
