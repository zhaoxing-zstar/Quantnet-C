/*
 Point.cpp
 Implement member functions for Point class
*/



#include "Point.hpp"	

#include <sstream>		
#include <iostream>	
#include <cmath>	
using namespace std;


// Initialize with 0
Point::Point() : x(0), y(0) 
{
	// cout << "Point created\n" << endl;
}
// a constructor with x-y coordinates
Point::Point(double xval,double yval) : x(xval), y(yval)
{
	// cout << "Point created with given values" << endl;
}
// copy constructor 
Point::Point(const Point &p)
{
	x=p.x;
	y=p.y;
	// cout << "Point copied"<< endl;
}
// Destrcutor
Point::~Point()	
{
	
	// cout << "Point destroyed" << endl;
}
//string description of the point
string Point::ToString() const
{
	stringstream descrip;
	descrip << "Point(" << x << ", " << y << ")";
	
	return descrip.str();
}
// the distance to the origin(0,0)
double Point::Distance() const
{
	return sqrt(pow(x,2)+pow(y,2));
}
// distance between two points (call by reference)
double Point::Distance(const Point &p) const
{
	return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
}
//Negate the coordinates
Point Point::operator - () const
{
	return Point(-x,-y);
}
// scale the coordinates
Point Point::operator * (double factor) const
{
	return Point(x*factor,y*factor);
}
//add coordinates
Point Point::operator + (const Point &p) const
{
	return Point(x+p.x,y+p.y);
}
//equally compare operator
bool Point::operator == (const Point& p) const
{
	return (x==p.x) and (y==p.y); 
}
//Assignment operator
Point& Point::operator = (const Point& source)
{
	x=source.x;
	y=source.y;
	return *this;
}
//scale the coordinates and assign
Point& Point::operator *= (double factor)
{
	x*=factor;y*=factor;
	return *this;
}
//overloading Ostream << Operator
ostream& operator << (ostream& os, const Point& p)
{
	os << p.ToString();
	return os;
}

