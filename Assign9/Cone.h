#ifndef CONE_H
#define CONE_H

#include <string>

using std::string;

class Cone : public Circle
{
    public:
        Cone(string, int, int);
        double getArea();
        virtual double getVolume();
        void print();

    private:
        int height;
};

#endif
