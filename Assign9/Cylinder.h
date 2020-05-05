#ifndef CYLINDER_H
#define CYLINDER_H

#include <string>

using std::string;

class Cylinder : public Circle
{
    public:
        Cylinder(string, int, int);
        double getArea();
        virtual double getVolume();
        void print();

    private:
        int height;

};

#endif
© 2017 GitHub, Inc.

