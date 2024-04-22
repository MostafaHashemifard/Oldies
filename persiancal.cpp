// Persian Calender.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
void gotoxy(short,short);
void SetTable();
void Select();
void SystemDate();
void GotoDate();
void AddNotes();
void AddDays();
void ConvertToMiladi();
void SettingDefaultUL();
void SettingDefaultUR();
void SettingDefaultDR();
using namespace System::Globalization;
using namespace System;
using namespace std;
class calender{
private:
	int Year,Month,DayInMonth,DayInWeek;
	string DayName,MonthName;
public:
	calender()
	{
		SystemDate();
	}
	
	void operator + (double a)
	{
		AddDays(a);
	}
	
	void operator - (double a)
	{
		AddDays(-a);
	}
	
	int PassedDays();/*OK*/
	int RemainingDays();/*OK*/
	
	void ConvertToShamsi(int,int,int);/*OK*/
	void ConvertToMiladi(int,int,int);/*OK*/

	void SystemDate();/*OK*/
	
	int GetYear();/*OK*/
	int GetMonth();/*OK*/
	int GetDayInMonth();/*OK*/
	string GetMonthName();/*OK*/
	string GetDayName();/*OK*/
	
	void AddDays(double);/*OK*/

	void ShowEvents();/*OK*/

	void SetDate(int,int,int);

	void AddNotes();
	void ShowNotes();
}cl,cl1;


string calender::GetMonthName()
{
	return MonthName;
}
string calender::GetDayName()
{
	return DayName;
}
int calender::GetYear()
{
	return Year;
}
int calender::GetMonth()
{
	return Month;
}
int calender::GetDayInMonth()
{
	return DayInMonth;
}



void calender::SetDate(int Y,int M,int D)
{
	Year=Y;
	Month=M;
	DayInMonth=D;
	ConvertToMiladi(Year,Month,DayInMonth);
	ConvertToShamsi(Year,Month,DayInMonth);
}

void calender::SystemDate()
{
	PersianCalendar pc;
	DateTime d;	
	d=DateTime::Now;
	ConvertToMiladi(pc.GetYear(d),pc.GetMonth(d),pc.GetDayOfMonth(d));
	ConvertToShamsi(Year,Month,DayInMonth);
}

void calender::ConvertToShamsi(int Y,int M,int D)
{
	PersianCalendar pc;
	DateTime ddd;	
	ddd=DateTime::DateTime(Y,M,D);
	Year=pc.GetYear(ddd);
	Month=pc.GetMonth(ddd);
	DayInMonth=pc.GetDayOfMonth(ddd);
	
	DateTime dt(Y,M,D);
    	DayInWeek=(int)dt.DayOfWeek;
	
	switch(DayInWeek)
	{
		case 2:
			DayName="Seshanbe"; break;
		case 3:
			DayName="Chaharshanbe"; break;
		case 4:
			DayName="Panjshanbe"; break;
		case 5:
			DayName="Jome"; break;					 
		case 6:
			DayName="Shanbe"; break;
		case 0:
			DayName="Yekshanbe"; break;
		case 1:
			DayName="Doshanbe"; break;
	}
		
	switch(Month)
	{
		case 1:
			MonthName="Farvardin "; break;
		case 2:
			MonthName="Ordibehesht "; break;
		case 3:
			MonthName="Khordad "; break;
		case 4:
			MonthName="Tir "; break;					 
		case 5:
			MonthName="Mordad "; break;
		case 6:
			MonthName="Shahrivar "; break;
		case 7:
			MonthName="Mehr "; break;
		case 8:
			MonthName="Aban "; break;
		case 9:
			MonthName="Azar "; break;
		case 10:
			MonthName="Dey "; break;
		case 11:
			MonthName="Bahman "; break;					 
		case 12:
			MonthName="Esfand "; break;
	}
}

void calender::ConvertToMiladi(int Y,int M,int D)
{
	PersianCalendar pc;
	DateTime ddd=pc.ToDateTime(Y,M,D,0,0,0,0,0);
	Year=ddd.Year;
	Month=ddd.Month;
	DayInMonth=ddd.Day;

	DateTime dt(Year,Month,DayInMonth);
    	DayInWeek=(int)dt.DayOfWeek;
	switch(DayInWeek)
	{
		case 0:
			DayName="Sunday"; break;
		case 1:
			DayName="Monday"; break;
		case 2:
			DayName="Tuesday"; break;
		case 3:
			DayName="Wednesday"; break;					 
		case 4:
			DayName="Thursday"; break;
		case 5:
			DayName="Friday"; break;
		case 6:
			DayName="Sathurady"; break;
	}
	switch(Month)
	{
		case 1:
			MonthName="January "; break;
		case 2:
			MonthName="February "; break;
		case 3:
			MonthName="March "; break;
		case 4:
			MonthName="April "; break;					 
		case 5:
			MonthName="May "; break;
		case 6:
			MonthName="Jun "; break;
		case 7:
			MonthName="July "; break;
		case 8:
			MonthName="Aguest "; break;
		case 9:
			MonthName="September "; break;
		case 10:
			MonthName="October "; break;
		case 11:
			MonthName="November "; break;					 
		case 12:
			MonthName="December "; break;
	}
}


int calender::PassedDays()
{
	if(Month<=7)
		return (((Month-1)*31)+DayInMonth);
	if(Month>=8)
	{
		int m1=Month-6;
		return (((m1-1)*30)+DayInMonth)+186;
	}
}

int calender::RemainingDays()
{	
	int sw=0;
	PersianCalendar pc;
	if(pc.IsLeapYear(Year,1))
			sw=1;	
	return ((365+sw)-PassedDays());
}

void calender::AddDays(double ADD)
{
	ConvertToMiladi(Year,Month,DayInMonth);
	
	PersianCalendar pc;
	DateTime ddd;	
	ddd=DateTime::DateTime(Year,Month,DayInMonth);
	Year=pc.GetYear(ddd.AddDays(ADD));
	Month=pc.GetMonth(ddd.AddDays(ADD));
	DayInMonth=pc.GetDayOfMonth(ddd.AddDays(ADD));
	
	ConvertToMiladi(Year,Month,DayInMonth);
	DateTime dt(Year,Month,DayInMonth);
	ConvertToShamsi(Year,Month,DayInMonth);
    	DayInWeek=(int)dt.DayOfWeek;
	
	switch(DayInWeek)
	{
		case 2:
			DayName="Seshanbe"; break;
		case 3:
			DayName="Chaharshanbe"; break;
		case 4:
			DayName="Panjshanbe"; break;
		case 5:
			DayName="Jome"; break;					 
		case 6:
			DayName="Shanbe"; break;
		case 0:
			DayName="Yekshanbe"; break;
		case 1:
			DayName="Doshanbe"; break;
	}
		
	switch(Month){
		case 1:
			MonthName="Farvardin "; break;
		case 2:
			MonthName="Ordibehesht "; break;
		case 3:
			MonthName="Khordad "; break;
		case 4:
			MonthName="Tir "; break;					 
		case 5:
			MonthName="Mordad "; break;
		case 6:
			MonthName="Shahrivar "; break;
		case 7:
			MonthName="Mehr "; break;
		case 8:
			MonthName="Aban "; break;
		case 9:
			MonthName="Azar "; break;
		case 10:
			MonthName="Dey "; break;
		case 11:
			MonthName="Bahman "; break;					 
		case 12:
			MonthName="Esfand "; break;
	}
}

void calender::ShowEvents()
{
	char line[80];
	char Address[80]="C:\\\\";
	char temp[2];
	char tmp[20];
	int i;
	
	for(i=0;cl.GetMonthName()[i];++i)
		tmp[i]=cl.GetMonthName()[i];
	
	tmp[i-1]=NULL;
	
	itoa(cl.GetDayInMonth(),temp,10);
	strcat(Address,temp);
	strcat(Address,tmp);
	strcat(Address,".txt");
	ifstream file(Address);
	file.getline(line,80);
	cout<<line;
}


void calender::AddNotes()
{
	char note[200];
	char Address[80]="C:\\\\New Folder\\\\";
	char temp[4];
	itoa(((Year-1300)*10000)+((Month*100)+DayInMonth),temp,10);
	strcat(Address,temp);
	strcat(Address,".txt");
	cin.getline(note,100,'.');
	ofstream notes;
	notes.open(Address);
	notes<<note;
	notes.close();
}

void calender::ShowNotes()
{
	char note[500];
	char Address[80]="C:\\\\New Folder\\\\";
	char temp[4];
	itoa(((Year-1300)*10000)+((Month*100)+DayInMonth),temp,10);
	strcat(Address,temp);
	strcat(Address,".txt");
	ifstream notes;
	notes.open(Address);
	notes.getline(note,500);
	cout<<note;
	notes.close();
}

/*=========Main Function========*/
void main()
{
	system("cls");
	SetTable();
	SystemDate();
	Select();
}

/*=========SetTable=========*/
void SetTable()
{
	system("cls");
	int i,j;
	for(i=2;i!=12;++i)
		for(j=50;j!=81;++j) 
			if(i==2&&j==50){
				gotoxy(50,2);
				cout<<"É";
			}
			else if(i==2&&j==80){
				gotoxy(80,2);
				cout<<"»";
			}
			else if(i==11&&j==50){
				gotoxy(50,11);
				cout<<"È";
			}
			else if(i==11&&j==80){
				gotoxy(80,11);
				cout<<"¼";
			}
			else if(j==50){
				gotoxy(50,i);
				cout<<"º";
			}
			else if(j==80){
				gotoxy(80,i);
				cout<<"º";
			}
			else if(i==2||i==11){
				gotoxy(j,i);
				cout<<"Í";
			}
	for(i=2;i!=12;++i)
		for(j=0;j!=50;++j) 
			if(i==2&&j==0){
				gotoxy(1,2);
				cout<<"É";
			}
			else if(i==2&&j==49){
				gotoxy(49,2);
				cout<<"»";
			}
			else if(i==11&&j==0){
				gotoxy(1,11);
				cout<<"È";
			}
			else if(i==11&&j==49){
				gotoxy(49,11);
				cout<<"¼";
			}
			else if(j==0){
				gotoxy(1,i);
				cout<<"º";
			}
			else if(j==49){
				gotoxy(49,i);
				cout<<"º";
			}
			else if(i==2||i==11){
				gotoxy(j+1,i);
				cout<<"Í";
			}
		gotoxy(16,5);
		cout<<"*****EVENTS*****";
		gotoxy(16,8);
		cout<<"*****NOT ES*****";
		gotoxy(16,2);
		cout<<"Persian Calender";
		gotoxy(60,2);
		cout<<"Miladi Date";
		gotoxy(2,12);
		cout<<"1.Convert To Miladi";
		gotoxy(2,14);
		cout<<"2.System Date";
		gotoxy(2,16);
		cout<<"3.Go To Date";
		gotoxy(2,18);
		cout<<"4.Add Notes";
		gotoxy(2,20);
		cout<<"5.Add Days";
		gotoxy(2,22);
		cout<<"6.Exit";
		gotoxy(2,24);
		cout<<"Select:";
		gotoxy(45,23);
		cout<<"Developed By:";
		gotoxy(45,24);
		cout<<"S.M.Mozd Awar & S.M.Hashemi fard";
}

/*=========Select=========*/
void Select()
{
	int a;
	for(;;){
		gotoxy(10,24);
		cout<<"    ";
		gotoxy(10,24);
		cin>>a;
		cin.sync();
		if(a==2) 
			SystemDate();
		if(a==3)
			GotoDate();   
		if(a==5)
			AddDays();
		if(a==1)
			ConvertToMiladi();
		if(a==4)
			AddNotes();
		if(a==6)
			exit(0);
	}
}

/*============SystemDate==========*/
void SystemDate()
{
	string temp;
	cl.SystemDate();
	
	if(cl.GetDayInMonth()<=3)
	{
		if(cl.GetDayInMonth()==1)
			temp="st";
		else if(cl.GetDayInMonth()==2)
			temp="nd";
		else if(cl.GetDayInMonth()==3)
			temp="rd";
	}
	else if(cl.GetDayInMonth()>3 && cl.GetDayInMonth()<20)
	{
		temp="th";
	}
	else if(cl.GetDayInMonth()%10==1)
		temp="st";
	else if(cl.GetDayInMonth()%10==2)
		temp="nd";
	else if(cl.GetDayInMonth()%10==3)
		temp="rd";
	else
		temp="th";

	SettingDefaultUR();
	SettingDefaultUL();
	SettingDefaultDR();
	gotoxy(2,3);
	cout<<"Today is "<<cl.GetDayName()<<" "<<cl.GetDayInMonth()<<temp<<" of "<<cl.GetMonthName()<<"in year "<<cl.GetYear();
	gotoxy(2,4);
	cout<<cl.PassedDays()<<" Days Passed     AND   ";
	gotoxy(30,4);
	cout<<cl.RemainingDays()<<" Days Remaining";
	gotoxy(2,6);
	cl.ShowEvents();
	gotoxy(2,9);
	cl.ShowNotes();
}

/*=============GotoDate===========*/
void GotoDate()
{
	int y,m,d;
	string temp;
	SettingDefaultDR();
	gotoxy(40,13);
	cout<<"***Goto Date***";
	gotoxy(45,15);
	cout<<"Year: ";
	cin>>y;
	gotoxy(45,16);
	cout<<"Month: ";
	cin>>m;
	gotoxy(45,17);
	cout<<"Day In Month: ";
	cin>>d;
	cl.SetDate(y,m,d);
	
	if(cl.GetDayInMonth()<=3)
	{
		if(cl.GetDayInMonth()==1)
			temp="st";
		else if(cl.GetDayInMonth()==2)
			temp="nd";
		else if(cl.GetDayInMonth()==3)
			temp="rd";
	}
	else if(cl.GetDayInMonth()>3 && cl.GetDayInMonth()<20)
	{
		temp="th";
	}
	else if(cl.GetDayInMonth()%10==1)
		temp="st";
	else if(cl.GetDayInMonth()%10==2)
		temp="nd";
	else if(cl.GetDayInMonth()%10==3)
		temp="rd";
	else
		temp="th";
	
	SettingDefaultDR();
	SettingDefaultUL();
	gotoxy(2,3);
	cout<<"Today is "<<cl.GetDayName()<<" "<<cl.GetDayInMonth()<<temp<<" of "<<cl.GetMonthName()<<"in year "<<cl.GetYear();
	gotoxy(2,4);
	cout<<cl.PassedDays()<<" Days Passed     AND   ";
	gotoxy(30,4);
	cout<<cl.RemainingDays()<<" Days Remaining";
	gotoxy(2,6);
	cl.ShowEvents();
	gotoxy(2,9);
	cl.ShowNotes();
}

/*==============AddDays===========*/
void AddDays()
{
	double d;
	string temp;
	SettingDefaultDR();
	gotoxy(40,13);
	cout<<"***Add Days***";
	gotoxy(38,15);
	cout<<" Days To Be Added";
	gotoxy(38,16);
	cout<<"(negative for mines):";
	gotoxy(46,17);
	cin>>d;
	cl.AddDays(d);
	if(cl.GetDayInMonth()<=3)
	{
		if(cl.GetDayInMonth()==1)
			temp="st";
		else if(cl.GetDayInMonth()==2)
			temp="nd";
		else if(cl.GetDayInMonth()==3)
			temp="rd";
	}
	else if(cl.GetDayInMonth()>3 && cl.GetDayInMonth()<20)
	{
		temp="th";
	}
	else if(cl.GetDayInMonth()%10==1)
		temp="st";
	else if(cl.GetDayInMonth()%10==2)
		temp="nd";
	else if(cl.GetDayInMonth()%10==3)
		temp="rd";
	else
		temp="th";

	SettingDefaultDR();
	SettingDefaultUL();
	gotoxy(2,3);
	cout<<"Today is "<<cl.GetDayName()<<" "<<cl.GetDayInMonth()<<temp<<" of "<<cl.GetMonthName()<<"in year "<<cl.GetYear();
	gotoxy(2,4);
	cout<<cl.PassedDays()<<" Days Passed     AND   ";
	gotoxy(30,4);
	cout<<cl.RemainingDays()<<" Days Remaining";
	gotoxy(2,6);
	cl.ShowEvents();
	gotoxy(2,9);
	cl.ShowNotes();
}

/*===========ConvertToMiladi============*/
void ConvertToMiladi()
{
	int y,m,d;
	string temp;
	SettingDefaultUR();
	SettingDefaultDR();
	gotoxy(40,13);
	cout<<"***Date Conversion***";
	gotoxy(47,15);
	cout<<"Year: ";
	cin>>y;
	gotoxy(47,16);
	cout<<"Month: ";
	cin>>m;
	gotoxy(47,17);
	cout<<"Day In Month: ";
	cin>>d;
	SettingDefaultDR();
	SettingDefaultUR();
	cl1.ConvertToMiladi(y,m,d);
	if(cl1.GetDayInMonth()<=3)
	{
		if(cl1.GetDayInMonth()==1)
			temp="st";
		else if(cl1.GetDayInMonth()==2)
			temp="nd";
		else if(cl1.GetDayInMonth()==3)
			temp="rd";
	}
	else if(cl1.GetDayInMonth()>3 && cl1.GetDayInMonth()<20)
	{
		temp="th";
	}
	else if(cl1.GetDayInMonth()%10==1)
		temp="st";
	else if(cl1.GetDayInMonth()%10==2)
		temp="nd";
	else if(cl1.GetDayInMonth()%10==3)
		temp="rd";
	else
		temp="th";
	gotoxy(52,3);
	cout<<"Converted Date Of "<<y<<"/"<<m<<"/"<<d;
	gotoxy(62,5);
	cout<<cl1.GetDayName();
	gotoxy(62,7);
	cout<<cl1.GetDayInMonth()<<temp<<" OF ";
	gotoxy(60,8);
	cout<<cl1.GetMonthName()<<"IN ";
	gotoxy(63,9);
	cout<<cl1.GetYear();
}

/*===========AddNotes============*/
void AddNotes()
{
	SettingDefaultDR();
	gotoxy(40,13);
	cout<<"***Add Notes***";
	gotoxy(40,14);
	cl.AddNotes();
	SettingDefaultDR();
}

/*==========SettingDefaultUL=============*/
void SettingDefaultUL()
{
	int i,j;
	for(i=3;i<11;++i)
		for(j=2;j<49;++j){
			gotoxy(j,i);
			cout<<" ";
		}
	gotoxy(16,5);
	cout<<"*****EVENTS*****";
	gotoxy(16,8);
	cout<<"*****NOT ES*****";
}

/*==========SettingDefaultDR=============*/
void SettingDefaultDR()
{
	int i,j;
	for(i=12;i<20;++i)
		for(j=30;j<80;++j){ 
			gotoxy(j,i);
			cout<<" ";
		}
}

/*==========SettingDefaultUR=============*/
void SettingDefaultUR()		
{
	int i,j;
	for(i=3;i<11;++i)
		for(j=51;j<80;++j){
			gotoxy(j,i);
			cout<<" ";
		}
}

/*=========gotoxy===========*/
void gotoxy(short x,short y)
{
	static HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x-1;
	position.Y = y-1;

	SetConsoleCursorPosition( hStdout, position);
}