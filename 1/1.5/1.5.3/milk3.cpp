/*
ID: emadpres1
TASK: milk3
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

const int MAX_N = 20;
std::set<int> possibleCValues;
bool visited[MAX_N][MAX_N][MAX_N]={false};
int CAP[3];

int pour(int cur[3], int from, int to)
{
    int to_pour = std::min(cur[from], CAP[to]-cur[to]);
    cur[from] -= to_pour;
    cur[to] += to_pour;
    return to_pour;
}

int pour(int cur[3], int from, int to, int amount)
{
    cur[from] -= amount;
    cur[to] += amount;
}

void calc(int cur[3])
{
    
    if(visited[cur[0]][cur[1]][cur[2]])
        return;
    visited[cur[0]][cur[1]][cur[2]]=true;
    if(cur[0]==0)
        possibleCValues.insert(cur[2]);

    for(int from=0; from<=2; from++)
        for(int to=0; to<=2; to++)
        {
            if(from==to) continue;
            int t = pour(cur, from, to);
            calc(cur);
            pour(cur, to, from, t);
        }
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    
    
    
    fin >> CAP[0] >> CAP[1] >> CAP[2];
    int cur[3]={0,0,CAP[2]};
    calc(cur);

    int index=0;
    for (auto it = possibleCValues.begin(); it != possibleCValues.end(); it++, index++)
    {
        fout << *(it);
        if(index!=possibleCValues.size()-1)
            fout <<" ";
        else
            fout<<endl;
    }
    

    fin.close();
    fout.close();
    return 0;
}