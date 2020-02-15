/*
ID: emadpres1
TASK: wormhole
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

struct Pos{
    int x,y;
    
    bool operator<(const Pos &another) const {
        return x<another.x || ( y<another.y && !(another.x<x));
    }
};


const int MAX_N = 12;
int nHoles, nBadPairings=0;
Pos holes_pos[MAX_N];
map<int, int> max_x;

ostream& operator<<(ostream &out, const Pos &h)
{
    out << h.x<<"_"<<h.y;
    return out;
}

bool CheckLoopExists(const pair<Pos,Pos> myPairs[])
{
    map<Pos, Pos> tunnels;
    for(int i=0; i<nHoles/2; i++)
    {
        tunnels.insert(make_pair(myPairs[i].first , myPairs[i].second));
        tunnels.insert(make_pair(myPairs[i].second, myPairs[i].first));
    }

    for(int i=0; i<nHoles; i++)
    {
        Pos cur_pos {holes_pos[i].x, holes_pos[i].y};
        int nUsedTunnel=0;

        while(true)
        {
            if(tunnels.find(cur_pos)!=tunnels.end())
            {
                nUsedTunnel++;
                if(nUsedTunnel>nHoles)
                    return true;
                cur_pos = tunnels.at(cur_pos);
            }
            
            //move to right
            int old_x = cur_pos.x;
            cur_pos.x = max_x.at(cur_pos.y);
            for(int j=0; j<nHoles; j++)
                if(holes_pos[j].y==cur_pos.y && holes_pos[j].x>old_x && holes_pos[j].x<cur_pos.x)
                    cur_pos.x = holes_pos[j].x;
            if(old_x == cur_pos.x)
                break; //cow reached the right boundary
        }
    }
    return false;
}

void MakePairs(const int pairIndex, bool availableHoles[], pair<Pos,Pos> myPairs[])
{
    if(pairIndex == nHoles/2)
    {
        // for(int i=0; i<nHoles/2; i++)
        //     cout <<"#"<<i+1<< "\t(" << myPairs[i].first<<","<<myPairs[i].second<<")"<<endl;
        
        if(CheckLoopExists(myPairs))
        {
            //cout << "----------------- with Loooop"<<endl;
            nBadPairings++;
        }
        // else
        //     cout << "----------------- OK"<<endl;
        
        return;
    }
    
    int firstAva = 0;
    while(availableHoles[firstAva]==false) firstAva++;
    availableHoles[firstAva]=false;

    for(int i=firstAva+1; i<nHoles; i++)
    {
        if(availableHoles[i])
        {
            availableHoles[i]=false;
            myPairs[pairIndex] = make_pair(holes_pos[firstAva], holes_pos[i]);
            MakePairs(pairIndex+1, availableHoles, myPairs);
            availableHoles[i]=true;
        }
    }
    availableHoles[firstAva]=true;
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
       


    fin >> nHoles ;
    for(int i=0; i<nHoles; i++)
    {
        fin >> holes_pos[i].x >> holes_pos[i].y;
        if(max_x.find(holes_pos[i].y) != max_x.end())
        {
            if(max_x.at(holes_pos[i].y) < holes_pos[i].x)
                max_x.at(holes_pos[i].y) = holes_pos[i].x;
        }
        else
        {
            max_x.insert(make_pair(holes_pos[i].y, holes_pos[i].x));
        }
        
    }


    bool availableHoles[MAX_N];
    for(int i=0; i<nHoles; availableHoles[i]=true, i++);
    pair<Pos,Pos> myPairs[MAX_N];
    MakePairs(0, availableHoles, myPairs);

    fout << nBadPairings << endl;
    fin.close();
    fout.close();
    return 0;
}