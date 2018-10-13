#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
#define MAX 100
stack <int> a,b;
int x[MAX][MAX],n,chuaxet[MAX],dem=0,duongdi[MAX];
void Init()
{
	ifstream fi("mtke.txt");
	fi>>n;
	for(int i=1;i<=n;chuaxet[i]=1,i++)
	for(int j=1;j<=n;j++)
		fi>>x[i][j];
	fi.close();	
}
void xuat()
{
	for(int i=1;i<=dem;i++) cout<<duongdi[i]<<' ';
}
void Haminton(int v,int v0)
{
	dem++;
	chuaxet[v]=0;
	duongdi[dem]=v;
	if(dem==n) 
		if(x[v][v0])	{cout<<"Chu trinh:\t";xuat();cout<<v0<<endl;}
		else {cout<<"Duong di:\t";xuat();cout<<endl;}
	else
		for(int i=1;i<=n;i++)
			if(x[v][i]&&chuaxet[i]) Haminton(i,v0);
	dem--;
	chuaxet[v]=1;
}
main()
{
	Init();
	int batdau=1;
	int ketthuc=1;
	Haminton(batdau,ketthuc);
}