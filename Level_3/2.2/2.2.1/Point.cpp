/*
 Point.cpp
 Implementation member functions for Point class
*/



#include "Point.hpp"	

#include <sstream>		
#include <iostream>		
using namespace std;

Point::Point() : m_x(0), m_y(0) 
{
	cout << "Point created\n" << endl;
}

Point::~Point()	// Destructor
{
	
	cout << "Point destroyed\n" << endl;
}
double Point::GetX()
{
	return m_x;
}
double Point::GetY() 
{
	return m_y;
}
void Point::SetX(double new_X)
{ 
	m_x = new_X;
}
void Point::SetY(double new_Y)
{ 
	m_y = new_Y;
}
string Point::ToString()
{
	stringstream descrip;
	descrip << "Point(" << m_x << ", " << m_y << ")";
	
	return descrip.str();
}