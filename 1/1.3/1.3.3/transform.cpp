/*
ID: emadpres1
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_N = 10;

void copy_matrix(char from[MAX_N][MAX_N], char to[MAX_N][MAX_N], int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            to[i][j] = from[i][j];
}

// void print_matrix(char mat[MAX_N][MAX_N], int N)
// {
//     cout << "------- PRINTING -------\n";
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             cout << mat[i][j];
//         cout<<endl;
//     }
//     cout << "------------------------\n";
// }

bool isSame(char first[MAX_N][MAX_N], char second[MAX_N][MAX_N], int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(first[i][j] != second[i][j])
                return false;
    return true;
}

bool rotate90(char mat[MAX_N][MAX_N], int N)
{
    // i,j ---> j, N-1-i
    char result[MAX_N][MAX_N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[j][N-1-i] = mat[i][j];  
    copy_matrix(result, mat, N);

    return true;
}

bool mirrorH(char mat[MAX_N][MAX_N], int N)
{
    // i,j ---> j, N-1-i
    char result[MAX_N][MAX_N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][N-1-j] = mat[i][j];  
    copy_matrix(result, mat, N);

    return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int N;
    char first[MAX_N][MAX_N], second[MAX_N][MAX_N];
    fin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> first[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> second[i][j];


    int result = -1;

    if( rotate90(first, N) /*90*/ && isSame(second, first, N) )
        result = 1;
    else if( rotate90(first, N) /*180*/ && isSame(second, first, N) )
        result = 2;
    else if( rotate90(first, N) /*270*/ && isSame(second, first, N) )
        result = 3;
    else if( rotate90(first, N) /*360=original*/ && mirrorH(first, N) && isSame(second, first, N) )
        result = 4;
    else if(    (rotate90(first, N) && isSame(second, first, N)) ||
                (rotate90(first, N) && isSame(second, first, N)) ||
                (rotate90(first, N) && isSame(second, first, N)) )
        result = 5;
    else if( rotate90(first, N) && mirrorH(first, N) && isSame(second, first, N) )
        result = 6;
    else 
        result = 7;
    
    fout << result << endl;   

    return 0;
}