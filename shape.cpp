#include "Shape.h"
#include <iomanip>
#include <cmath>

Rectangle::Rectangle(double w, double h)
{
    width = w;
    height = h;
}

double Rectangle::getArea() const
{
    return width * height;
}

void Rectangle::display() const
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Rectangle (" << width << " x " << height << ")\n";
}

Circle::Circle(double r)
{
    radius = r;
}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

void Circle::display() const
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Circle (radius: " << radius << ")\n";
}