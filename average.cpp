#include"iostream.h"
#include"conio.h"
#include"stdio.h"
void main()
{
	clrscr();
	int i,p=8,j/*Counter*/,Sn/*Number of students*/,Sn1/*Number of students*/,
	Ln/*Number of lessons*/,Ut=0,/*Total units*/unit/*Unit of lesson*/,
	Gn1/*Number of grades/Number of lessons*/;
	float avg/*Average of student*/,gr/*Student's grades*/,
	temp=0/*Temporary*/,total/*Total grades*/;

	textbackground(1);
	clrscr();
	cout<<"Please Enter Number Of Students: ";
	gotoxy(25,11);
	cout<<"****Remaining Students: "<<"  ****";
	gotoxy(25,13);
	cout<<"****Remaining   Grades: "<<"  ****";
	gotoxy(31,15);
	cout<<"Student's Average: ";
	gotoxy(1,4);
	cout<<"Grades:";
	gotoxy(1,5);
	cout<<"U nits:";
	gotoxy(30,24);
	cout<<"### By E.Bahmani ###";
	gotoxy(28,25);
	cout<<"Professor: Modaresi Majd";
	gotoxy(1,2);
	cout<<"Please Enter Number Of Your Lessons:     (MAX : 10)\n";
	cout<<"Please Enter Your Grade Then The Lesson's Unit";
	do{
		gotoxy(34,1);
		cin>>Sn;//Getting number of students
		if(Sn<=0){
			gotoxy(34,1);
			cout<<"  ";
		}
	}while(Sn<=0);
	Sn1=Sn;
	gotoxy(49,11);
	cout<<Sn1;//Showing number of students
	for(i=0;i<Sn;++i){
		do{
			gotoxy(38,2);
			cin>>Ln;//Getting number of lessons
			if(Ln<=0){
				gotoxy(38,2);
				cout<<"  ";
			}
		}while(Ln<=0);
		Gn1=Ln;
		gotoxy(49,13);
		cout<<Gn1;//Showing number of lessons
		for(j=0;j<Ln;++j){
			gotoxy(p,4);
			cin>>gr;//Getting grade
			gotoxy(p+5,4);
			cout<<",";
			gotoxy(p,5);
			cin>>unit;//Getting unit
			gotoxy(p+5,5);
			cout<<",";
			gotoxy(49,13);
			cout<<"  ";//Clear the last number of grades
			gotoxy(49,13);
			cout<<--Gn1;//Showing remaining grades
			p+=6;
			Ut+=unit;
			temp=temp+(gr*unit);
		}//End of inner loop
		gotoxy(49,11);
		cout<<"  ";//Clear the last number of students
		gotoxy(49,11);
		cout<<--Sn1;//Showing remaining students
		avg=temp/Ut;
		gotoxy(37,17);
		printf("%4.2f",avg);//Showing student's average
		total+=avg;//Calculating total grades for class average
	  /*=====Setting Default====*/
		p=8;
		Ut=0;
		temp=0;
		gotoxy(28,18);
		cout<<"Press Any Key To Continue";
		getch();
		gotoxy(28,18);
		cout<<"                         ";//Clear "Press Any..."
		gotoxy(37,17);
		cout<<"                  ";//Clear the last student's average
		gotoxy(38,2);
		cout<<"  ";//Clear the last number of lessons
		gotoxy(49,13);
		cout<<"  ";//Clear the last remaining grades
		gotoxy(8,4);//Clear the last grades
		cout<<"                                                            ";
		gotoxy(8,5);//Clear the last units
		cout<<"                                                              ";
	  /*========================*/
	}//End of outer loop
	gotoxy(30,19);
	cout<<"Average Of Class Is:";
	gotoxy(37,21);
	printf("%4.2f",total/Sn);
	getch();
}




