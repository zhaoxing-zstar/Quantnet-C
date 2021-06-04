/*
Exception.cpp
Implement functions for ArrayException and OutOfBoundsException class
*/

#include<iostream>
#include<sstream>
using namespace std;
#include "Exception.hpp"


namespace zstar{
    namespace Containers{

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
