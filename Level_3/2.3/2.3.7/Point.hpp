/*
point.h
header files for Point class

#2.3.2   Distance function called by reference
#2.3.3   change DistanceOrigin() function to Distance(), 
            and rename the SetX() andGetX() functions to just X(), same for y;

#2.3.4  const functions

#2.3.7 Inline functions
*/

#ifndef Point_HPP
#define Point_HPP

#include<sstream>
#include<iostream>
using namespace std;

class Point
{
private:
    double x;             //x-coordinate
    double y;             //y-coordinate

public:
    Point();      //Constrcutor and Destructor
    Point(double xval,double yval);  //a constructor that accepts x- and y- coordinates
    Point(const Point &p);     //copy constructor
    
    ~Point();

    double X() const;          //X & Y function
    double Y() const;
    double Distance() const;
    double Distance(const Point &p) const;


    void X(double new_X) {x=new_X;} //Modifiers
    void Y(double new_Y) {y=new_Y;}

    string ToString() const;       //Description

};

inline double Point::X() const {return x;}
inline double Point::Y() const {return y;}

#endif