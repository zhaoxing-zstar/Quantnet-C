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
	shapes[2]=new Circle;
	shapes[3]=new Line(Point(1.0, 2.5), Point(3.4, 5.2));

	for (int i=0; i!=4; i++) shapes[i]->Draw();
	for (int i=0; i!=4; i++) delete shapes[i];
	/*
	Can't create an instance of the Shape class because shape class is now an abstract base class.
	But we can still create shape pointers that point to concrete shapes like point and line.
	*/
}
