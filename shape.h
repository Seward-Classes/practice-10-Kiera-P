#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
    virtual double getArea() const = 0;

    virtual void display() const
    {
        std::cout << "Shape\n";
    }

    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);

    double getArea() const override;

    void display() const override;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r);

    double getArea() const override;

    void display() const override;
};

#endif