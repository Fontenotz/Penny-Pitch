#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char board[5][5]=
{
	'1','1','1','1','1',
	'1','2','2','2','1',
	'1','2','3','2','1',
	'1','2','2','2','1',
	'1','1','1','1','1'
};

int x,y,z;

void score();
void showboard();
void generation();

int main()
{
	srand(time(0));

	int w;
	cout<<"How many throws would you like to take?"<<endl;
	cin>>w;

	for(int v=0;v<w;v++)
	{
		system("pause");
		system("cls");
		generation();
		showboard();
		score();
		cout<<w-v-1<<" tosses remaining"<<endl;
	}
	return 0;
}


void generation()
{
	x=rand()%5;
	y=rand()%5;

	if (board[x][y]=='P')
		generation();
	else
		board[x][y]='P';
}


void score()
{
	if (x==0 || x==4 || y==0 || y==4)
	{
		cout<<"One point for that toss"<<endl;
		z++;
	}
	
	else if (x==2 && y==2)
	{
		cout<<"Three points for that toss"<<endl;
		z=z+3;
	}

	else
	{
		cout<<"Two points for that toss"<<endl;
		z=z+2;
	}
	cout<<"Total Score: "<<z<<endl;

}


void showboard()
{
	for (int a=0;a<5;a++)
	{
		for (int b=0;b<5;b++)
		{
			cout<<board[a][b]<<"  ";
		}
		cout<<endl;
	}
}