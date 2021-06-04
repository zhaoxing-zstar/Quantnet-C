/*
 * @Descripttion: Source file for EuropeanOption
 * @version: 1.0
 * @Author: Zstar
 * @Date: 2021-05-26 20:58:37
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 20:13:09
 */



#include "EuropeanOption.hpp"
#include "OptionExtras.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>
using namespace std;


double EuropeanOption::CallPrice() const
{
	return Call_Price(T,K,sig,r,U,b);
}
double EuropeanOption::PutPrice() const
{ 

	return Put_Price(T, K, sig, r, U, b);
}
double EuropeanOption::CallDelta() const
{ 
	return Call_Delta(T, K, sig, r, U, b);
}
double EuropeanOption::PutDelta() const
{ 

	return Put_Delta(T, K, sig, r, U, b);
}
double EuropeanOption::CallGamma() const
{ 

	return Call_Gamma(T, K, sig, r, U, b);
}
double EuropeanOption::PutGamma() const
{ 

	return Put_Gamma(T, K, sig, r, U, b);
}
double EuropeanOption::CallVega() const
{ 

	return Call_Vega(T, K, sig, r, U, b);
}
double EuropeanOption::PutVega() const
{ 

	return Put_Vega(T, K, sig, r, U, b);
}
double EuropeanOption::CallTheta() const
{ 

	return Call_Theta(T, K, sig, r, U, b);
}
double EuropeanOption::PutTheta() const
{ 

	return Put_Theta(T, K, sig, r, U, b);
}
/////////////////////////////////////////////////////////////////////////////////////

void EuropeanOption::Init()
{	// Initialise all default values

	Option::Init();
	// Default values
	r = 0.05;
	sig= 0.2;
	K = 110.0;
	T = 0.5;
	U=60;
	b = r;			// Black and Scholes stock option model (1973)
}

void EuropeanOption::Copy( const EuropeanOption& o2)
{
	Option::Copy(o2);
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	U = o2.U;
	
}

EuropeanOption::EuropeanOption() : Option()
{ // Default call option
	Init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2) : Option(o2)
{ // Copy constructor

	Copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType) : Option(optionType)
{	// Create option type

	Init();
}
//Destructor
EuropeanOption::~EuropeanOption()
{

}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{//Assignment operator

	if (this == &option2) return *this;

	Copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::CallToPut(double c) const
{
	return c+K*exp(-r * T) - U;
}
double EuropeanOption::PutToCall(double p) const
{
	return p-K*exp(-r * T) + U;
}
//use underlying price as argument
double EuropeanOption::PriceWithS(double newU) const
{
	if (OptionType=="Call")
	{	
		return Call_Price(T,K,sig,r,newU,b);
	}
	else
	{
		return Put_Price(T, K, sig, r, newU, b);
	}
}
//use expiry time as argument
double EuropeanOption::PriceWithT(double newT) const
{
	if (OptionType=="Call")
	{
		return Call_Price(newT,K,sig, r,U,b);
	}
	else
	{
		return Put_Price(newT,K,sig,r,U,b);
	}
}
//use volatility as argument
double EuropeanOption::PriceWithSig(double newSig) const
{
	if (OptionType=="Call")
	{
		return Call_Price(T,K,newSig, r,U,b);
	}
	else
	{
		return Put_Price(T,K,newSig,r,U,b);
	}
}
//use any argument as arguments
double EuropeanOption::PriceWithAny(double T, double K, double sig, double r, double U, double b) const
{
	if (OptionType=="Call")
	{
		return Call_Price(T,K,sig, r,U,b);
	}
	else
	{
		return Put_Price(T,K,sig,r,U,b);
	}
}
double	EuropeanOption::DeltaDiff(double U, double h) const
{
	return (PriceWithS(U + h)-PriceWithS(U-h)) / (2.0*h);
}
double EuropeanOption::GammaDiff(double U, double h) const
{
	return (PriceWithS(U+h)-2.0*PriceWithS(U)+PriceWithS(U-h))/(h*h);
}
bool EuropeanOption::ParityChecker(double tol) const
{	
	return (abs(PutPrice()-CallToPut(CallPrice()))<tol);
}



