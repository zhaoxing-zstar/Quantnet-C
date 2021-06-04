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
	
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1,2), Point(3, 4)); // Create line.

	cout<<s.ToString()<<endl; // Print shape.
	cout<<p.ToString()<<endl; // Print point.
	cout<<l.ToString()<<endl; // Print line

	cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
	cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
	cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?

	Shape* sp; // Create pointer to a shape variable.
	sp=&p; // Point in a shape variable. Possible?
	cout<<sp->ToString()<<endl; // What is printed?
	/*
	Now the ToString() function of the Point is called instead of the one in the Shape class
	This is because ToString() in base class Shape has been declared virtual.  
	So the Shape* variable now knows what type of object it is pointing to.
	*/

	// Create and copy Point p to new point.
	Point p2;
	p2=p;
	cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call the base class assignment in point?
	
	return 0;
}
