/*
IsSmaller.cpp
a class that checks if the input is smaller than a certain value
*/
#ifndef IsSmaller_CPP
#define IsSmaller_CPP
#include "IsSmaller.hpp"
#include <iostream>
using namespace std;

template <typename T>
IsSmaller<T>::IsSmaller() : m_compare(0){}

template <typename T>
IsSmaller<T>::IsSmaller(const T& value) : m_compare(value) {}

template <typename T>
IsSmaller<T>::IsSmaller(const IsSmaller<T>& source) : m_compare(source.m_compare) {}

template <typename T>
IsSmaller<T>& IsSmaller<T>::operator = (const IsSmaller<T>& source) 
{
    if (this==&source) return *this;
    m_compare=source.m_compare;
    return *this;
}

template <typename T> 
IsSmaller<T>::~IsSmaller() {}

template <typename T>
bool IsSmaller<T>::operator() (const T& t) const
{
    return ((t<m_compare) ? 1:0);
}
#endif