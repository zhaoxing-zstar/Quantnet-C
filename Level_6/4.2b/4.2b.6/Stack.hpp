/*
Stack.hpp
header file for stack class
use the Array class as a data member
use an int value as template variable
*/
#ifndef Stack_HPP
#define Stack_HPP
#include "Array.hpp"
#include<iostream>
using namespace std;
namespace zstar{
    namespace Containers
    {   
        template <typename T, int size>
        class Stack
        {
        private:
            int m_current;
            Array<T> m_array;

        public:
            Stack();       //default constructor
            Stack(const int &array_len);        //overload constructor
            Stack(const Stack<T, size>& source);       //copy constructor
            Stack<T,size>& operator = (const Stack<T,size>& source);      //assignment operator
            virtual ~Stack();      //destructor

            void Push(T element);       //store the element at the current position in the embedded array
            T Pop();        //decrements the current position and then returns the element at that position
        };
    }
}

#ifndef Stack_CPP
#include "Stack.cpp"
#endif

#endif