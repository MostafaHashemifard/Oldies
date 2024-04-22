#include"iostream.h"
#include"conio.h"
void main()
{
	clrscr();
	int a=0,b=0,t,c=0,m,s=1;
	int i,k,j=2,cell[100];
	int *rect;
	do{
		textbackground(1);
		window(1,1,80,25);
		clrscr();
		gotoxy(1,12);
		cout<<"Please enter degree of the rectangle (maximum degree is 9,only for odd numbers): ";
		gotoxy(39,13);
		cin>>m;
		k=m;
	}while(m%2==0||m>9||m<=0);
	rect=new int[(k*k)+1];
	i=((m/2)+1)*m;
	clrscr();

	for(t=1;t!=100;++t)
		cell[t]=0;

	rect[i]=1;
	cell[i]=1;
	clrscr();

	while(j<=k*k){
		if(i==k){
			if(cell[i+((i-2)*k)+1]==0){
				rect[i+((i-2)*k)+1]=j;
				cell[i+((i-2)*k)+1]=1;
				i=i+((i-2)*k)+1;
			}
			else if(cell[i+((i-2)*k)+1]==1){
				rect[i-1]=j;
				cell[i-1]=1;
				--i;
			}
		}
		else if(i<k&&i>=1){
			if(cell[k*(k-1)+(i+1)]==0){
				rect[k*(k-1)+(i+1)]=j;
				cell[k*(k-1)+(i+1)]=1;
				i=k*(k-1)+(i+1);
			}
			else if(cell[k*(k-1)+(i+1)]==1){
				rect[i-1]=j;
				cell[i-1]=1;
				--i;
			}
		}

		else if(i%k==0){
			if(cell[i-((k*2)-1)]==0){
				rect[i-((k*2)-1)]=j;
				cell[i-((k*2)-1)]=1;
				i=i-((k*2)-1);
			}
			else if(cell[i-((k*2)-1)]==1){
				rect[i-1]=j;
				cell[i-1]=1;
				--i;
			}
		}
		else{
			if(cell[i-(k-1)]==0){
				rect[i-(k-1)]=j;
				cell[i-(k-1)]=1;
				i=i-(k-1);
			}
			else if(cell[i-(k-1)]==1){
				rect[i-1]=j;
				cell[i-1]=1;
				--i;
			}
		}
		++j;
	}




	while(a!=m){
		while(b!=(m*3)+1){
			if(a==0&&b==0){
				gotoxy(1,1);
				cout<<"Ú";
			}
			else if(a==0&&b==m*3){
				gotoxy((m*3)+1,1);
				cout<<"¿";
			}
			else if(b==0)
				cout<<"Ã";
			else if(a==0 && b%3==0)
				cout<<"Â";
			else if(b==m*3)
				cout<<"´";
			else if(a!=0 && b%3==0)
				cout<<"Å";
			else
				cout<<"Ä";
			++b;
		}
		cout<<"\n";
		while(c!=m+1){
		cout<<"³  ";
		++c;
		}
	       cout<<"\n";
	       ++a;
	       b=0;
	       c=0;
	}

	for(a=0;a!=(m*3)+1;++a){
		if(a==0){
			gotoxy(1,(m*2)+1);
			cout<<"À";
		}
		else if(a==m*3){
			gotoxy((m*3)+1,(m*2)+1);
			cout<<"Ù";
		}
		else if(a%3==0)
			cout<<"Á";
		else
			cout<<"Ä";
	}
	for(a=2;a<=m*2;a+=2)
		for(b=2;b<=m*3;b+=3){
		gotoxy(b,a);
		cout<<rect[s];
		++s;
	}

getch();
}