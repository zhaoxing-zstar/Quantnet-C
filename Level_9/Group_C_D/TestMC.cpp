// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "../UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "../UtilitiesDJD/Geometry/Range.cpp"
#include "../UtilitiesDJD/RNG/NormalGenerator.cpp"
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


template <class T> void print(const vector<T>& myList)
{  // A generic print function for vectors
	
	cout << endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	typename vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			cout << *i << ",";

	}

	cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace
template <typename T>
double SD(const vector<T>& prices, T r, T expiryT)
{// compute SD
	long M = prices.size();
	T CTj_sum(0);
	T CTj_2_sum(0);
	for(long i=0;i<M;i++)
	{
		CTj_sum+=prices[i];
		CTj_2_sum+=prices[i]*prices[i];
	}

	return sqrt((CTj_2_sum-(CTj_sum * CTj_sum)/ M)/(M-1.0)) * exp(-r*expiryT);
}

template <typename T>
double SE(const vector<T>& prices, T r, T expiryT)
{
	return SD(prices, r, expiryT) / sqrt(prices.size());
}



int main()
{
	cout <<  "1 factor MC with explicit Euler\n";
	// //Batch 1
	// OptionData myOption;
	// myOption.K = 65.0;
	// myOption.T = 0.25;
	// myOption.r = 0.08;
	// myOption.sig = 0.3;
	// myOption.type = 1;	// Put -1, Call +1
	// double S_0 = 60;

	// double actual_call = 2.13337;
	// double actual_put = 5.84628;

	// //Batch 2
	// OptionData myOption;
	// myOption.K = 100.0;
	// myOption.T = 1.0;
	// myOption.r = 0.0;
	// myOption.sig = 0.2;
	// myOption.type = 1;	// Put -1, Call +1
	// double S_0 = 100;

	// double actual_call = 7.96557;
	// double actual_put = 7.96557;

	//Batch 4
	OptionData myOption;
	myOption.K = 100.0;
	myOption.T = 30.0;
	myOption.r = 0.08;
	myOption.sig = 0.3;
	myOption.type = 1;	// Put -1, Call +1
	double S_0 = 100;

	double actual_call = 92.17570;
	double actual_put = 1.24750;
	
	vector<long> N_list={1000};
	vector<long> NSim_list={1000000};

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	ofstream os;
	os.open("MC_Output.csv");
	os << "N,NSim,Call Price,Call Error,Call SD,Call SE,Put Price,Put Error,Put SD,Put SE\n";

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	for(int l=0; l<N_list.size();l++)
	{	//Loop the N_list (NT: Numer of time steps)
		vector<double> x = range.mesh(N_list[l]);
		double k = myOption.T / double (N_list[l]);
		double sqrk = sqrt(k);
		for (int j=0;j<NSim_list.size();j++)
		{	//Loop the NSim_list
			int coun=0; //Number of times S his orgin

			vector<double> Ctj; 		//Stores the prices in each iteration
			// Normal random number
			double dW;
			double price = 0.0;	// Option price


			for (long i = 1; i <= NSim_list[j]; ++i)
			{ // Calculate a path at each iteration
				double VOld=S_0;
				double VNew;
					
				if ((i/10000) * 10000 == i)
				{// Give status after each 1000th iteration

						cout << i << endl;
				}

				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index)
				{

					// Create a random number
					dW = myNormal->getNormal();
						
					// The FDM (in this case explicit Euler)
					VNew = VOld  + (k * drift(x[index-1], VOld))
								+ (sqrk * diffusion(x[index-1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}
					
				double tmp = myOption.myPayOffFunction(VNew);
				price += (tmp)/double(NSim_list[j]);

				Ctj.push_back(tmp);
			}
			price *= exp(-myOption.r * myOption.T);
			cout << "Price, after discounting: " << price << ", " << endl;
			cout << "Number of times origin is hit: " << coun << endl;

			os << N_list[l] << "," << NSim_list[j] << "," << price << "," << abs(price - actual_call) << ","
				<< SD<double>(Ctj, myOption.r, myOption.T) << "," << SE<double>(Ctj, myOption.r, myOption.T) << ",";
			
			//next, compute the put option prices
			myOption.type=-1;
			coun=0;
			price=0.0;
			Ctj.clear();		
			for (long i = 1; i <= NSim_list[j]; ++i)
			{ // Calculate a path at each iteration
				double VOld=S_0;
				double VNew;
					
				if ((i/10000) * 10000 == i)
				{// Give status after each 1000th iteration

						cout << i << endl;
				}

				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index)
				{

					// Create a random number
					dW = myNormal->getNormal();
						
					// The FDM (in this case explicit Euler)
					VNew = VOld  + (k * drift(x[index-1], VOld))
								+ (sqrk * diffusion(x[index-1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}
					
				double tmp = myOption.myPayOffFunction(VNew);
				price += (tmp)/double(NSim_list[j]);

				Ctj.push_back(tmp);
			}
			price *= exp(-myOption.r * myOption.T);
			cout << "Price, after discounting: " << price << ", " << endl;
			cout << "Number of times origin is hit: " << coun << endl;

			os <<  price << "," << abs(price - actual_put) << ","
				<< SD<double>(Ctj, myOption.r, myOption.T) << "," << SE<double>(Ctj, myOption.r, myOption.T) << endl;
			myOption.type=1;
		}
	}

	os.close();

	return 0;
}