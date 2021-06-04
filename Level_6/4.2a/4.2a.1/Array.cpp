/*
Array.cpp
Implement memeber functions for Array class
*/

#include "Point.hpp"
#include "Array.hpp"
#include "Exception.hpp"
#include<iostream>
using namespace std;

#ifndef Array_CPP
#define Array_CPP

namespace zstar{

    namespace Containers{
        template <typename T>
        Array<T>::Array()      //Default constructor
        {
            m_size=10;      //default 10 elements
            m_data= new T[m_size];

        }

        template <typename T>
        Array<T>::Array(const int &array_len)      //overload constructor
        {
            m_size=array_len;
            m_data=new T[m_size];
        }

        template <typename T>
        Array<T>::Array(const Array<T>& a)        //copy constructor
        {
            m_size=a.m_size;
            m_data=new T[a.m_size];
            for(int i=0;i<a.m_size;i++)
            {
                m_data[i]=a.m_data[i];
            }
        }

        template <typename T>
        Array<T>::~Array()         //destructor
        {
            delete[] m_data;
        }

        template <typename T>
        Array<T>& Array<T>::operator=(const Array<T> &source)        //Assignment operator
        {
            if(this == &source)
            {
                return *this;
            }
            else{
                delete[] m_data;        //delete the internal C array before it is copied
                m_size=source.m_size;
                m_data=new T[source.m_size];
                for(int i=0; i<source.m_size;i++)
                {
                    m_data[i]=source.m_data[i];
                }
                return *this;
            }

        }

        template <typename T>
        T& Array<T>::operator[](int index)         //add a square bracket opearator
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
        so it makes it safe to return a const reference of the T object

        */

        template <typename T>
        const T& Array<T>::operator[] (int index) const       //const version of the square bracket operator
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
        template <typename T>
        int Array<T>::Size() const
        {
            return m_size;
        }
        template <typename T>
        T& Array<T>::GetElement(int index) const
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
        template <typename T>
        void Array<T>::SetElement(int i, const T &p)
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


    }
}


#endif
