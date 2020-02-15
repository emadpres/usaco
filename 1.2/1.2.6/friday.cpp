/*
ID: emadpres1
TASK: friday
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin >> N;
    int freq[7]={0}; // sat, sun, mon=2, ...

    int month_len[12] = {   31, -1, 31,     // jan, feb, mar // feb: 28 (29 in in leap years)
                            30, 31, 30,     // apr, may, jun
                            31, 31, 30,     // jul, aug, sep
                            31, 30, 31};    // oct, nov, dec


    int firstDayOfMonth_weekDayNumber = 2; // 1st Jan 1900 is Monday(2);
    for (int year = 1900; year <= 1900+N-1; year++)
    {
        month_len[1] = 28 ;
        if( (year%100==0 && year%400==0) || (year%100!=0 && year%4==0))
            month_len[1] = 29 ; // leap year

        for(int month=0; month<12; month++)
        {
            int t = (firstDayOfMonth_weekDayNumber + 12)%7;
            freq[t]++;

            firstDayOfMonth_weekDayNumber = (firstDayOfMonth_weekDayNumber+ month_len[month])%7;
        }
    }

    for (int i = 0; i < 7; i++)
    {
        fout<<freq[i];
        if(i<6) fout<<" ";
    }
    fout<<endl;
    
    
    return 0;
}