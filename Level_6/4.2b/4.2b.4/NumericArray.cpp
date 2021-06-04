/*
NumericArray.cpp
Implement functions for NumericArray class
(generic inheritance)
*/
#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "Exception.hpp"
#include<iostream>
using namespace std;

namespace zstar{
    namespace Containers{
        //default constructor
        template <typename T>
        NumericArray<T>::NumericArray() : Array<T>(){}

        //overload constructor
        template <typename T>
        NumericArray<T>::NumericArray(const int &array_len) : Array<T>(array_len){}

        //copy constructor
        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source){}

        //destructor
        template <typename T>
        NumericArray<T>::~NumericArray() {}

        //Assignment operator
        template <typename T>
        NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
        {
            if(this==&source) return *this;
            else{
                Array<T>::operator = (source);
            }
            return *this;
        }
        //An operator * to scale the elements of the numeric array by a factor
        template <typename T>
        NumericArray<T> NumericArray<T>::operator * (T factor) const
        {
            NumericArray<T> Scale(this->Size());
            for(int i=0;i!=(*this).Size();i++)
            {
                Scale[i]=factor*(*this)[i];
            }
            return Scale;
        }
        //An operator + to add the elements of two numeric arrays.
        template <typename T>
        NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& na) const
        {
            if((this->Size())!= na.Size())
            {
                throw DimensionException();
            }
            else
            {
                NumericArray<T> sumarray((*this).Size());

                for(int i=0; i!=(*this).Size();i++)
                {
                    sumarray[i]=(*this)[i]+na.GetElement(i);
                }
                return sumarray;
            }
        }
        //the dot product of two NumericArray
        template <typename T>
        T NumericArray<T>::DotProduct(const NumericArray<T>& na)
        {
            if(this->Size()!=na.Size())
            {
                throw DimensionException();
            }
            else
            {
                T DotProduct = 0;
                for(int i=0; i!=(*this).Size();i++)
                {
                    DotProduct = DotProduct + ((*this)[i] * na.GetElement(i));
                }

                return DotProduct;
            }
        }

        

    }
}

#endif
