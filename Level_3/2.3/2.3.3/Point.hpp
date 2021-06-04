/*
point.h
header files for Point class

# Distance function called by reference
#   change DistanceOrigin() function to Distance(), 
    and rename the SetX() andGetX() functions to just X(), same for y;

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

    double X();          //X & Y function
    double Y();
    double Distance();
    double Distance(const Point &p);


    void X(double new_X); //Modifiers
    void Y(double new_Y);

    string ToString();       //Description

};


#endif