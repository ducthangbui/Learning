#include<iostream>
#include<fstream>
using namespace std;
int n,mt[100][100],truoc[100],d[100],s,t,chuaxet[100];
void Init()
{
	ifstream fi("dijkstra.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>mt[i][j];
		if(mt[i][j]==0) mt[i][j]=1000;
	}
	s=1;t=9;
	for(int i=1;i<=n;i++)
		{d[i]=mt[s][i];chuaxet[i]=1;truoc[i]=s;}
	d[s]=0;
	
	fi.close();
}
void dijkstra()
{
	int k=n-1;
	while(k--)
	{
		int min=1000,vt;
		for(int i=1;i<=n;i++)// tim dinh co k/c nho nhat
		{
			if(d[i]<min&&chuaxet[i])
			{
				min=d[i];vt=i;
			}
		}
		chuaxet[vt]=0;
		for(int i=1;i<=n;i++)// update
		{
			if(d[i]>d[vt]+mt[vt][i]&&mt[vt][i]&&chuaxet[i])
			{
				d[i]=d[vt]+mt[vt][i];
				truoc[i]=vt;
			}
		}
	}	
}
main()
{
	Init();
	dijkstra();
	cout<<"do dai duong di :"<<d[t]<<endl;
	cout<<"Duong di: ";
	do
	{
		cout<<t<<' ';
		t=truoc[t];
	}while(t!=s);
	cout<<s;
}