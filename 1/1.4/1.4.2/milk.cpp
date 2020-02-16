/*
ID: emadpres1
TASK: milk
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Seller {
    int price, available;
};

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    
    const int N_FARMER_MAX = 5000;
    Seller sellers[N_FARMER_MAX];
    int totalNeed, nFarmer;

    fin >> totalNeed >> nFarmer;
    for(int i=0; i<nFarmer; i++)
        fin >> sellers[i].price >> sellers[i].available;

    sort(sellers, sellers+nFarmer, [](Seller a, Seller b){return a.price < b.price;} );

    int remaining = totalNeed, pay = 0;
    for(int i=0; i<nFarmer; i++)
    {
        if(sellers[i].available < remaining)
        {
            remaining -= sellers[i].available;
            pay += sellers[i].available*sellers[i].price;
        }
        else
        {
            pay += remaining*sellers[i].price;
            break;
        }   
    }
    

    fout << pay << endl;

    return 0;
}