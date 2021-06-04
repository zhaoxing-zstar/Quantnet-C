/*
 * @Descripttion: test program for solutions of European options
 * @version: 1.0
 * @Author: Zstar
 */

#include "Option.hpp"
#include "OptionExtras.hpp"
#include "EuropeanOption.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef boost::tuple<double, double ,double, double,double> FiveParams;

int main()
{
    //Store Batch1 to Batch4 in a vector
    vector<FiveParams> vecBatch;
	// vecBatch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
	// vecBatch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	// vecBatch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	vecBatch.push_back(boost::make_tuple(1.45,120, 0.51, 0.045, 120));

    double T,K,sig,r,U,b;       //parameters
    double C,P;         //  call / put price

    int n=41;
    vector<double> vecU=GenerateMeshArray(10.0,50.0,n);
    vector<double> vecT=GenerateMeshArray(20,40,21);
    vector<double> vecSig=GenerateMeshArray(0.1,1.0,10);

    for(int i=0; i< vecBatch.size(); ++i)
    {   // A.1.a)
        // Use global functions
        T = vecBatch[i].get<0>();
        K = vecBatch[i].get<1>();
        sig= vecBatch[i].get<2>();
        r = vecBatch[i].get<3>();
        U = vecBatch[i].get<4>();
        b=r;
        cout<<endl;
        C=Call_Price(T,K,sig,r,U,b);
        P=Put_Price(T,K,sig,r,U,b);
        cout<<"Batch "<< i+1<<":"<<endl;
        cout<<"Use Option functions: ";
        cout<<" C= "<<C<<", P= "<<P<<endl;
        
        //Use instances of European class
        EuropeanOption option0;
        option0.T=T;
        option0.K=K;
        option0.sig=sig;
        option0.r=r;
        option0.U=U;
        option0.b=b;
        cout<<"Use instances of EuropeanOption class";
        cout <<  " : "  << " C = " << option0.Price() ;
		option0.toggle();
		cout << ", P = " << option0.Price() << endl;
        
        // A.1.b)
        // Use put-call Parity
        cout<<"Results from Put-Call parity";
        cout<<  " : "  << "C = " << option0.PutToCall(option0.Price()) ;
		option0.toggle();
		cout << ", P = " << option0.CallToPut(option0.Price()) << endl;
        option0.toggle();
        //Parity Check
        cout<<"Parity Check result: "<<option0.ParityChecker()<<endl;
    }

    //A.1.c) comput prices for a range of underlying value


    // cout<<"Computing prices for a range of underlying values: "<<endl;
    // for(int i=0; i< vecBatch.size(); ++i)
    // {
    //     T = vecBatch[i].get<0>();
    //     K = vecBatch[i].get<1>();
    //     sig= vecBatch[i].get<2>();
    //     r = vecBatch[i].get<3>();
    //     U = vecBatch[i].get<4>();
    //     b=r;
    //     EuropeanOption option1;
    //     option1.T=T;
    //     option1.K=K;
    //     option1.sig=sig;
    //     option1.r=r;
    //     option1.U=U;
    //     option1.b=b;
    //     cout<<"Batch "<<i+1<<": "<<endl;
    //     vector<double> vecC1,vecP1;
    //     for(int j=0;j<vecU.size();j++)
    //     {
    //         vecC1.push_back(option1.PriceWithS(vecU[j]));
    //         option1.toggle();
    //         vecP1.push_back(option1.PriceWithS(vecU[j]));
    //         option1.toggle();
    //     }
    //     for(int j=0; j< vecU.size();++j)
    //     {
    //         cout<<"S: "<<vecU[j]<<", C: "<<vecC1[j]<<", P: "<<vecP1[j]<<endl;
    //     }
        
    // }


    //A.1.d) compute option prices as a function of expiry time, volatility and any of the option
    //pricing parameters

    
    // cout<<"Computing prices for a range of expiry time: "<<endl;
    // for(int i=0; i< vecBatch.size(); ++i)
    // {
    //     T = vecBatch[i].get<0>();
    //     K = vecBatch[i].get<1>();
    //     sig= vecBatch[i].get<2>();
    //     r = vecBatch[i].get<3>();
    //     U = vecBatch[i].get<4>();
    //     b=r;
    //     EuropeanOption option1;
    //     option1.T=T;
    //     option1.K=K;
    //     option1.sig=sig;
    //     option1.r=r;
    //     option1.U=U;
    //     option1.b=b;
    //     cout<<"Batch "<<i+1<<": "<<endl;
    //     vector<double> vecC1,vecP1;
    //     for(int j=0;j<vecT.size();j++)
    //     {
    //         vecC1.push_back(option1.PriceWithT(vecT[j]));
    //         option1.toggle();
    //         vecP1.push_back(option1.PriceWithT(vecT[j]));
    //         option1.toggle();
    //     }
    //     for(int j=0; j< vecT.size();++j)
    //     {
    //         cout<<"T: "<<vecT[j]<<"\tC: "<<vecC1[j]<<"\tP: "<<vecP1[j]<<endl;
    //     }  
    // }

    // cout<<"Computing prices for a range of volatility: "<<endl;
    // for(int i=0; i< vecBatch.size(); ++i)
    // {
    //     T = vecBatch[i].get<0>();
    //     K = vecBatch[i].get<1>();
    //     sig= vecBatch[i].get<2>();
    //     r = vecBatch[i].get<3>();
    //     U = vecBatch[i].get<4>();
    //     b=r;
    //     EuropeanOption option1;
    //     option1.T=T;
    //     option1.K=K;
    //     option1.sig=sig;
    //     option1.r=r;
    //     option1.U=U;
    //     option1.b=b;
    //     cout<<"Batch "<<i+1<<": "<<endl;
    //     vector<double> vecC1,vecP1;
    //     for(int j=0;j<vecSig.size();j++)
    //     {
    //         vecC1.push_back(option1.PriceWithT(vecSig[j]));
    //         option1.toggle();
    //         vecP1.push_back(option1.PriceWithT(vecSig[j]));
    //         option1.toggle();
    //     }
    //     for(int j=0; j< vecSig.size();++j)
    //     {
    //         cout<<"Sigma: "<<vecSig[j]<<"\tC: "<<vecC1[j]<<"\tP: "<<vecP1[j]<<endl;
    //     }
    // }

    // cout<<"Computing prices for any of the option pricing parameters: "<<endl;
    // vector<double> vecr=GenerateMeshArray(0,0.5,11);
    // for(int i=0; i< vecBatch.size(); ++i)
    // {
    //     T = vecBatch[i].get<0>();
    //     K = vecBatch[i].get<1>();
    //     sig= vecBatch[i].get<2>();
    //     r = vecBatch[i].get<3>();
    //     U = vecBatch[i].get<4>();
    //     b=r;
    //     EuropeanOption option1;
    //     option1.T=T;
    //     option1.K=K;
    //     option1.sig=sig;
    //     option1.r=r;
    //     option1.U=U;
    //     option1.b=b;
    //     cout<<"Batch "<<i+1<<": "<<endl;
    //     vector<double> vecC1,vecP1;
    //     for(int j=0;j<vecSig.size();j++)
    //     {
    //         vecC1.push_back(option1.PriceWithAny(T,K,vecSig[j],vecr[j],U,b));
    //         option1.toggle();
    //         vecP1.push_back(option1.PriceWithAny(T,K,vecSig[j],vecr[j],U,b));
    //         option1.toggle();
    //     }
    //     for(int j=0; j< vecSig.size();++j)
    //     {
    //         cout<<"Sigma: "<<vecSig[j]<<"\tr:"<<vecr[j]<<"\tC: "<<vecC1[j]<<"\tP: "<<vecP1[j]<<endl;
    //     }
    // }

    /* A.2.a) Option Sensitivities */
    T=1.45;
    K=120;
    sig = 0.51;
    r = 0.045;
    U =108;
    b=0.0;

    cout<<"Delta and Gamma: "<<endl;
    cout<<"Delta of Call : "<<Call_Delta(T,K,sig,r,U,b) <<", Delta of Put: "<<Put_Delta(T,K,sig,r,U,b)<<endl;
    cout<<"Gamma of Call : "<<Call_Gamma(T,K,sig,r,U,b) <<", Gamma of Put: "<<Put_Gamma(T,K,sig,r,U,b)<<endl;
    
    EuropeanOption fOption;
	fOption.T = T;
	fOption.K = K;
	fOption.sig = sig;
	fOption.r = r;
	fOption.U = U;
	fOption.b = b;

    //A.2.b)
    // cout<<"Computing Delta for range of underlying values: "<<endl;
    // vector<double> vecCD, vecPD;
    // vector<double> vecUb=GenerateMeshArray(80,110,31);
    // for (int i=0;i<vecUb.size(); i++)
    // {   
    //     fOption.U=vecUb[i];
    //     vecCD.push_back(fOption.Delta());
    //     fOption.toggle();
    //     vecPD.push_back(fOption.Delta());
    //     fOption.toggle();
    // }
    // for (int i = 0; i < vecUb.size(); i++)
	// {
	// 	cout << "S = " << vecUb[i] << "\tDelta of Call = " << vecCD[i] << "\tDelta of Put = " << vecPD[i] << endl;
	// }
	// cout << endl;

    //A.2.c)
    // cout<<"Computing Delta for range of different Option Parameters: "<<endl;
    // vector<double> vecCD1, vecPD1;
    // vector<double> vecUb1=GenerateMeshArray(80,100,21);
    // vector<double> vecrb1=GenerateMeshArray(0.1,0.3,21);
    // for (int i=0;i<vecUb1.size(); i++)
    // {   
    //     fOption.U=vecUb1[i];
    //     fOption.r=vecrb1[i];
    //     vecCD1.push_back(fOption.Delta());
    //     fOption.toggle();
    //     vecPD1.push_back(fOption.Delta());
    //     fOption.toggle();
    // }
    // for (int i = 0; i < vecUb1.size(); i++)
	// {
	// 	cout << "S = " << vecUb1[i] <<"\tr="<<vecrb1[i]<< "\tDelta of Call = " << vecCD1[i] << "\tDelta of Put = " << vecPD1[i] << endl;
	// }
	// cout << endl;

    //  Use divided differences to approximate option sensitivities
    // vector<double> vecH = GenerateMeshArray(0.001, 1, 20);
	// for (int i = 0; i < vecH.size(); i++)
	// {
	// 	cout << "S = " << U << ", h = " << vecH[i] << ", Delta of Call = " << fOption.DeltaDiff(U, vecH[i]) << endl;
	// 	fOption.toggle();
	// 	cout << "S = " << U << ", h = " << vecH[i] << ", Delta of Put = " << fOption.DeltaDiff(U, vecH[i]) << endl;
    //     fOption.toggle();
	// }

	// for (int i = 0; i < vecH.size(); i++)
	// {
	// 	cout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Call = " << fOption.GammaDiff(U, vecH[i]) << endl;
	// 	fOption.toggle();
	// 	cout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Put = " << fOption.GammaDiff(U, vecH[i]) << endl;
	//     fOption.toggle();
	// }

	// Use divided differences for A.2.b)
	// vector<double> vecCDelta1, vecPDelta1;
	// for (int i = 0; i < vecU.size(); i++)
	// {
	// 	for (int j = 0; j < vecH.size(); j++)
	// 	{
	// 		vecCDelta1.push_back(fOption.DeltaDiff(vecU[i], vecH[j]));
	// 		fOption.toggle();
	// 		vecPDelta1.push_back(fOption.DeltaDiff(vecU[i], vecH[j]));
	// 		fOption.toggle();

	// 		cout << "S = " << vecU[i] << ", h = " << vecH[j] << ", Delta of Call = " << vecCDelta1[i + j] << ", Delta of Put = " << vecPDelta1[i + j] << endl;
	// 	}
	// }
}


