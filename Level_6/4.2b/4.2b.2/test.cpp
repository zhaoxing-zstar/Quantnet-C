// Test Program for NumericArray
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
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
	NumericArray<double> arr1(10);
	NumericArray<double> arr2(10);
	NumericArray<double> arr3(20);
	try
	{
		//initialize numericarrays with some values
		for(int i=0; i!=arr1.Size();i++) arr1[i]=(i+1);
		for(int i=0; i!=arr2.Size();i++) arr2[i]=(i+2);
		for(int i=0; i!=arr3.Size();i++) arr3[i]=(i*i);

		// doublesum=arr1+arr2
		NumericArray<double> doublesum(10);
		doublesum=arr1+arr2;
		// output the result
		for(int i=0;i!=doublesum.Size();i++) cout<<doublesum[i]<<",";
		cout<<endl;

		//Scale
		NumericArray<double> doublescale(10);
		doublescale=arr1*3;
		for(int i=0;i!=doublescale.Size();i++) cout<<doublescale[i]<<",";
		cout<<endl;
		
		//DotProduct
		cout<<"the dot product of arr1 & arr2 is:"<<(arr1.DotProduct(arr2))<<endl;

		//this will cause error because arr2 and arr3 have not the same size
		cout<<"the dot product of arr1 & arr2 is:"<<(arr2.DotProduct(arr3))<<endl;

	}
	catch(ArrayException& excep)
	{
		cout<<excep.GetMessage()<<endl;
	}
	catch(...) //default catch
	{
		cout<<"An unexcepted error has happened"<<endl;
	}
	return 0;
	
}
	
