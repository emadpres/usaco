/*
ID: emadpres1
TASK: beads
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("beads.out");
ifstream fin ("beads.in");

const int MAX_N = 350;
int N;
char beads[MAX_N];


int breakAt(int pos, char lastNonWhiteColor)
{
    int color_r = beads[pos];
    int color_l = lastNonWhiteColor;
    int index_r = pos, index_l= pos==0?N-1:pos-1;
    while( beads[index_r]==color_r || beads[index_r]=='w')
        index_r = index_r==N-1?0:index_r+1; // move one position to right

    while(beads[index_l]==color_l || beads[index_l]=='w')
    {
        index_l = index_l==0?N-1:index_l-1; // move one position to left
        if( (index_r<pos && index_r>index_l) || (index_l>pos && index_l<index_r) )
            break;
    }

    //fout << "\tindex_l: "<<index_l<<"      index_r: "<<index_r<<endl;

    int count_r = index_r>=pos ? (index_r-pos) : (N-pos+index_r);
    int count_l = index_l<=pos ? (pos-1-index_l) : (N-index_l-1+pos);

    return count_r+count_l;
}


int main() {
    
    
    

    fin >> N;
    bool oneBlueFound = false, oneRedFound = false;
    for (int i = 0; i < N; i++) {
        fin >> beads[i];
        if(beads[i]=='r') oneRedFound = true;
        if(beads[i]=='b') oneBlueFound = true;
    }

    // We make sure all breads are not white/blue or white/red in the rest of algorithm
    // otherwise we simply return N as the solution
    if(!oneBlueFound || !oneRedFound) {
        fout<<N<<endl;
        return 0;
    }


    char lastNonWhiteColor='w';
    int lastNonWhitePos=N;
    while(lastNonWhiteColor=='w')
    {
        lastNonWhitePos--;
        lastNonWhiteColor = beads[lastNonWhitePos];
    }

    int best = -1;
    for(int i=0; i<N; i++)
    {
        if(beads[i]!='w' && lastNonWhiteColor!=beads[i])
        {
            //fout << "Breaking at pos: "<<i<<" lastNonWhiteColor: "<<lastNonWhiteColor<<endl;
            int n = breakAt(i, lastNonWhiteColor);
            //fout << "\t\t\tRES"<<n<<endl;
            if(n>best)
                best = n;
            lastNonWhiteColor = beads[i];
        }

    }

    fout<<best<<endl;
    

    return 0;
}