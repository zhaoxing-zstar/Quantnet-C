/*
Stack.cpp
Implementation for Stack class
use an int value as template variable
*/
#ifndef Stack_CPP
#define Stack_CPP
#include "Stack.hpp"
#include "StackException.hpp"
#include<iostream>
using namespace std;

namespace zstar{
    namespace Containers{

        //default constructor
        template <typename T, int size>
        Stack<T, size>::Stack() : m_array(size), m_current(0) {}
        
        //copy constructor
        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& source) : m_array(source.m_array), m_current(source.m_current) {}

        //assignment operator
        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
        {
            if(this==&source) return *this;
            else{
                m_array=source.m_array;
                m_current=source.m_current;
            }
            return *this;
        }

        //destructor
        template <typename T, int size>
        Stack<T, size>::~Stack() {}

        //Push function
        template <typename T, int size>
        void Stack<T, size>::Push(T element)
        {   try
            {
                m_array[m_current]=element;
                m_current++;
            }
            catch(ArrayException&)
            {
                throw StackFullException();
            }
            catch(...)
            {
                cout<<"An unknown error happened!"<<endl;
            }
        }

        //Pop function
        template <typename T, int size>
        T Stack<T, size>::Pop()
        {   
            try
            {
                return m_array[--m_current];
            }
            catch(ArrayException&)
            {   
                m_current=0;
                throw StackEmptyException();
            }
            catch(...)
            {
                cout<<"An unknown error happened!"<<endl;
            }
        }
    }
}
#endif