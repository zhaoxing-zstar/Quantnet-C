/*
Stack.cpp
Implementation for Stack class
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
        template <typename T>
        Stack<T>::Stack() : m_array(Array<T>()), m_current(0) {}
        
        //overload constructor
        template <typename T>
        Stack<T>::Stack(const int& array_len) : m_array(Array<T>(array_len)), m_current(0) {}

        //copy constructor
        template <typename T>
        Stack<T>::Stack(const Stack<T>& source) : m_array(source.m_array), m_current(source.m_current) {}

        //assignment operator
        template <typename T>
        Stack<T>& Stack<T>::operator = (const Stack<T>& source)
        {
            if(this==&source) return *this;
            else{
                m_array=source.m_array;
                m_current=source.m_current;
            }
            return *this;
        }

        //destructor
        template <typename T>
        Stack<T>::~Stack() {}

        //Push function
        template <typename T>
        void Stack<T>::Push(T element)
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
        template <typename T>
        T Stack<T>::Pop()
        {   
            try
            {
                return m_array[--m_current];
            }
            catch(ArrayException&)
            {
                throw StackEmptyException();
                m_current=0;
            }
            catch(...)
            {
                cout<<"An unknown error happened!"<<endl;
            }
        }
    }
}
#endif