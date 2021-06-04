/*
Array.hpp
header files for Array Class
*/
#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
#include<iostream>
using namespace std;


class Array
{
private:
    Point *m_data;
    int m_size;
public:
    Array();        //Default constructor
    Array(const int &array_len);        //overload constructor
    Array(const Array &a);          //copy constructor
    ~Array();       //Destructor

    Array& operator = (const Array &source);    //Assignment operator
    Point& operator [] (int index);         //add a square bracket operator
    const Point& operator [] (int index) const;         //const version of the square bracket operator

    //Getter functions
    int Size() const;
    Point& GetElement(int index) const; 

    //Setter function
    void SetElement(int i, const Point &p);


};
#endif