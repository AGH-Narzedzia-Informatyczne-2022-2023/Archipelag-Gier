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

    board[0][0]="__";
    board[20][0]="|_";
    board[0][20]="_ ";
}

void screen()
{
    for(int i=0; i<21; i++)
    {
        
        cout << board1[i];
        cout << endl;
    }
}

void snake()
{
    board[part_y[longg]][part_x[longg]]="  ";
    part_x[0]=x; part_y[0]=y;
    

    switch(pad)
    {
        case 'w': 
                padl='w'; y=y-1; break;
        case 'a': 
                padl='a'; x=x-1; break;
        case 's':
                padl='s'; y=y+1; break;
        case 'd':
                padl='d'; x=x+1; break;
    }

    if(x==20) x=1;
    if(x==0) x=19;
    if(y==0) y=19;
    if(y==20) y=1;

    if(board[y][x]=="X ")
    {
        longg++;
        apple();
    }

    if(board[y][x]=="O "||board[y][x]=="o "||board[y][x]=="0 ")
    {
        endd++;
        return;
    } 

    board[y][x]="8 ";
    for(int d=longg; d>0; d--)
    {
        part_x[d]=part_x[d-1];
        part_y[d]=part_y[d-1];
        if(d%4==0)
        board[part_y[d-1]][part_x[d-1]]="O ";
        if(d%4==1)
        board[part_y[d-1]][part_x[d-1]]="o ";
        if(d%4==2)
        board[part_y[d-1]][part_x[d-1]]="0 ";
        if(d%4==3)
        board[part_y[d-1]][part_x[d-1]]="o ";
    }
}

void apple()
{
    do
    {
        random=rand()%(361)+1;
    } while((board[random%19+1][(random-1)/19+1]!="  ")||((random%19+1==apple_y)&&((random-1)/19+1==apple_x)));  //while(board[random%19+1][random/19+1]=="O "||board[random%19+1][random/19+1]=="o "||board[random%19+1][random/19+1]=="0 "||board[random%19+1][random/19+1]=="8 "||(random%19+1==apple_y)&&(random/19+1==apple_x));

    apple_x=(random-1)/19+1;
    apple_y=random%19+1;

    board[apple_y][apple_x]="X ";
}

void start()
{
    x=10; y=10; endd=0; longg=1; czas=0;
    srand(time(NULL));
    place();
    board[x][y]="8 ";
    apple();
    for(int i=0; i<21; i++)
    {
        board1[i].clear();
        for(int j=0; j<21; j++)
        board1[i]+=board[i][j];
    }
    screen();
    padl='%';
    cout << endl << endl << "WITAJ W SNAKE!" << endl << endl << "Sterowanie: wasd." << endl << "Wybierz kierunek by zaczac." << endl << endl << "Autor: Jakub Grzyb";

}

