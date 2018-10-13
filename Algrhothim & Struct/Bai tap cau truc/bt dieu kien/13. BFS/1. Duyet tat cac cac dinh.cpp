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
#include<queue>// day la phan chinh sua cua DFS -> copy cho nhanh -> ko doi ten DFS->BFS
queue <int> SS;
void DFS(int v=1)
{
	SS.push(v);chuaxet[v]=0;
		while(!SS.empty())
		{
			int k=SS.front();SS.pop();cout<<k<<' ';
			for(int i=1;i<=n;i++)
				if(x[k][i]&&chuaxet[i]) {chuaxet[i]=0;SS.push(i);}
		}
}
main()
{
	Init();
	DFS();
}