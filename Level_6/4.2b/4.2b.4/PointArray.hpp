/*
PointArray.hpp
header files for PointArray Class
Inherits (concrete inheritance) from base class
*/

#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.hpp"
using zstar::CAD::Point;
using namespace std;
#include<iostream>

namespace zstar{
    namespace Containers{
        class PointArray: public Array<Point>
        {
        public:
            PointArray();       //default constructor
            PointArray(const int &array_len);        //overload constructor
            PointArray(const PointArray& source);       //copy constructor
            PointArray& operator = (const PointArray& source);      //assignment operator
            virtual ~PointArray();      //destructor

            double Length() const;      // return the total length between the points in the array
        };
    }
}


#endif