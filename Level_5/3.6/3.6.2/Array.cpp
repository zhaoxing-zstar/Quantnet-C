/*
Array.cpp
Implement memeber functions for Array class
*/

#include "Point.hpp"
#include "Array.hpp"
#include<iostream>
using namespace std;

namespace zstar{

    namespace Containers{
        Array::Array()      //Default constructor
        {
            m_size=10;      //default 10 elements
            m_data= new CAD::Point[m_size];

        }
        Array::Array(const int &array_len)      //overload constructor
        {
            m_size=array_len;
            m_data=new CAD::Point[m_size];
        }
        Array::Array(const Array& a)        //copy constructor
        {
            m_size=a.m_size;
            m_data=new CAD::Point[a.m_size];
            for(int i=0;i<a.m_size;i++)
            {
                m_data[i]=a.m_data[i];
            }
        }
        Array::~Array()         //destructor
        {
            delete[] m_data;
        }
        Array& Array::operator=(const Array &source)        //Assignment operator
        {
            if(this == &source)
            {
                return *this;
            }
            else{
                delete[] m_data;        //delete the internal C array before it is copied
                m_size=source.m_size;
                m_data=new CAD::Point[source.m_size];
                for(int i=0; i<source.m_size;i++)
                {
                    m_data[i]=source.m_data[i];
                }
                return *this;
            }

        }
        CAD::Point& Array::operator[](int index)         //add a square bracket opearator
        {
            if(index>m_size-1 || index<0)
            {
                throw OutOfBoundsException(index);
            }
            else{
                return m_data[index];
            }    
        }

        /*
        A const square bracket operaotr function ensures that the object can't be modified inside the function, 
        so it makes it safe to return a const reference of the CAD::Point object

        */
        const CAD::Point& Array::operator[] (int index) const       //const version of the square bracket operator
        {
            if(index>m_size-1 || index<0)
            {
                throw OutOfBoundsException(index);
            }
            else
            {
                return m_data[index];
            }
        }
        //Getter functions
        int Array::Size() const
        {
            return m_size;
        }
        CAD::Point& Array::GetElement(int index) const
        {
            if(index>m_size-1 || index<0)
            {
                throw OutOfBoundsException(index);
            }
            else
            {
                return m_data[index];
            }
        }
        //Setter function
        void Array::SetElement(int i, const CAD::Point &p)
        {
            if(i>m_size-1 || i<0)
            {
                throw OutOfBoundsException(i);
                // cout<<"Index out of bounds!"<<endl;
            }
            else
            {
                this->m_data[i] = p;
            }
        }

        //Implementation for class ArrayException
        ArrayException::ArrayException(){}
        ArrayException::~ArrayException(){}

        //Implementation for class OutOfBoundsException
        OutOfBoundsException::OutOfBoundsException() : ArrayException(),m_index(0){}
        OutOfBoundsException::OutOfBoundsException(int index) : ArrayException(), m_index(index){}
        OutOfBoundsException::~OutOfBoundsException(){}
        string OutOfBoundsException::GetMessage()
        {   stringstream ss;
            ss<<"Index "<<m_index<<" is out of bounds!";
            return ss.str();
        }


    }
}
