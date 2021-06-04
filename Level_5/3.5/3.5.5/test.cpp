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
	shapes[0]=new Line;
	shapes[1]=new Point;
	shapes[2]=new Line(Point(1.0, 2.5), Point(3.4, 5.2));

	for (int i=0; i!=3; i++) shapes[i]->Print();
 	for (int i=0; i!=3; i++) delete shapes[i];
	/*
	a function for the base class (Print()) that does all the functionality common to all derived classes.
	*/
}
