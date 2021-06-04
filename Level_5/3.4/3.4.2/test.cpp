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
	/*
	Yes, this works. The public members of the base class Shape become part of the public interface
	of the dervied class. The Point class inherits the base functionality from Shape.
	*/

	cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
	/*
	YYes, this works. The public members of the base class Shape become part of the public interface
	of the dervied class. The Line class inherits the base functionality from Shape.
	*/

	Shape* sp; // Create pointer to a shape variable.
	sp=&p; // Point in a shape variable. Possible?
	/*
	Possible. The pointer of a Shape can be given the address of a Point because Point is a 
	derived class from Shape.
	*/

	cout<<sp->ToString()<<endl; // What is printed?
	/*
	This calls the ToString function of the Shape class, but the ID of the point is printed.
	*/

	// Create and copy Point p to new point.
	Point p2;
	p2=p;
	cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call the base class assignment in point?
	/*
	The ID won't be copied if I don't call the base class assignment in point.
	You must explicitly call it from the derived class assignment operator member function.
	*/
	return 0;
}
