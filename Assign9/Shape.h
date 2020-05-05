#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using std::string;

class Shape
{

    public:
        Shape(const string&);
        virtual ~Shape();
        virtual void print();
        virtual double getArea() const = 0;

    private:
        string name;

};

#endif
