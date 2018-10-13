#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100
int x[MAX][MAX],n,chuaxet[MAX],truoc[MAX];
void Init()
{
	ifstream fi("mtke.txt");
	fi>>n;
	for(int i=1;i<=n;chuaxet[i]=1,i++)
	for(int j=1;j<=n;j++)
		fi>>x[i][j];
	fi.close();	
}
void DFS(int v=1)
{
	chuaxet[v]=0;
	for(int i=1;i<=n;i++)
		if(x[v][i]+x[i][v]&&chuaxet[i]) DFS(i);
}
void Reset()
{
	for(int i=1;i<=n;i++) chuaxet[i]=1;
}
int KT()
{
	for(int i=1;i<=n;i++) if(chuaxet[i]==1) return 0;
	return 1;
}
int lienthong_yeu()
{
	for(int i=1;i<=n;i++)
	{
		DFS(i);
		if(!KT()) return 0;
		Reset();
	}
	return 1;
}
main()
{
	Init();
	cout<<lienthong_yeu();
}