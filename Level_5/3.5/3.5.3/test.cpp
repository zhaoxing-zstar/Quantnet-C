// Test Program
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;      
using namespace std;
int main()
{
	
	Shape* shapes[3];
	shapes[0]=new Shape;
	shapes[1]=new Point;
	shapes[2]=new Line;

	for (int i=0; i!=3; i++)  delete shapes[i];

	return 0;
	/*
	If the destructor is not declared as virtual, three Shape destructors will be called.
	Upon declaring the base class destructor as virtual, the proper destructors for the derived classes are now called correctly.
	*/
}
