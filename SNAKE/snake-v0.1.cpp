#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <conio.h>

using namespace std;

string board[21][21], board1[21];
void place();

int main()
{
    place();
    for(int i=0; i<21; i++)
    for(int j=0; j<21; j++)
    cout << i << " : " << j << " " << board[i][j] << "   ####  \n";
    return 0;
}

void place()
{
    for(int i=0; i<21; i++)
    {
        board[i][0]="| ";
        board[20][i]="__";
        board[0][i]="__";
        board[i][20]="| ";
    }

    for(int i=1; i<20; i++)
    {
        for(int j=1; j<20; j++)
        board[i][j]="  ";
    }

    board[0][0]="__";
    board[20][0]="|_";
    board[0][20]="_ ";
}