// Test Program for PointArray
#include "Point.hpp"
#include "PointArray.hpp"
#include "Exception.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using namespace std;

int main()
{
	try
	{
		//initialize pointarrays with some values
		PointArray pa1(5);
		for(int i=0; i!=pa1.Size();i++)
		{
			pa1.SetElement(i,Point(i,i+1));
		}
		cout<<pa1.Length()<<endl;
		//expected output: 4*\sqrt{2}=5.656

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
	
