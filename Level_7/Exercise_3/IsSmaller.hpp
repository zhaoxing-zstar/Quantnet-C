/*
IsSmaller.hpp
a class that checks if the input is smaller than a certain value
*/

#ifndef IsSmaller_HPP
#define IsSmaller_HPP
#include<iostream>

template <typename T>
class IsSmaller
{
private:
    T m_compare;
public:
    IsSmaller();        //default constructor
    IsSmaller(const T& value);      //overload constructor
    IsSmaller(const IsSmaller<T>& source);      //copt constructor
    IsSmaller<T>& operator = (const IsSmaller<T>& source);      //assignment operator
    ~IsSmaller();           //destructor

    bool operator() (const T& t)    const;       //overload () operator

};

#ifndef IsSmaller_CPP
#include "IsSmaller.cpp"
#endif

#endif