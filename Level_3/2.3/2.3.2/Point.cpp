/*
 Point.cpp
 Implementation member functions for Point class
*/



#include "Point.hpp"	

#include <sstream>		
#include <iostream>	
#include <cmath>	
using namespace std;


// Initialize with 0
Point::Point() : x(0), y(0) 
{
	cout << "Point created\n" << endl;
}
// a constructor with x-y coordinates
Point::Point(double xval,double yval) : x(xval), y(yval)
{
	cout << "Point created with given values" << endl;
}
// copy constructor 
Point::Point(const Point &p)
{
	x=p.x;
	y=p.y;
	cout << "Point copied"<< endl;
}
// Destrcutor
Point::~Point()	
{
	
	cout << "Point destroyed" << endl;
}
//Get the x-coordinate
double Point::GetX()
{
	return x;
}
//Get the y-coordinate
double Point::GetY() 
{
	return y;
}
//modify the x-coordinate
void Point::SetX(double new_X)
{ 
	x = new_X;
}
//modify the y-coordinate
void Point::SetY(double new_Y)
{ 
	y = new_Y;
}
//string description of the point
string Point::ToString()
{
	stringstream descrip;
	descrip << "Point(" << x << ", " << y << ")"<<endl;
	
	return descrip.str();
}
// the distance to the origin(0,0)
double Point::DistanceOrigin()
{
	return sqrt(pow(x,2)+pow(y,2));
}
// distance between two points (call by reference)
double Point::Distance(const Point &p)
{
	return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
}