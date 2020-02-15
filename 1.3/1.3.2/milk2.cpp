/*
ID: emadpres1
TASK: milk2
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Event{
    int time;
    bool type; //true: oomade   false: mire
};

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    const int N_MAX = 5000;
    int N;
    Event events[N_MAX*2];

    fin >> N;
    for(int i=0; i<N; i++)
    {
        fin >> events[i*2].time >> events[i*2+1].time;
        events[i*2].type = true;
        events[i*2+1].type = false;
    }

    
    sort(events, events+N*2, [](Event a, Event b){
        if(a.time < b.time)
            return true;
        else if(a.time == b.time && a.type==true && b.type==false)
            // in case at the same time some farmer leaves and 
            // some arrives, give higher priority to arrivals.
            return true; 
        else return false;
        });


    int cur_milking_start, cur_idle_start = -1;
    int n_cur_milker = 0;
    int longest_milking = 0;
    int longest_idle = 0;
    for(int i=0; i<N*2; i++)
    {
        if(events[i].type == true) // new farmer arrived
        {
            n_cur_milker++;
            if(n_cur_milker==1)
            {
                cur_milking_start = events[i].time;
                if(cur_idle_start!=-1 && events[i].time-cur_idle_start>longest_idle)
                    longest_idle = events[i].time-cur_idle_start;
            }
        }
        else    // a farmer is leaving
        {
            n_cur_milker--;
            if(n_cur_milker==0)
            {
                cur_idle_start = events[i].time;
                if(events[i].time-cur_milking_start > longest_milking)
                    longest_milking = events[i].time-cur_milking_start;
            }
        }
        
    }
    fout << longest_milking<<" "<<longest_idle<<endl;
    return 0;
}