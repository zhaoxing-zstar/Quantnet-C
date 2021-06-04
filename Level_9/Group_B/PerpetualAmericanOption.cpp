/*
 * @Descripttion: 
 * @version: 
 * @Author: Zstar
 * @Date: 2021-05-27 22:45:09
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 23:03:14
 */
#include "PerpetualAmericanOption.hpp" 
#include "OptionExtras.hpp"
#include <string> 
#include <vector> 
using namespace std; 


// Price of call
double PerpetualAmericanOption::CallPrice() const
{ 

	return ::PerpetualCall(K, sig, r, U, b);
}

// Price of put
double PerpetualAmericanOption::PutPrice() const
{ 

	return ::PerpetualPut(K, sig, r, U, b);
}

// Initialise all default values
void PerpetualAmericanOption::Init()
{ 

	Option::Init();
	K = 100;
	sig = 0.1;
	r = 0.1;
	U = 110;
	b = r;
}
// Copy all values
void PerpetualAmericanOption::Copy(const PerpetualAmericanOption& source)
{ 

	Option::Copy(source);
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;
}
// Default constructor
PerpetualAmericanOption::PerpetualAmericanOption() : Option()
{ 

	Init();
}
// Copy constructor
PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : Option(source)
{ 

	Copy(source);
}
// Constructor with option type
PerpetualAmericanOption::PerpetualAmericanOption(const string& optionType) : Option(optionType)
{ 

	Init();
}


// Destructor
PerpetualAmericanOption::~PerpetualAmericanOption()
{ 
}

// Assignment operator
PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)
{ 

	Option::operator = (source);

	if (this == &source) //check if source is the same as this object 
	{
		return *this; // if same , directly return 
	}

	//assign the source member
	Option::Copy(source);
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;

	return *this; //return this object
}
