
/*
 * @Descripttion: test program for solutions of European options
 * @version: 1.0
 * @Author: Zstar
 */

#include "Option.hpp"
#include "OptionExtras.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// The function prints out two columns of title1, title2, title 3
void PrintMesh(const vector<double>& mesh, const vector<double>& c_price, const vector<double>& p_price, string title1, string title2, string title3)
{
	cout << title1 << "\t" << title2 <<"\t"<<title3<< endl;
	for (int i = 0; i < mesh.size(); i++)
		cout << mesh[i] << "\t" << c_price[i] <<"\t"<<p_price[i]<< endl;
}

//The function prints out a matrix
void PrintMatrix(const vector<vector<double>>& mx, const vector<double>& var, string title)
{
	// Print the title for the output columns	
	cout <<"K"<<"\t"<< "sigma" << "\t"
		<< "r" << "\t" << "S" << "\t" << "b" << "\t" << title << "\t" << endl;

	for (int i = 0; i < mx.size(); i++)
	{
		for (vector<double>::const_iterator itr = mx[i].begin(); itr != mx[i].end(); itr++)
			cout << *itr << "\t";

		cout << var[i] << endl;
	}
		
}
// A matrix receive a parameters vector and return the (K, sig, r, U, b) parameter matrix.
std::vector<vector<double>> PerpetualMatrix(const PerpetualAmericanOption& opt, string type, const vector<double>& var_arr)
{
	// Get the parameters for opt
	vector<double> parameter;
    parameter.push_back(opt.K);
    parameter.push_back(opt.sig);
    parameter.push_back(opt.r);
    parameter.push_back(opt.U);
    parameter.push_back(opt.b);
	
	int j;

	// The final matrix to be returned
	vector <vector <double>> am_mx;

	// Pinpoint the position of the parameter that we want to modify
	if (type == "K")
		j = 0;
	else if (type == "sig")
		j = 1;
	else if (type == "r")
		j = 2;
	else if (type == "U")
		j = 3;
	else if (type == "b")
		j = 4;
	else
	{
		cout << "The parameter type is not found. An empty matrix has been returned.\n";
		return am_mx;
	}

	// Create the matrix with varying values for the parameter
	for (int i = 0; i < var_arr.size(); i++)
	{
		parameter[j] = var_arr[i];
		am_mx.push_back(parameter);
	}

	return am_mx;
}
int main()
{
    // B. Perpetual American Options
	// a) and b)
	PerpetualAmericanOption PAOption;
    PAOption.K=100;
    PAOption.sig=0.1;
    PAOption.r=0.1;
    PAOption.U=110;
    PAOption.b=0.02;

	cout << "PerpetualAmericanOption: " << endl;
	cout << "Call Price: " << PAOption.Price() << endl;
	PAOption.toggle();
	cout << "Put Price: " << PAOption.Price() << endl;
	PAOption.toggle();
	cout << endl << endl;

	// c)

	// Create a price mesh from 100 to 120
	// vector<double> PA_mesh = GenerateMeshArray(100, 120, 20);

	// vector<double> PA_C_Prices, PA_P_Prices;
	// for (int i=0;i<PA_mesh.size();i++)
	// {	
	// 	PAOption.U=PA_mesh[i];
	// 	PA_C_Prices.push_back(PAOption.Price());
	// 	PAOption.toggle();
	// 	PA_P_Prices.push_back(PAOption.Price());
	// 	PAOption.toggle();
	// }
	// cout << "PAOption:" << endl;
	// PrintMesh(PA_mesh, PA_C_Prices,PA_P_Prices, "S", "Call Price","Put Price");

	// cout << endl << endl;

	// // d)
	// vector<double> PA_r_mesh =GenerateMeshArray(0.1,0.3,20);
	// vector<vector<double>> Matrix_K = PerpetualMatrix(PAOption, "K", PA_mesh);
	// vector<vector<double>> Matrix_r = PerpetualMatrix(PAOption, "r", PA_r_mesh);
	// for (int j=0;j<Matrix_K.size();j++)
	// {
	// 	Matrix_K[j][2]=Matrix_r[j][2];
	// }
	// vector<double> Matrix_Price;
	// for (int i=0; i<Matrix_K.size();i++)
	// {	
	// 	Matrix_Price.push_back(PerpetualCall(Matrix_K[i][0],Matrix_K[i][1],Matrix_K[i][2],Matrix_K[i][3],Matrix_K[i][4]));
	// }
	// PrintMatrix(Matrix_K, Matrix_Price, "Price");
	
	// return 0;
}


