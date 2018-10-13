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
	SS.push(v);
	chuaxet[v]=0;
		while(!SS.empty())
		{
			int k=SS.front();SS.pop();
			for(int i=1;i<=n;i++)
				if(x[k][i]&&chuaxet[i]) 
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
int Dem_tp_lienthong()
{
	int dem=0;
	for(int i=1;i<=n;i++)
		if(chuaxet[i]) {dem++;DFS(i);}
	Reset();
	return dem;
}
main()
{
	Init();
	int slt=Dem_tp_lienthong();
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[i][j])
			{
				x[i][j]=x[j][i]=0;//xoa canh
				if(Dem_tp_lienthong()>slt) cout<<i<<"-"<<j<<endl;
				x[i][j]=x[j][i]=1;//phuc hoi
			}
	
}