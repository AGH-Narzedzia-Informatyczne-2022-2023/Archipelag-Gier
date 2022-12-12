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
    for(int restart=0; restart<10000; restart++)
    {
        system("cls");
        start();

        for (int a=0; a<10000; a++)
        {
            pad=getch();
            if((pad=='w'&&padl=='s')||(pad=='s'&&padl=='w')||(pad=='a'&&padl=='d')||(pad=='d'&&padl=='a')||((pad!='w')&(pad!='a')&(pad!='s')&(pad!='d')))
            pad=padl;

            while(!_kbhit())
            {
                snake();
                for(int i=0; i<21; i++)
                {
                    board1[i].clear();
                    for(int j=0; j<21; j++)
                    board1[i]+=board[i][j];
                }
    
                cls();
                screen();
                cout<< "x,y: " << x << " " << y<<"      Dlugosc: " << longg << "      Czas: " <<czas/10/60 << ":" << czas/10%60 << endl << "x,y jablka: " << apple_x << " " << apple_y;
                if(endd>=1) break;
                Sleep(100);
                czas++;

            }
        if(endd>=1) break;
        }

        cout << endl << "KONIEC GRY!" << endl << "Nacisnij 2 razy dowolny klawisz by zaczac od nowa. Nacisnij l jesli chcesz wyjsc.";
        getch();
        reset=getch();
        if(reset=='l')
        exit(0);
    }
}

