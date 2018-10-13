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
		if(x[v][i]&&chuaxet[i]) {truoc[i]=v;DFS(i);}
}
main()
{
	Init();
	int t=5,s=1;//duong di tu t -> s
	DFS(s);
	if(chuaxet[t]==0)//ton tai duong di
	{
		while(t!=s)
		{
			cout<<t<<' ';
			t=truoc[t];
		}
		cout<<s;
	}
	else cout<<"Khong ton tai duong di";
}