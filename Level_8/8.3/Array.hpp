/*
Array.hpp
header files for Array Class
*/
#ifndef Array_HPP
#define Array_HPP

#include<iostream>
using namespace std;

namespace zstar{

    namespace Containers{
        template <typename T>
        class Array
        {
        private:
            T* m_data;
            int m_size;
            static int df_size;         //default size of the array
        public:
            Array();        //Default constructor
            Array(const int &array_len);        //overload constructor
            Array(const Array<T> &a);          //copy constructor
            ~Array();       //Destructor

            Array<T>& operator = (const Array<T> &source);    //Assignment operator
            T& operator [] (int index);         //add a square bracket operator
            const T& operator [] (int index) const;         //const version of the square bracket operator

            //Getter functions
            int Size() const;
            T& GetElement(int index) const; 
            static int DefaultSize();

            //Setter function
            void SetElement(int i, const T &p);
            static void DefaultSize(int df_sz);


        };

    }
}

#ifndef Array_CPP
#include "Array.cpp"
#endif 

#endif