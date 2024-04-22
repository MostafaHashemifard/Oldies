#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "graphics.h"
#include "stdio.h"
#include "dos.h"
void Paint5Nods(int,int,int,int,int,int,int,int,int,int);
void LineFromTo(int,int,int,int);
void Collar(int,int,int);
void paint();
void leftmove();
void downmove();
void rightmove();
void upmove();
void movement();
void select();
void set_table();
void setting_default();
void fill_graph();
void choice();
void nod_degree();
void graph_info();
void route();
void all_routes();
void matrix_calculating();
void degree_calculating();
void SetColor();
int calculating();
char names[5]={'a','b','c','d','e'};
int color[5]={0};
int nods[40][40];
int m[5][5];
int m2[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int m3[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int m4[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int m5[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int routes[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int M[5][5];
int M2[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int M3[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int M4[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int M5[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Routes[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Coordinats[5][2]={320,55, 160,165, 480,165, 160,385, 480,385};
const int COUNT=5;
int x=6,y=2,counter=0,cnt=0;
int degA=0,degB=0,degC=0,degD=0,degE=0;
int OdegA,OdegB,OdegC,OdegD,OdegE,IdegA,IdegB,IdegC,IdegD,IdegE;
void main()
{
	int i,j,k,p=0,q=0;
	textbackground(1);
	clrscr();
	set_table();
	gotoxy(2,12);
	cout<<"1.Graph's informations";
	gotoxy(2,13);
	cout<<"2.Nods' degree";
	gotoxy(2,14);
	cout<<"3.Route between two nods";
	gotoxy(2,15);
	cout<<"4.All routes";
	gotoxy(2,16);
	cout<<"5.Drawing Graph Then Exit";
	gotoxy(2,18);
	cout<<"Your choice: ";
	gotoxy(x,y);
	fill_graph();
	for(i=2;i<12;i+=2){
		for(j=6;j<24;j+=4){
			m[p][q]=nods[j][i];
			++q;
		}
		q=0;
		++p;
	}
	degree_calculating();
	matrix_calculating();
	calculating();
	SetColor();
	while(1){
		setting_default();
		choice();
		getch();
	}
}
/*=====paint=====*/
void paint()
{
	int i,j;

	Paint5Nods(Coordinats[0][0],Coordinats[0][1],
		   Coordinats[1][0],Coordinats[1][1],
		   Coordinats[2][0],Coordinats[2][1],
		   Coordinats[3][0],Coordinats[3][1],
		   Coordinats[4][0],Coordinats[4][1]);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++){
				if(m[i][j]==1)
				{
					if(i==j)
						Collar(Coordinats[i][0],Coordinats[i][1],i);
				else
						LineFromTo(Coordinats[i][0],Coordinats[i][1],Coordinats[j][0],Coordinats[j][1]);
				}
		}
	getch();
	closegraph();
}
/*=====Paint5Nods=====*/
void Paint5Nods(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5)
{

	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "bgi");
	errorcode = graphresult();
	if (errorcode != grOk){
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	setbkcolor(9);
	for(int i=0;i<8;i++){

		moveto(x1-3,y1-20);
		setcolor(1);
		outtext("A");
		setcolor(color[0]);//a
		circle(x1,y1,i);

		moveto(x2-20,y2-2);
		setcolor(1);
		outtext("B");
		setcolor(color[1]);//b
		circle(x2,y2,i);

		moveto(x3+20,y3-2);
		setcolor(1);
		outtext("C");
		setcolor(color[2]);//c
		circle(x3,y3,i);

		moveto(x4-20,y4-2);
		setcolor(1);
		outtext("D");
		setcolor(color[3]);//d
		circle(x4,y4,i);

		moveto(x5+20,y5-2);
		setcolor(1);
		outtext("E");
		setcolor(color[4]);//e
		circle(x5,y5,i);
	}
}
/*=====LineFromTo=====*/
void LineFromTo(int x1, int y1, int x2, int y2)
{

	setcolor(4);
	line(x1,y1,x2,y2);
	if(x1<x2 && y1==y2){
		line(x2,y2,x2-25,y2-5);
		line(x2,y2,x2-25,y2+5);
	}
	if(x2<x1 && y1==y2){
		line(x2,y2,x2+25,y2-5);
		line(x2,y2,x2+25,y2+5);
	}

	if(y1<y2 && x1==x2){
		line(x2,y2,x2-5,y2-25);
		line(x2,y2,x2+5,y2-25);
	}
	if(y2<y1 && x1==x2){
		line(x2,y2,x2+5,y2+25);
		line(x2,y2,x2-5,y2+25);
	}

	if(y1<y2 && x1<x2){
		if(y1==55 && y2==165){
			line(x2,y2,x2-20,y2-20);
			line(x2,y2,x2-26,y2-12);
		}
		if(y1==165 && y2==385){
			line(x2,y2,x2-20,y2-20);
			line(x2,y2,x2-26,y2-12);
		}
		if(y1==55 && y2==385){
			line(x2,y2,x2-9,y2-29);
			line(x2,y2,x2-16,y2-22);
		}
	}
	if(y1>y2 && x1>x2){
		if(y1==165 && y2==55){
			line(x2,y2,x2+26,y2+12);
			line(x2,y2,x2+20,y2+20);
		}
		if(y1==385 && y2==165){
			line(x2,y2,x2+26,y2+12);
			line(x2,y2,x2+20,y2+20);
		}
		if(y1==385 && y2==55){
			line(x2,y2,x2+16,y2+22);
			line(x2,y2,x2+9,y2+29);
		}
	}
	if(y1>y2 && x1<x2){
		if(y1==165 && y2==55){
			line(x2,y2,x2-26,y2+12);
			line(x2,y2,x2-20,y2+20);
		}
		if(y1==385 && y2==165){
			line(x2,y2,x2-26,y2+12);
			line(x2,y2,x2-20,y2+20);
		}
		if(y1==385 && y2==55){
			line(x2,y2,x2-16,y2+22);
			line(x2,y2,x2-9,y2+29);
		}
	}
	if(y1<y2 && x1>x2){
		if(y1==55 && y2==165){
			line(x2,y2,x2+20,y2-20);
			line(x2,y2,x2+26,y2-12);
		}
		if(y1==165 && y2==385){
			line(x2,y2,x2+20,y2-20);
			line(x2,y2,x2+26,y2-12);
		}
		if(y1==55 && y2==385){
			line(x2,y2,x2+9,y2-29);
			line(x2,y2,x2+16,y2-22);
		}
	}
}
/*=====Collar=====*/
void Collar(int x, int y, int Number)
{
	setcolor(4);
	switch(Number){
		case 0: circle(x,y-20,20); break;
		case 2: circle(x+20,y,20); break;
		case 4: circle(x+20,y,20); break;
		case 3: circle(x-20,y,20); break;
		case 1: circle(x-20,y,20); break;
	}
}
/*=====fill_graph=====*/
void fill_graph()
{
	movement();
}
/*=====leftmove=====*/
void leftmove()
{
	if(x!=6){
		gotoxy(x-=4,y);
	}
}
/*=====downmove=====*/
void downmove()
{
	if(y!=10){
		gotoxy(x,y+=2);
	}
}
/*=====rightmove=====*/
void rightmove()
{
	if(x!=22){
		gotoxy(x+=4,y);
	}
}
/*=====upmove=====*/
void upmove()
{
	if(y!=1){
		gotoxy(x,y-=2);
	}
}
/*=======movement=======*/
void movement()
{
	int sw=0;
	char ch;
	while(counter!=25){
		ch=getch();
		if(ch==0){
			ch=getch();
			if(sw==1){
				gotoxy(28,2);
				cout<<"                 ";
				sw=0;
			}
			if(ch==75)
				leftmove();
			else if(ch==80)
				downmove();
			else if(ch==77)
				rightmove();
			else if(ch==72)
				upmove();
		}
		else if(ch==13){
			if(nods[x][y]==-1)
				select();
			else if(nods[x][y]==0||nods[x][y]==1){
				gotoxy(28,2);
				cout<<"This cell is full";
				sw=1;
			}
		}
		else if(ch==27)
			exit(0);
	}
}
/*=======select========*/
void select()
{
	cin>>nods[x][y];
	++counter;
	gotoxy(x,y);
}
/*========set_table==========*/
void set_table()
{
	int p=2,j=0,q=6;
	char nod[10]={'a','b','c','d','e',' ',' ',' ',' ',' '};

	for(int r=0;r<40;++r)
		for(int e=0;e<40;++e)
			nods[r][e]=-1;

	for(int i=2;i<12;++i){
		gotoxy(4,i);
		cout<<"³";
		gotoxy(24,i);
		cout<<"³";
		if(i==2){
			gotoxy(4,1);
			cout<<"Ú";
			gotoxy(24,1);
			cout<<"¿";
		}
		else if(i==11){
			gotoxy(4,11);
			cout<<"À";
			gotoxy(24,11);
			cout<<"Ù";
		}
		gotoxy(2,p);
		cout<<nod[j];
		gotoxy(q,1);
		cout<<nod[j];
		q+=4;
		p+=2;
		++j;
	}
}
/*======choice=======*/
void choice()
{
	int choice;
	gotoxy(15,18);
	cin>>choice;
	switch(choice){
		case 1:
			graph_info();
			break;
		case 2:
			nod_degree();
			break;
		case 3:
			route();
			break;
		case 4:
			all_routes();
			break;
		case 5:
			paint();
			exit(0);
		default:
			gotoxy(2,19);
			cout<<"WRONG ENTRY";
			delay(1000);
			exit(0);
	}
}

/*========degree_calculating========*/
void degree_calculating()
{
	int o;
	for(o=0;o<5;++o){
		OdegA+=m[o][0];
		IdegA+=m[0][o];
	}
	degA=OdegA+IdegA;
	for(o=0;o<5;++o){
		OdegB+=m[o][1];
		IdegB+=m[1][o];
	}
	degB=OdegB+IdegB;
	for(o=0;o<5;++o){
		OdegC+=m[o][2];
		IdegC+=m[2][o];
	}
	degC=OdegC+IdegC;
	for(o=0;o<5;++o){
		OdegD+=m[o][3];
		IdegD+=m[3][o];
	}
	degD=OdegD+IdegD;
	for(o=0;o<5;++o){
		OdegE+=m[o][4];
		IdegE+=m[4][o];
	}
	degE=OdegE+IdegE;
}

/*=======nod_degree========*/
void nod_degree()
{
	char name;
	gotoxy(2,19);
	cout<<"Nod name: ";
	cin>>name;
	switch(name){
		case 'a':
			gotoxy(2,20);
			cout<<"Nod ("<<name<<")'s degree: "<<degA;
			break;
		case 'b':
			gotoxy(2,20);
			cout<<"Nod ("<<name<<")'s degree: "<<degB;
			break;
		case 'c':
			gotoxy(2,20);
			cout<<"Nod ("<<name<<")'s degree: "<<degC;
			break;
		case 'd':
			gotoxy(2,20);
			cout<<"Nod ("<<name<<")'s degree: "<<degD;
			break;
		case 'e':
			gotoxy(2,20);
			cout<<"Nod ("<<name<<")'s degree: "<<degE;
			break;
		default:
			gotoxy(2,19);
			cout<<"Wrong entry";
			break;
	}
}
/*========graph_info=========*/
void graph_info()
{
	int o,f,i,sw=0;
	gotoxy(40,4);
	cout<<"***Graph Information***";
	/****IsHamband****/
	if(calculating()==25){
		gotoxy(41,7);
		cout<<"This graph is connected";
		sw=1;
	}
	else{
		gotoxy(39,7);
		cout<<"This graph is not connected";
		sw=0;
	}
	/*****************/

	/****IsOiler****/
	if(sw==1)
		if(OdegA==IdegA&&OdegB==IdegB&&OdegC==IdegC&&OdegD==IdegD&&OdegE==IdegE){
			gotoxy(41,8);
			cout<<"This graph is oiler";
		}
		else{
			gotoxy(41,8);
			cout<<"This graph is not oiler";
		}
	else{
		gotoxy(41,8);
		cout<<"This graph is not oiler";
	   }

	/***************/

	for(i=0;i<5;++i){
		gotoxy(41,i+9);
		cout<<"Color of nod ("<<names[i]<<") will be : ";
		cout<<color[i];
	}
}

/*========route===========*/
void route()
{
	char nod1,nod2;
	gotoxy(2,19);
	cout<<"First nod: ";
	cin>>nod1;
	gotoxy(2,20);
	cout<<"Second nod: ";
	cin>>nod2;
	gotoxy(40,4);
	cout<<"***Route Between Two Nods***";
	for(int i=0;i<5;++i)
		if(nod1==names[i])
			break;
	for(int j=0;j<5;++j)
		if(nod2==names[j])
			break;
	if(routes[i][j]==1){
		gotoxy(36,7);
		cout<<"There is a route between ("<<nod1<<") "<<"and ("<<nod2<<").";
	}
	else{
		gotoxy(33,7);
		cout<<"There isn't any routes between ("<<nod1<<") "<<"and ("<<nod2<<").";
	}
}

/*=========all_routes==============*/
void all_routes()
{
	int sw=1,j,i;
	gotoxy(45,4);
	cout<<"**All Routes**";
	for(i=0,j=0;i<5;++i,++j){
		if(sw==1)
			gotoxy(45,j+7);
		else
			--j;
		sw=0;
		for(int j=0;j<5;++j){
			if(routes[i][j]==1){
				sw=1;
				cout<<" ("<<names[i]<<","<<names[j]<<") ";
			}
		}
	}
}
/*=========matrix_calculating==========*/
void matrix_calculating()
{
	int i,j,k;
	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(m[i][k]*m[k][j]==1)
					m2[i][j]=1;

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(m[i][k]*m2[k][j]==1)
					m3[i][j]=1;

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(m[i][k]*m3[k][j]==1)
					m4[i][j]=1;

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(m[i][k]*m4[k][j]==1)
					m5[i][j]=1;
	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			if(m5[i][j]==1||m4[i][j]==1||m3[i][j]==1||m2[i][j]==1||m[i][j]==1)
				routes[i][j]=1;

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			if(i==j)
				if(routes[i][j]==1)
					++cnt;
}

/*==========calculating============*/
int calculating()
{
       int counter=0;
       for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			M[i][j]=m[i][j];

       for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			if(m[i][j]==1)
				M[j][i]=M[i][j];

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(int k=0;k<5;++k)
				if(M[i][k]*M[k][j]==1)
					M2[i][j]=1;
	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(M[i][k]*M2[k][j]==1)
					M3[i][j]=1;

	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(M[i][k]*M3[k][j]==1)
					M4[i][j]=1;
	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			for(k=0;k<5;++k)
				if(M[i][k]*M3[k][j]==1)
					M5[i][j]=1;
	for(i=0;i<5;++i)
		for(j=0;j<5;++j)
			if(M5[i][j]==1||M4[i][j]==1||M3[i][j]==1||M2[i][j]==1||M[i][j]==1)
				Routes[i][j]=1;
	for( i=0;i<5;++i)
		for( j=0;j<5;++j)
			if(Routes[i][j]==1)
				++counter;
	return counter;
}

/*==========SetColor===========*/
void SetColor()
{
	for(int i=0;i<COUNT;i++)
		color[i]=0;
	for(i=0;i<COUNT;i++)
	{
		int c[COUNT]={0,0,0,0,0};
		for(int j=0;j<COUNT;j++)
		{
		      if(M[i][j]==1 && color[j]!=0)
			      c[color[j]]=1;
		      int ii=1;
		      while(c[ii]!=0)
			     ii++;
		      color[i]=ii;
		}
	}
}

/*=========setting_default==========*/
void setting_default()
{
	gotoxy(15,18);
	cout<<" ";
	for(int i=19;i<=24;++i)
		for(int j=2;j!=80;++j){
			gotoxy(j,i);
			cout<<" ";
		}
	for(i=1;i<=24;++i)
		for(j=30;j!=80;++j){
			gotoxy(j,i);
			cout<<" ";
		}
}
