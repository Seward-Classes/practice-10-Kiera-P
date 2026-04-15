#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

#include "Shape.h"

// Temporary workaround (until CMake)
#include "Shape.cpp"

using namespace std;

void printAllAreas(const vector<unique_ptr<Shape>>& shapes)
{
    for (const auto& shape : shapes)
    {
        shape->display();
        cout << fixed << setprecision(4);
        cout << "Area: " << shape->getArea() << "\n\n";
    }
}

int main()
{
    ifstream file("shapes.txt");
    if (!file)
    {
        cerr << "Error: Could not open shapes.txt\n";
        return 1;
    }

    vector<unique_ptr<Shape>> shapes;
    string line;
    int lineNumber = 0;

    while (getline(file, line))
    {
        lineNumber++;

        if (line.empty())
            continue;

        stringstream ss(line);
        string type;
        ss >> type;

        if (type == "rectangle")
        {
            double w, h;
            if (ss >> w >> h)
            {
                shapes.push_back(make_unique<Rectangle>(w, h));
            }
            else
            {
                cerr << "Error on line " << lineNumber << ": Invalid rectangle data\n";
            }
        }
        else if (type == "circle")
        {
            double r;
            if (ss >> r)
            {
                shapes.push_back(make_unique<Circle>(r));
            }
            else
            {
                cerr << "Error on line " << lineNumber << ": Invalid circle data\n";
            }
        }
        else
        {
            cerr << "Error on line " << lineNumber << ": Unknown shape type '" << type << "'\n";
        }
    }

    printAllAreas(shapes);

    return 0;
}