// Test Program
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;      
using namespace std;
int main()
{
	Line l;
	return 0;
	/*
	#  when Line class doesn't use colon syntax:
	Number of point constructor, destructor, and assignment calls=8
	#  when Line class uses colon syntax:
	Number of point constructor, destructor, and assignment calls=4

	The colon syntax can improve the performance of constructors. If we don't use the colon syntax,
	the memeber data must first be initialized with default constructors, and then reassigned via 
	assignment operator with actual values, so there are two more Point initialization processes.




	*/
}
