/*
 * @Descripttion: header file for PerpetualAmericanOption Class
 * @version: 1.0
 * @Author: Zstar
 * @LastEditors: Zstar
 */
#ifndef PerpetualAmericanOption_hpp
#define PerpetualAmericanOption_hpp

#include "Option.hpp"
#include <string>
#include <vector>
using namespace std;

class PerpetualAmericanOption : public Option
{
private:
	double CallPrice() const; 
	double PutPrice() const; 
	void Init(); 
	void Copy(const PerpetualAmericanOption& source); // Copy all values

public:
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry

	//public functionality
public:
	PerpetualAmericanOption(); // Default constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source); // Copy constructor
	PerpetualAmericanOption(const string& optionType); // Constructor with option type
	virtual ~PerpetualAmericanOption(); // Destructor

	// Assignment operator
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);


};


#endif

