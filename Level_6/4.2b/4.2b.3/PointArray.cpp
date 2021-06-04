/*
PointArray.cpp
Implementation for PointArray class
*/
#ifndef PointArray_CPP
#define PointArray_CPP
#include "PointArray.hpp"
#include "Array.hpp"

#include<iostream>

namespace zstar{
    namespace Containers{
        //default constructor
        PointArray::PointArray() : Array(){}
        //overload constructor
        PointArray::PointArray(const int&array_len) : Array(array_len) {}
        //copy constructor
        PointArray::PointArray(const PointArray& source) : Array(source){}
        //assignment operator
        PointArray& PointArray::operator = (const PointArray& source)
        {
            if (this==&source) return *this;
            else{
                Array<Point>::operator = (source);
            }
            return *this;
        }
        //destructor
        PointArray::~PointArray() {}
        
        //calculate total length between points in the array
        double PointArray::Length() const
        {
            double total_len;
            for(int i=0;i!=(this->Size()-1);i++)
            {
                total_len+=(*this)[i].Distance((*this)[i+1]);
            }
            return total_len;
        }

    }
}

#endif