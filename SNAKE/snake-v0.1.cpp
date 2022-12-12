#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#define cls(); printf("\e[H\e[2J\e[3J");


using namespace std;

string board[21][21], board1[21];
void place();
void screen();
void snake();
void apple();
void eat();
void start();

char pad, padl;
int x=10, y=10;
int endd=0;
int longg=1;
int part_x[1000], part_y[1000];
int random;
int apple_x, apple_y;
int czas=0;
char reset;

int main()
{
    return 0;
}