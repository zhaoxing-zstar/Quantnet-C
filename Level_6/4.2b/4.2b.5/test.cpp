// Test Program for StackException
#include "Stack.hpp"
#include "Point.hpp"
#include "PointArray.hpp"
#include "Exception.hpp"
#include "StackException.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using zstar::Containers::Stack;
using namespace std;

int main()
{	Stack<Point> st(5);
	//		test the StackEmptyException
	try
	{
		//initialize pointarrays with some values
		PointArray pa1(5);
		for(int i=0; i!=pa1.Size();i++)
		{
			pa1.SetElement(i,Point(i,i+1));
		}
		//push some points in the stack
		for(int i=0; i!=3;i++)
		{
			st.Push(pa1[i]);
		}
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl; //this will throw an StackEmptyException because of too many pop(s)
	}
	catch(StackException& excep)
	{
		cout<<excep.GetMessage()<<endl;
	}
	catch(...) //default catch
	{
		cout<<"An unexcepted error has happened"<<endl;
	}


	//test the StackFullException
	try
	{
		//initialize pointarrays with some values
		PointArray pa1(5);
		for(int i=0; i!=pa1.Size();i++)
		{
			pa1.SetElement(i,Point(i,i+1));
		}
		//push some points in the stack
		for(int i=0; i!=4;i++)
		{
			st.Push(pa1[i]);
		}
		st.Push(Point(4,5)); //this will throw an StackFullException because of too many push(s)
	}
	catch(StackException& excep)
	{
		cout<<excep.GetMessage()<<endl;
	}
	catch(...) //default catch
	{
		cout<<"An unexcepted error has happened"<<endl;
	}
	return 0;
	
}
	
