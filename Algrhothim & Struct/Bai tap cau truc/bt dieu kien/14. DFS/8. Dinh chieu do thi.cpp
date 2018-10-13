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
	for(int i=1;i<=n;i++)
		if(x[v][i]&&chuaxet[i]) DFS(i);
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
void Dfs(int v)
{
	chuaxet[v]=0;
	for(int i=1;i<=n;i++) 
		if(x[v][i]&&chuaxet[i]) 
		{
			x[i][v]=0;
			Dfs(i);
		}
		else if(x[v][i])
		{
			x[v][i]=0;
			x[i][v]=1;
		}
}
main()
{
	Init();
	//kiem tra canh cau
	int k=1;
	int slt=Dem_tp_lienthong();
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[i][j])
			{
				x[i][j]=x[j][i]=0;//xoa canh
				if(Dem_tp_lienthong()>slt) {k=0;cout<<"bb\n";}
				x[i][j]=x[j][i]=1;//phuc hoi
			}
	if(k)
	{
		Dfs(1);
		for(int i=1;i<=n;cout<<endl,i++)
		for(int j=1;j<=n;j++)
		cout<<x[i][j]<<' ';
	}

}