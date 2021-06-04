/*
point.h
header files for Point class

Distance function called by reference
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

    double GetX();          //GetX & GetY function
    double GetY();
    double DistanceOrigin();
    double Distance(const Point &p);


    void SetX(double new_X); //Modifiers
    void SetY(double new_Y);

    string ToString();       //Description

};


#endif