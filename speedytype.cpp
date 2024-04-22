#include"stdio.h"
#include"conio.h"
#include"iostream.h"
#include"stdlib.h"
#include"dos.h"
#include"string.h"
#include"graphics.h"
void downmove();
void upmove();
void set_table();
void select();
void load();
void Ftable(int);
int answer(int);
int finish();
int j1=11,j=1,score=0;
void main()
{
	clrscr();
	int a1=0,b1=0,c1=0,sw1=0,d1=0,mo;
	int a2=0,b2=0,c2=0,sw2=0,d2=0,level;
	int a3=0,b3=0,c3=0,sw3=0,d3=0,step=0;
	int a4=0,b4=0,c4=0,sw4=0,d4=0;
	int l=0,k=0,sw11=0;
	int sw12=0,sw13=0,l1=0,d21=0,d22=0,d23=0,sw14=0,d24=0;
	char ch,dc,answ,ch1;
	char words[4][6][15]={
	"tel","coil","spike","replay","spindle","university"
	,"cpu","text","sound","editor","network","monitor"
	,"hate","bird","internal","metallica","motion","late"
	,"dedication","apprise","assignment","kick","host","guest"};

	while(1){
		score=0;
		textbackground(1);
		clrscr();
		set_table();
		while(1){
			ch1=getch();
			if(ch1==0){
				ch1=getch();
				if(ch1==80)
					downmove();
				else if(ch1==72)
					upmove();
			}
			else if(ch1==27)
				exit(0);
			else if(ch1==13){
				select();
				break;
			}
		}


		step=j-1;
		clrscr();
		window(1,1,80,25);
		while(j!=6){
			textbackground(4);
			clrscr();
			textcolor(15);
			a1=0;b1=0;c1=0;sw1=0;d1=0;
			a2=0;b2=0;c2=0;sw2=0;d2=0;
			a3=0;b3=0;c3=0;sw3=0;d3=0;
			a4=0;b4=0;c4=0;sw4=0;d4=0;
			sw12=0;sw13=0;l1=0;d21=0;d22=0;d23=0; d24=0;sw14=0;
			l=0;k=0;sw11=0;
			char  cs[100]={'.','.','.','.','.','.','.','.','.','.','.'};
			clrscr();
			++step;
			gotoxy(9,20);
			cout<<"          ";
			gotoxy(9,20);
			cout<<score;
			textcolor(0);
			for(mo=1;mo!=81;++mo){
				gotoxy(mo,17);
				cputs("²");
			}
			textcolor(14);
			gotoxy(50,24);
			cputs("E.Bahmani & S.M.Hashemi Fard");
			textcolor(15);
			gotoxy(2,19);
			cputs("Type The Words Here: ");
			gotoxy(2,20);
			cputs("Score: ");
			gotoxy(9,20);
			cout<<score;
			gotoxy(2,21);
			cputs("Level: ");
			gotoxy(9,21);
			cout<<j;
			gotoxy(2,24);
			cputs("ESC : EXIT");
			textcolor(15);
			randomize();
			gotoxy(5,1);
			a1=random(4);
			b1=random(6);
			cprintf("%s",words[a1][b1]);

			gotoxy(15,8);
			while(b2==b1||a2==a1){
				a2=random(4);
				b2=random(6);
			}
			cprintf("%s",words[a2][b2]);

			gotoxy(35,5);
			while(b3==b2||b3==b1||a3==a2){
				a3=random(4);
				b3=random(6);
			}
			cprintf("%s",words[a3][b3]);

			gotoxy(50,9);
			while(b4==b3||b4==b2||b4==b1||a4==a3||a4==a2||a4==a1){
				a4=random(4);
				b4=random(6);
			}
			cprintf("%s",words[a4][b4]);
			c1=1;
			c2=8;
			c3=5;
			c4=9;
			d1=1;
			d2=8;
			d3=5;
			d4=9;

			while(1){
				if(l==4)
					break;
				if(l1==4)
					break;

				if(sw1!=1){
					gotoxy(5,c1);
					delay(1000-(step*150));
					cout<<"                 ";
					gotoxy(5,c1+1);
					cprintf("%s",words[a1][b1]);
				}
				++d1;
				++c1;

				if(sw2!=1){
					gotoxy(15,c2);
					delay(900-(step*150));
					cout<<"                   ";
					gotoxy(15,c2+1);
					cprintf("%s",words[a2][b2]);
				}
				++d2;
				++c2;

				if(sw3!=1){
					gotoxy(35,c3);
					delay(1100-(step*150));
					cout<<"                   ";
					gotoxy(35,c3+1);
					cprintf("%s",words[a3][b3]);
				}
				++d3;
				++c3;

				if(sw4!=1){
					gotoxy(50,c4);
					delay(800-(step*150));
					cout<<"                     ";
					gotoxy(50,c4+1);
					cprintf("%s",words[a4][b4]);
				}
				++d4;
				++c4;


				if(sw11==-1){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",++score);
					++l1;
					++d21;
					--sw11;
				}

				if(sw12==-1){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",++score);
					++l1;
					++d22;
					--sw12;
				}


				if(sw13==-1){
					gotoxy(9,20);
					cout<<"   ";
					gotoxy(9,20);
					cprintf("%d",++score);
					++l1;
					++d23;
					--sw13;
				}


				if(sw14==-1){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",++score);
					++l1;
					++d24;
					--sw14;
				}


				if(d1==16){
					sw1=1;
					++l;
				}
				if(d1==16&&d21==0){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",--score);
				}

				if(d2==16){
					sw2=1;
					++l;
				}
				if(d2==16&&d22==0){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",--score);
				}

				if(d3==16){
					sw3=1;
					++l;
				}
				if(d3==16&&d23==0){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",--score);
				}

				if(d4==16){
					sw4=1;
					++l;
				}
				if(d4==16&&d24==0){
					gotoxy(9,20);
					cout<<"    ";
					gotoxy(9,20);
					cprintf("%d",--score);
				}

				while(kbhit()){
					gotoxy(23,19);
					ch=getche();
					if(ch==27)
						exit(0);
					cs[k]=ch;
					cs[k+1]=NULL;
					++k;
				}

				if(sw11>-1){
					if(strstr(cs,words[a1][b1])!=0){
						sw1=1;
						if(d1<17){
							gotoxy(5,c1);
							cout<<"                ";
						}
						--sw11;
						k=0;
						continue;
					}
				}

				if(sw12>-1){
					if(strstr(cs,words[a2][b2])!=0){
						sw2=1;
						if(d2<17){
							gotoxy(15,c2);
							cout<<"                ";
						}
						k=0;
						--sw12;
						continue;
					}
				}

				if(sw13>-1){
					if(strstr(cs,words[a3][b3])!=0){
						sw3=1;
						if(d3<17){
							gotoxy(35,c3);
							cout<<"                ";
						}
						k=0;
						--sw13;
						continue;
					}
				}

				if(sw14>-1){
					if(strstr(cs,words[a4][b4])!=0){
						sw4=1;
						if(d4<17){
							gotoxy(50,c4);
							cout<<"                ";
						}
						k=0;
						--sw14;
						continue;
					}
				}
			}     // End Of Inner While
		++j;
		} // End Of Outer While

	if(finish()==0)
		exit(0);
	}
}
/*=====downmove=====*/
void downmove()
{
	if(j1!=15){
		++j1;
		set_table();
	}
	else{
		j1=11;
		set_table();
	}
}
/*=====upmove=====*/
void upmove()
{
	if(j1!=11){
		--j1;
		set_table();
	}
	else{
		j1=15;
	set_table();
	}
}
/*=========set_teble============*/
void set_table()
{
	textbackground(11);//11
	window(15,3,65,23);
	clrscr();
	textbackground(1);
	window(20,5,60,21);
	clrscr();
	gotoxy(12,5);
	cputs("Select The Level: ");
	gotoxy(13,7);
	cputs("1.First  Level");
	gotoxy(13,8);
	cputs("2.Second LeveL");
	gotoxy(13,9);
	cputs("3.Third  LeveL");
	gotoxy(13,10);
	cputs("4.Fourth LeveL");
	gotoxy(13,11);
	cputs("5.Fifth  LeveL");
	gotoxy(6,13);
	cputs("Press ENTER To Select The Level");
	gotoxy(7,14);
	cputs("You Can Press ESC Key To Exit");

	textbackground(6);
	window(32,j1,46,j1);
	clrscr();
	if(j1==11)
		cputs("1.First  Level");
	if(j1==12)
		cputs("2.Second LeveL");
	if(j1==13)
		cputs("3.Third  LeveL");
	if(j1==14)
		cputs("4.Fourth LeveL");
	if(j1==15)
		cputs("5.Fifth  LeveL");
}
/*============select=============*/
void select()
{
	j=j1-10;
}

/*=======finish===========*/
int finish()
{
	char ch;
	int cnt=16;
	clrscr();
	Ftable(cnt);
	while(1){
		ch=getch();
		if(ch==0){
			ch=getch();
			if(ch==80){
				if(cnt!=16){
					--cnt;
					Ftable(cnt);
				}
				else{
					cnt=17;
					Ftable(cnt);
				}
			}

			else if(ch==72){
				if(cnt!=17){
					++cnt;
					Ftable(cnt);
				}
				else{
					cnt=16;
					Ftable(cnt);
				}
			}
		}
		else if(ch==13)
			return answer(cnt);

	}
}
/*=====Ftable=========*/
void Ftable(int temp)
{
	window(1,1,80,25);
	textbackground(1);
	clrscr();
	textcolor(15);
	gotoxy(28,12);
	cputs("Your Final Score Is: ");
	cprintf("%d",score);
	gotoxy(25,20);
	cputs("E.Bahmani & S.M.Hashemi Fard");
	gotoxy(33,14);
	cputs("Play Again? ");
	gotoxy(36,16);
	cout<<"Y E S";
	gotoxy(36,17);
	cout<<"N   O";
	if(temp==16){
		gotoxy(34,16);
		cout<<"*";
		gotoxy(34,16);
	}
	if(temp==17){
		gotoxy(34,17);
		cout<<"*";
		gotoxy(34,17);
	}
}
/*=======answer=========*/
int answer(int temp)
{
	if(temp==16)
		return 1;
	return 0;
}