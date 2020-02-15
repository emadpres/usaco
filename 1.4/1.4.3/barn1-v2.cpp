/*
ID: emadpres1
TASK: barn1
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    const int N_STALL_MAX = 200;
    int maxBoard, nStall, nCow;
    bool stalls[N_STALL_MAX] = {}, covered[N_STALL_MAX] = {};
    
    fin >> maxBoard >> nStall >> nCow;
    int first=nStall, last=-1;
    for (int i = 0; i < nCow; i++)
    {
        int t;
        fin >> t;
        stalls[t-1] = true;
        if(t-1<first)
            first = t-1;
        if(t-1>last)
            last = t-1;
    }

    std::vector<int> emptyStreaks;
    int cur = first, streak = 0;
    while(cur++<=last)
    {
        if(stalls[cur]==false)
            streak++;
        else if(streak>0)
        {
            emptyStreaks.emplace_back(streak);
            streak = 0;
        }
    }

    sort(emptyStreaks.begin(), emptyStreaks.end(), [](int a, int b){return a>b;});

    int totalCovered = last-first+1;
    int usedBoard = 1;
    while(usedBoard < maxBoard && usedBoard-1 < emptyStreaks.size()){
        totalCovered -= emptyStreaks[usedBoard-1];
        usedBoard++;
    }

    fout << totalCovered << endl;
    
    
    return 0;
}