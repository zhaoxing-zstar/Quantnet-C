/*
Array.hpp
header files for ArrayException base class,
 OutOfBoundsException derived class.
 and Dimension Exception class
*/

#include<iostream>
#include<sstream>
using namespace std;

// header files for ArrayException class
#ifndef ARRAYEXCEPTION
#define ARRAYEXCEPTION
namespace zstar{
    namespace Containers{
        class ArrayException
        {
        private:

        public:
            ArrayException();       //constructor
            virtual ~ArrayException();

            virtual string GetMessage()=0;      //abstract function GetMessage()

        };
    }
}
#endif

//header files for OutOfBoundsException
#ifndef OUTOFBOUNDS
#define OUTOFBOUNDS
namespace zstar{
    namespace Containers{
        class OutOfBoundsException : public ArrayException
        {
        private:
            int m_index;
        public:
            OutOfBoundsException();
            OutOfBoundsException(int index);
            ~OutOfBoundsException();

            string GetMessage();
        };
    }
}
#endif

// header files for DimensionException
#ifndef DIMEXCEPTION
#define DIMEXCEPTION
namespace zstar{
    namespace Containers{
        class DimensionException : public ArrayException
        {
        private:

        public:
            DimensionException();
            ~DimensionException();

            string GetMessage();        //override GetMessage function
        };
    }
}
#endif