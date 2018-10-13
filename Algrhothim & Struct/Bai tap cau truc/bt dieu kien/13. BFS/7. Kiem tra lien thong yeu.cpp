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
#include<queue>// day la phan chinh sua cua DFS -> copy cho nhanh -> ko doi ten DFS->BFS
queue <int> SS;
void DFS(int v=1)
{
	SS.push(v);
	chuaxet[v]=0;
		while(!SS.empty())
		{
			int k=SS.front();SS.pop();
			for(int i=1;i<=n;i++)
				if(x[k][i]+x[i][k]&&chuaxet[i]) 
				{
					chuaxet[i]=0;
					SS.push(i);
				}
		}
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