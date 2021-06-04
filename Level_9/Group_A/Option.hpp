/*
 * @Descripttion: Option.hpp Base class for options
 * @version: 1.0
 * @Author: Zstar
 * @Date: 2021-05-26 23:06:07
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 23:30:21
 */

#ifndef Option_hpp
#define Option_hpp
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;
class Option
{   
private:
	virtual double CallPrice() const = 0; // Price of call
	virtual double PutPrice() const = 0; // Price of put
	virtual double CallDelta() const =0 ; // Delta of call
	virtual double PutDelta() const = 0; // Delta of put
	virtual double CallGamma() const = 0; // Gamma of call
	virtual double PutGamma() const = 0 ; // Gamma of put
	virtual double CallVega() const = 0; // Vega of call
	virtual double PutVega() const = 0; // Vega of put
	virtual double CallTheta() const = 0; // Theta of call
	virtual double PutTheta() const = 0; // Theta of put
public:
    Option();       //Constructor
    Option(const Option& op);       //copy constructor
    Option(const string& Optiontype);       //Option type
    virtual ~Option();          //virtual destructor

    Option& operator = (const Option &op);      //assignment operator

    string OptionType;          //Option name (Put,call)
public:

    void Init();	// Initialise all default values
	void Copy(const Option& o2);
    
    // Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;
    double Vega() const;
    double Gamma() const;
    double Theta() const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

};


#endif








