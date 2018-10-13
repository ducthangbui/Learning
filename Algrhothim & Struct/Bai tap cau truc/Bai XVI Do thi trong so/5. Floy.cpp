#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100
#define VOCUNG 100000
int mt[MAX][MAX],tg[100][100],n;
ifstream fi("dijkstra.txt");
void Init()
{
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>mt[i][j];
		if(!mt[i][j]) mt[i][j]=VOCUNG;
		tg[i][j]=i;
	}
	fi.close();
}
void Floy()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(mt[i][k]+mt[k][j]<mt[i][j])
		{
			mt[i][j]=mt[i][k]+mt[k][j];
			tg[i][j]=tg[k][j];
		}
}
void Duong_di(int a,int b)
{
//	cout<<"a= "<<a<<"\nb= "<<b<<endl;
	if(tg[a][b]==a) 
		if(mt[a][b]!=VOCUNG) cout<<b<<' '<<a<<' ';
		else  cout<<"Khong ton tai duong di!";
	else
	{
		cout<<b<<' ';
		Duong_di(a,tg[a][b]);
	}
}
main()
{
	Init();
	Floy();
	Duong_di(1,9);
	cout<<endl<<mt[1][9];
}