#include"iostream.h"
#include"conio.h"
#include"stdlib.h"
#include"time.h"
#include"stdio.h"
#include"string.h"
#include"dos.h"
void main()
{
 char alphc[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 char alph[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 char ch,mos=178,z1=179,z2=196,answ;
 char cellc[200][200];
 char cell[200][200];
 char word[10];
 char pn[10];
 int i=0,j=0,k=0,op=0,v=0,v1=0,x,y,co=0,g=0,n,sw=0,a=0,f=0,counter=0,c=0,w=-1,p=0,b=0;

textbackground(1); // Blue
clrscr();
 do
 {textcolor(15); // White
 textbackground(1); // Blue
 clrscr();
 ++g;
 i=0;j=0;k=0;x=0;op=0;n=0;counter=0;sw=0;a=0;f=0 ;c=0;w=-1;b=0;p=0;

 while(i!=12)
 {
 while(j!=46){
 if(i==0&&j==0)
 {gotoxy(1,1);
 cout<<"Ú";}
 else
 if(i==0&&j==45)
 {gotoxy(1,45);
 cout<<"¿";}
 else
 if(j==0)
   cout<<"Ã";
 else
 if(i==0 && j%3==0)
   cout<<"Â";
 else if(j==45)
   cout<<"´";
 else if(i!=0 && j%3==0)
   cout<<"Å";
 else
   cout<<"Ä";
 ++j;}
 cout<<"\n";
 while(k!=16)
 {cout<<"³  ";
 ++k;}
 cout<<"\n";
 ++i;
 j=0;
 k=0;}
 for(i=0;i!=46;++i){
  if(i==0)
  {gotoxy(1,25);
  cout<<"À";}    // Ò Ó Ô Õ Ö × Ø
  else if(i==45)
  {gotoxy(46,25);
  cout<<"Ù";}
  else if(i%3==0)
    cout<<"Á";
 else
   cout<<"Ä";
   }
  gotoxy(40,1);
  cout<<"\n";
 for(i=2;i!=25;++i)
  {gotoxy(48,i);
  cout<<"³"<<"\n";}

  for(i=2;i!=26;i+=2)
   for(j=3;j!=48;j+=3)
    {gotoxy(j,i);
     x=random(26);
     cell[i][j]=alph[x];
     cellc[i][j]=alphc[x];
     cout<<alph[x];}

     gotoxy(50,7);
     cout<<"Word In Finding Process: ";
     gotoxy(50,6);
     cout<<"Player Name: ";
     if(g!=1)
     {gotoxy(63,6);
     puts(pn);}
     gotoxy(60,18);
     cout<<"Level: "<<g;
     gotoxy(50,21);
     cout<<"Developed By:";
     gotoxy(50,22);
     cout<<"E.Bahmani & S.M.Hashemi Fard";
     gotoxy(50,24);
     cout<<"ALL RIGHTS RESERVED!!!";
     if(g==1)
     {gotoxy(50,1);
     cout<<"Please Type Your Name: ";
     gotoxy(50,2);
     gets(pn);
     gotoxy(50,3);
     cout<<"Please Type The Word You Want ";
     gotoxy(50,4);
     cout<<"To Find: ";
     gets(word);}
     else
     {gotoxy(50,1);
     cout<<"Please Type The Word You Want ";
     gotoxy(50,2);
     cout<<"To Find: ";
     gets(word);}
     n=strlen(word);
     gotoxy(63,6);
     puts(pn);
     gotoxy(50,8);
     puts(word);

     if(n%2!=0)
     {j=n-1;
     for(b=0;;++b)
      {if(word[b]==word[j]||word[b]+32==word[j]||word[b]==word[j]+32)
       f+=2;
      else
      break;
      if(f==n-1)
      {sw=1;
      break;}
      --j;}}
      f=0;
      f=0;
      if(n%2==0)
      {j=n-1;
     for(b=0;;++b)
      {if(word[b]==word[j]||word[b]+32==word[j]||word[b]==word[j]+32)
      f+=2;
      else
      break;
      if(f==n)
      {sw=1;
      break;}
      --j;}}
      w=-1;

     if(n==1)
     {for(i=2;i!=26;i+=2)
      for(j=3;j!=48;j+=3)
       if(cell[i][j]==word[0]||cellc[i][j]==word[0])
	{++counter;
	gotoxy(j-1,i);
	cout<<"²";}}
     else
   {for(i=2;i!=26;i+=2)
   {c=0;
   v1=0;
   v=0;
    for(j=3;j!=48;j+=3)
     {if(cell[i][j]==word[0]||cellc[i][j]==word[0])
      {++c;
      v1=j+3;
      for(v=1;word[v];++v)
      {if(word[v]==cell[i][v1]||cellc[i][v1]==word[v])
      ++c;
      else
      c=0;
      v1+=3;}}
      else
      {c=0;
      w=-1;}
      if(c==n)
      {p=v1-4;
       for(a=n-1;a>=0;--a)
       {gotoxy(p,i);
	cout<<"²";
       p-=3;}
      ++counter;
      c=0;}}}
      w=n;
      c=0;
      a=0;
      n=strlen(word);
   for(i=2;i!=26;i+=2)
   {c=0;
   v=0;v1=0;a=0;
    for(j=3;j!=48;j+=3)
     {if(cell[i][j]==word[n-1]||cellc[i][j]==word[n-1])
      {++c;
      v1=j+3; a=0;
      for(v=n-2;v>=0;--v)
      {if(word[v]==cell[i][v1]||cellc[i][v1]==word[v])
      {++c;
      a=0;}
      else
      c=0;
      v1+=3;}}
      else
      c=0;
      if(c==n)
      {p=v1-4;
       for(a=0;a!=n;++a)
       {gotoxy(p,i);
	cout<<"²";
       p-=3;}
      ++counter;
      c=0;a=0;}}}
      c=0;

   for(j=3;j!=48;j+=3)
   {c=0;
   v=0;
   v1=0;
    for(i=2;i!=26;i+=2)
     {if(cell[i][j]==word[0]||cellc[i][j]==word[0])
      {++c;
      v1=i+2;
      for(v=1;word[v];++v)
      {if(word[v]==cell[v1][j]||cellc[v1][j]==word[v])
      ++c;
      else
      c=0;
      v1+=2;}}
      else
      {c=0;
      w=-1;}
      if(c==n)
      {p=v1-2;
     textcolor(4);
     for(a=n-1;a>=0;--a)
     {gotoxy(j-1,p);
      cout<<"²";
      p-=2;  }
      ++counter;
      c=0;}}}
      w=n;
      c=0;
   for(j=3;j!=48;j+=3)
   {c=0;
    for(i=2;i!=26;i+=2)
     {if(cell[i][j]==word[n-1]||cellc[i][j]==word[n-1])
      {++c;
      v1=i+2;
      for(v=n-2;v>=0;--v)
      {if(word[v]==cell[v1][j]||cellc[v1][j]==word[v])
      ++c;
      else
      c=0;
      v1+=2;}}
      else
      {c=0;
      w=-1;}
      if(c==n)
      {p=v1-2;
    textcolor(4);
    for(a=0;a!=n;++a)
     {gotoxy(j-1,p);
      cout<<"²";
      p-=2;  }
      ++counter;
      c=0;}}}}

     if(sw==1)
     counter=counter/2;
     gotoxy(50,9);
     if(counter>1)
     cout<<counter<<"Times Found!!!";
     if(counter==0)
     cout<<"oOoOpSsSs!!! didnt find";
     if(counter==1)
     cout<<counter<<"Time Found!!!";
     gotoxy(58,13);
     cout<<"Play Again?";
     cin>>answ;
     if(answ!='y'&&answ!='Y')
      {window(1,1,80,25);
      textbackground(8); // Black
      clrscr();
      textcolor(4);// Red
      gotoxy(20,23);
      cputs("Thanks For Wasting Your Time With Us!!!");
      gotoxy(28,24);
      cputs("Press Any Key To Exit!!!");
      loop:
      gotoxy(22,4);
      for(i=1;i!=14;++i)
      {
      textcolor(i+1);
      gotoxy(20,i-1);
      cout<<"                                      ";
      gotoxy(14,i);
      cputs("                   Developed By:                 ");
      gotoxy(14,i+1);
      cputs("            E.Bahmani & S.M.Hashemi Fard         ");
      delay(500);
      if(kbhit())
      exit(1);
      if(i==13)
      {gotoxy(14,14);
      cout<<"                                                  ";
      gotoxy(14,13);
      cout<<"                                                   ";
      goto loop;}}
      getch();
     }
     }while(1);
getch();
}