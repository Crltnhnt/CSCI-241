#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
    public:
        Circle();
        int getRadius();
        virtual double getArea();
        void print();

    private:
        int radius;
};

#endif
