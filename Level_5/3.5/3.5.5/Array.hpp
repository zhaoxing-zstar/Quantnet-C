/*
Array.hpp
header files for Array Class
*/
#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
#include<iostream>
using namespace std;

namespace zstar{

    namespace Containers{
        class Array
        {
        private:
            CAD::Point *m_data;
            int m_size;
        public:
            Array();        //Default constructor
            Array(const int &array_len);        //overload constructor
            Array(const Array &a);          //copy constructor
            ~Array();       //Destructor

            Array& operator = (const Array &source);    //Assignment operator
            CAD::Point& operator [] (int index);         //add a square bracket operator
            const CAD::Point& operator [] (int index) const;         //const version of the square bracket operator

            //Getter functions
            int Size() const;
            CAD::Point& GetElement(int index) const; 

            //Setter function
            void SetElement(int i, const CAD::Point &p);


        };
        #endif
    }
}