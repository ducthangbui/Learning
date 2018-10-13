#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
#define MAX 100
stack <int> a,b;
int x[MAX][MAX],n,vt_le=1;
void Init()
{
	ifstream fi("mtke.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		fi>>x[i][j];
	fi.close();	
}
int Tontai()
{
	int le=0,tong=0;
	for(int i=1;i<=n;i++)
	{
		tong=0;
		for(int j=1;j<=n;j++) tong+=x[i][j];
		if(tong%2) {le++;vt_le=i;}
	}
	if(le==0) return 2;//co chu trinh
	if(le==2) return 1;//co duong di
	return 0;//ko ton tai
}
void Euler(int v=1)
{
	a.push(v);
	while(!a.empty())
	{
		int k=1;
		int q=a.top();
		for(int i=1;i<=n&&k;i++)
			if(x[i][q]) 
			{
				a.push(i);
				x[i][q]=x[q][i]=0;
				k=0;
			}
		if(k)
		{
			b.push(a.top());
			a.pop();
		}
	}
}
void Xuat()
{
	while(!b.empty())
	{
		cout<<b.top()<<' ';
		b.pop();
	}
}
main()
{
	Init();
	if(Tontai()!=0) Euler(vt_le);
	Xuat();
}