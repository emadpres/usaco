/*
ID: emadpres1
TASK: combo
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <tuple>

using namespace std;

namespace std {
    template <typename T1, typename T2, typename T3>
    struct hash<tuple<T1, T2, T3>>
    {
        size_t operator() (const tuple<T1, T2, T3> &t) const 
        {
            const auto h1 = std::hash<T1>()(std::get<0>(t));
            const auto h2 = std::hash<T2>()(std::get<1>(t));
            const auto h3 = std::hash<T3>()(std::get<2>(t));

            return h1 ^ (h2<<1) ^ (h3<<2);
        }
    };
}


int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    int max, farmer[3], master[3];
    fin >> max;
    fin >> farmer[0] >> farmer[1] >> farmer[2];
    fin >> master[0] >> master[1] >> master[2];

    unordered_set<tuple<int,int,int>> settings;
    for(int i=-2; i<=2; i++)
        for(int j=-2; j<=2; j++)
            for(int k=-2; k<=2; k++)
            {
                int a = (farmer[0]+i-1+50)%max+1;
                int b = (farmer[1]+j-1+50)%max+1;
                int c = (farmer[2]+k-1+50)%max+1;
                settings.insert(make_tuple(a,b,c));

                a = (master[0]+i-1+50)%max+1;
                b = (master[1]+j-1+50)%max+1;
                c = (master[2]+k-1+50)%max+1;
                settings.insert(make_tuple(a,b,c));
            }

    fout << settings.size() << endl;

    return 0;
}