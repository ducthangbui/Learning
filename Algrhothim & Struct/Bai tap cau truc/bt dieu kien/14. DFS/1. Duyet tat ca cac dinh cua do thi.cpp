#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100
int x[MAX][MAX],n,chuaxet[MAX];
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
	cout<<v<<' ';
	for(int i=1;i<=n;i++)
		if(x[v][i]&&chuaxet[i]) DFS(i);
}
main()
{
	Init();
	DFS();
}