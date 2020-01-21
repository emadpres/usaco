/*
ID: emadpres1
TASK: skidesign
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    
    const int MAX_N = 1000, MAX_ELEVATION = 100;
    int N, elev[MAX_N];
    fin >> N;
    for (int i = 0; i < N; i++)
        fin >> elev[i];
    

    sort(elev, elev+N);
    int needToChange = elev[N-1]-elev[0]-17;
    if(needToChange<=0){
        fout << 0 <<endl;
        return 0;
    }
    
    int decreaseCostToHeight[MAX_ELEVATION+1] = {}, increaseCostToHeight[MAX_ELEVATION+1] = {};

    int i = 0;
    for(int h = elev[0]; h <= elev[N-1]; h++)
        for(int hill = 0; hill<N; hill++)
        {
            int cost = (elev[hill] - h) * (elev[hill] - h);
            if(elev[hill] - h>0)
                decreaseCostToHeight[h] += cost;
            else
                increaseCostToHeight[h] += cost;
        }

    // for(int h = elev[0]; h <= elev[N-1]; h++)
    //     fout << h <<" " << decreaseCostToHeight[h]<<" "<<increaseCostToHeight[h]<<endl;

    int min = -1;
    for(int i=0; i<=needToChange; i++)
    {
        int t = increaseCostToHeight[elev[0]+i] + decreaseCostToHeight[elev[N-1]-(needToChange-i)];
        if(min<0 || min > t)
            min = t;
    }
    fout << min << endl;

    fin.close();
    fout.close();
    return 0;
}