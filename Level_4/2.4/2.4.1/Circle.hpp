/*
header files for Circle class
*/

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"
#include "Line.hpp"

#include<iostream>
#include<sstream>
using namespace std;


class Circle
{
private:
    double m_radius;
    Point m_center_p;
public:
    //Constructors and Destructors
    Circle();
    Circle(const double &radius, const Point &center_p);
    Circle(const Circle &c);
    Circle &operator = (const Circle &source);          //Assignment operator
    ~Circle();

    //getter functions for radius & centerpoint
    double Radius() const;
    Point CenterPoint() const;

    //setter functions for radius & centerpoint
    void Radius(const double &radius);
    void CenterPoint(const Point &center_p);

    //string description of a circle
    string ToString() const;

    //calculate the diameter, area and circumference of the circle
    double Diameter() const;
    double Area() const;
    double Circumference() const;

};

#endif