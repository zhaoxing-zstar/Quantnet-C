/*
 * @Descripttion: header files for EuropeanOption class
 * @version: 1.0
 * @Author: Zstar
 * @Date: 2021-05-26 20:58:37
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 21:33:50
 */


#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "Option.hpp"
#include <string>
#include <vector>
using namespace std;

class EuropeanOption : public Option
{
private:		

	void Init();	// Initialise all default values
	void Copy(const EuropeanOption& o2);

	// 'Kernel' functions for option calculations
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
	double CallVega() const;
	double PutVega() const;
	double CallGamma() const;
	double PutGamma() const;
	double CallTheta() const;
	double PutTheta() const;

public:

	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double U; 		// Current price of the underlying asset
	double b;		// Cost of carry


public:	// Public functions
	EuropeanOption();							// Default call option
	EuropeanOption(const EuropeanOption& option2);	// Copy constructor
	EuropeanOption (const string& optionType);	// Create option type
	virtual ~EuropeanOption();	

	EuropeanOption& operator = (const EuropeanOption& option2);

	double CallToPut(double c) const; // Use put-call parity to calculate put price
	double PutToCall(double p) const; // Use put-call parity to calculate call price
	double PriceWithS(double newU) const; // Use underlying price as argument
	double PriceWithT(double newT) const; // Use expiry time as argument
	double PriceWithSig(double newSig) const; // Use volatility as argument
	double PriceWithAny(double T, double K, double sig, double r, double U, double b) const; // Use any parmeters as argument
	double DeltaDiff(double U, double h) const; // Use divided differences to calculate Delta
	double GammaDiff(double U, double h) const; // Use divided differences to calculate Gamma

	bool ParityChecker(double tol=0.00001) const;		//check if a given set of put/call prices satisfy parity

	// Parameters vectors function
	vector <double> ParameterArray() const;
};


#endif