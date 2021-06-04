/*
 * @Descripttion: Implement fucntiond for Option class
 * @version: 
 * @Author: Zstar
 * @Date: 2021-05-27 08:45:43
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 18:04:10
 */
#include "Option.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

void Option::Init()
{
    OptionType= "Call";
}
void Option::Copy(const Option& o2)
{
    OptionType=o2.OptionType;
}
Option::Option()
{
    Init();
}
Option::Option(const Option& op)
{
    OptionType=op.OptionType;
}
Option::Option(const string& Optiontype)
{
    OptionType=Optiontype;
}
Option::~Option(){}
Option& Option::operator = (const Option& op)
{
    if (this==&op)
    {
        return (*this);
    }
    Copy(op);
    return (*this);
}
void Option::toggle()
{
    OptionType=((OptionType=="Call")? "Put" : "Call");
}
// Functions that calculate option prices and sensitivities
double Option::Price() const
{
	if (OptionType == "Call")
	{
		return CallPrice();
	}
	else
	{
		return PutPrice();
	}
}

double Option::Delta() const
{
	if (OptionType == "Call")
	{
		return CallDelta();
	}
	else
	{
		return PutDelta();
	}
}

double Option::Gamma() const
{
	if (OptionType == "Call")
	{
		return CallGamma();
	}
	else
	{
		return PutGamma();
	}
}

double Option::Vega() const
{
	if (OptionType == "Call")
	{
		return CallVega();
	}
	else
	{
		return PutVega();
	}
}

double Option::Theta() const
{
	if (OptionType == "Call")
	{
		return CallTheta();
	}
	else
	{
		return PutTheta();
	}
}


