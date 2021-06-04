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
// Destrcutor
Point::~Point()	
{
	
	cout << "Point destroyed\n" << endl;
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
	descrip << "Point(" << x << ", " << y << ")";
	
	return descrip.str();
}
// the distance to the origin(0,0)
double Point::DistanceOrigin()
{
	return sqrt(pow(x,2)+pow(y,2));
}
// distance between two points
double Point::Distance(Point p)
{
	return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
}