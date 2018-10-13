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
	int le=0,tong,vao,ra;
	for(int i=1;i<=n;i++)
	{
		ra=vao=0;
		for(int j=1;j<=n;j++) ra+=x[i][j];
		for(int k=1;k<=n;k++) vao+=x[k][i];
		if(ra-vao==1) {le++;vt_le=i;}
		if(vao-ra==1) le++;
		if(abs(ra-vao)>1) return 0;
	}
	if(le==0) return 2;//co chu trinh
	if(le==2) return 1;//co duong di
}
void Euler(int v=1)
{
	a.push(v);
	while(!a.empty())
	{
		int k=1;
		int q=a.top();
		for(int i=1;i<=n&&k;i++)
			if(x[q][i]) 
			{
				a.push(i);
				x[q][i]=0;
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
	int k=Tontai();
	if(k==0) cout<<"\nKhong ton tai duong di hay chu trinh !\n";
	if(k==2) cout<<"\nChu trinh:\t";
	if(k==1) cout<<"\nDuong di:\t";
	if(k!=0) Euler(vt_le);
	Xuat();
}