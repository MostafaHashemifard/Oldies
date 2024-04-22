


#include"iostream.h"
#include"conio.h"
#include"stdlib.h"
#include"stdio.h"
#include"time.h"
#include"dos.h"
void X();
void XP1();
void XP9();
void XP10();
void XP11();
void XM1();
void XM9();
void XM10();
void XM11();
void ShowBombs();
int cell[101],cellc[100][100];
int p=0,r=0,k=0,x,a=0;
void main()
{
 int i=0,j=0;
 clrscr();
 for(i=1;i!=26;++i)
 {textbackground(20);
 delay(100);
 window(1,i,80,i);
 clrscr();}

i=0;
textbackground(20);
window(1,1,80,25);
clrscr();
 while(i!=10)
 {
 while(j!=41)
 {
  if(j==0)
    cout<<"Ã";
  else
   if(i==0 && j%4==0)
    cout<<"Â";
 else if(j==40)
    cout<<"´";
 else if(i!=0 && j%4==0)
    cout<<"Å";
 else
    cout<<"Ä";
 ++j;
 }
 cout<<"\n";
while(k!=11)
{
  cout<<"³   ";
  ++k;
}
  cout<<"\n";
  ++i;
  j=0;
  k=0;
}
 for(i=0;i!=41;++i)
 {
  if(i%4==0)
    cout<<"Á";
  else
    cout<<"Ä";
 }
  gotoxy(40,1);
  cout<<"\n";
  gotoxy(1,1);
  cout<<"Ú";
  gotoxy(41,1);
  cout<<"¿";
  gotoxy(1,21);
  cout<<"À";
  gotoxy(41,21);
  cout<<"Ù";

  gotoxy(2,23);
  cout<<"Developed by:";
  gotoxy(2,24);
  cout<<"MAHDIYAR AHMADI  & HAMED KHOJASTEH ";
  int cnt=0;
  for(i=2;i<=20;i+=2)
     for(j=2;j<=40;j+=4)
     {  ++cnt;
	gotoxy(j,i);
	cout<<cnt;

  }
  for(i=1;i<=100;++i)
      cell[i]=1;

  srand(time(0));
    cout<<"\n\n";
    while(r<10){
     p=random(101);
    if(cell[p]==0)
	continue;
    else{
    cell[p]=0;
    ++r;}
    }

  cnt=0;
  for(i=2;i<=20;i+=2)
     for(j=2;j<=40;j+=4)
     {  ++cnt;
	cellc[j][i]=cell[cnt];
     }
    cout<<"\n";
    cnt=0;

    while(a!=90)
   {
      gotoxy(50,2);
      cout<<"***WELCOME TO MINESWEEPER***";
      gotoxy(50,4);
      cout<<"Enter Cell Number ";
      gotoxy(67,4);
      cout<<"   ";
      cin>>x;
      gotoxy(67,4);
      cout<<"      ";
      if(cell[x]==0){
	 gotoxy(50,11);
	 cout<<"You lose ";
	 ShowBombs();
	 break;
      }
      else
      {
      if(x==1){
	X();
	XP1();
	XP10();
	XP11();
      }
      else if(x==10){
	X();
	XM1();
	XP9();
	XP10();
      }
      else if(x==91){
	X();
	XP1();
	XM9();
	XM10();
      }
      else if(x==100){
	X();
	XM1();
	XM10();
	XM11();
      }
      else if(x%10==1){
	X();
	XM10();
	XM9();
	XP1();
	XP10();
	XP11();
      }
      else if(x%10==0){
	X();
	XM1();
	XM10();
	XM11();
	XP9();
	XP10();
      }
      else{
	X();
	XP1();
	XP9();
	XP10();
	XP11();
	XM1();
	XM9();
	XM10();
	XM11();
      }
      }
}
gotoxy(20,40);
getch();
}
/*=====X======*/
void X()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x)
				if(cell[x]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x)
			break;
	}
}

/*=======XP1=========*/
void XP1()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x+1)
				if(cell[x+1]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x+1)
			break;
	}
}
/*========XP9==========*/
void XP9()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x+9)
				if(cell[x+9]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x+9)
			break;
	}
}

/*========XP10========*/
void XP10()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x+10)
				if(cell[x+10]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x+10)
			break;
	}
}

/*========XP11=========*/
void XP11()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x+11)
				if(cell[x+11]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		 }
		 if(g==x+11)
			break;
	}
}

/*=======XM1=======*/
void XM1()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x-1)
				if(cell[x-1]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x-1)
			break;
	}
}

/*=========XM9==========*/
void XM9()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x-9)
				if(cell[x-9]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x-9)
			break;
	}
}

/*=========XM10=========*/
void XM10()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		 for(j=2;j<=40;j+=4){
			++g;
			if(g==x-10)
				if(cell[x-10]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
				}
		}
		if(g==x-10)
			break;
	}
}

/*===========XM11===========*/
void XM11()
{
	int i,j,g=0;
	for(i=2;i<=20;i+=2){
		for(j=2;j<=40;j+=4){
			++g;
			if(g==x-11)
				if(cell[x-11]==1){
					gotoxy(j,i);
					cout<<"   ";
					++a;
					break;
			}
		}
		if(g==x-11)
			break;
	}
}

/*=======ShowBombs==========*/
void ShowBombs()
{
	  int i,j,k;
			for(j=2;j<=20;j+=2){
				for(k=2;k<=40;k+=4){
					if(cellc[k][j]==0){
						gotoxy(k,j);
						cout<<" * ";
					}
					else if(cellc[k][j]==1){
						gotoxy(k,j);
						cout<<"²²²";
					}
				}
			}
}

