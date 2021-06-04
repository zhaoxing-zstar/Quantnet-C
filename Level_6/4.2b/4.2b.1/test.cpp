// Test Program
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Exception.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using namespace std;

int main()
{
	
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	
	cout<<intArray1.DefaultSize()<<endl;
	cout<<intArray2.DefaultSize()<<endl;
	cout<<doubleArray.DefaultSize()<<endl;
	
	intArray1.DefaultSize(15);
	
	cout<<intArray1.DefaultSize()<<endl;
	cout<<intArray2.DefaultSize()<<endl;
	cout<<doubleArray.DefaultSize()<<endl;

	/*
	output:
	0
	0
	0
	15
	15
	0

	In template-based programming in C++, static member variables are created for each different 
	type class(int & double in this case), therefore, the DefaultSize of the doubleArray remains 
	0 even though we change the DefaultSize of the intArray.



	*/
}
	
