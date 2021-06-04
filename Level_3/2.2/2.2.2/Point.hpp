/*
point.h
header files for Point class
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
    
    ~Point();

    double GetX();          //GetX & GetY function
    double GetY();
    double DistanceOrigin();
    double Distance(Point p);


    void SetX(double new_X); //Modifiers
    void SetY(double new_Y);

    string ToString();       //Description

};


#endif