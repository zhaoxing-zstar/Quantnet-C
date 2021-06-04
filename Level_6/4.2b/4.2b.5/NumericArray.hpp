/*
NumericArray.hpp
header files for NumericArray class
Numeric functionality can then be put in this class which itself is also a template (generic inheritance) 

*/
#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"
#include<iostream>

namespace zstar{
    namespace Containers{
        template <typename T>
        class NumericArray:public Array<T>
        {
        public:
            NumericArray();         //default constructor
            NumericArray(const int& array_len);             //overload constructor
            NumericArray(const NumericArray<T>& source);        //copy constructor
            ~NumericArray();        //destructor

            NumericArray<T>& operator = (const NumericArray<T>& source);        //Assignment operator
            NumericArray<T> operator + (const NumericArray<T>& na) const;       //An operator + to add the elements of two numeric arrays. 
            NumericArray<T> operator * (T factor) const;       //An operator * to scale the elements of the numeric array by a factor
            T DotProduct(const NumericArray<T>& na);        //dot-product
        };
    }
}

#ifndef NumericArray_CPP

#include "NumericArray.cpp"
#endif


#endif