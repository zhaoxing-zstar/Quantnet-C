/*
simulate dice throwing
*/
#include<iostream>
#include<boost/random.hpp>
#include<map>

using namespace std;

int main()
{   
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;

    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);
    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome

    long num;
    cout<<"How many trials?";
    cin>>num;

    for(int i=0;i<=num;++i)
    {
        outcome = six(myRng);
        statistics[outcome]++;
    }

    for (int i=1;i<=6;i++){
        cout<<"Trial "<<i<<" has "<< (static_cast<double>(statistics[i])/num)*100<<"% outcomes"<<endl;
    }
    return 0;
}

/*  Output
How many trials? 1000000
Trial 1 has 16.6829% outcomes
Trial 2 has 16.6693% outcomes
Trial 3 has 16.587% outcomes
Trial 4 has 16.6045% outcomes
Trial 5 has 16.7324% outcomes
Trial 6 has 16.724% outcomes


*/