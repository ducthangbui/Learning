#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
using namespace std;
#define MAX 100
#define VOCUNG 100000
int n,chuaxet[MAX],d[MAX],s,truoc[MAX],t;
struct canh
{
	int dau,cuoi,value;
};
vector <canh> T;
void Init()
{
	ifstream fi("dijkstra.txt");
	fi>>n;
	canh a;
	for(int i=1;i<=n;chuaxet[i]=1,i++)
	for(int j=1;j<=n;j++)
	{
		fi>>a.value;
		if(a.value) 
		{
			a.dau=i;
			a.cuoi=j;
			T.push_back(a);
		}
	}
	fi.close();
	for(int i=1;i<=n;i++) {d[i]=VOCUNG;truoc[i]=0;}
	d[s]=0;
}
void BMF()
{
	int k=T.size();
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			if(d[T[j].cuoi]>d[T[j].dau]+T[j].value)
			{
				d[T[j].cuoi]=d[T[j].dau]+T[j].value;
				truoc [T[j].cuoi]=T[j].dau;
			}
	for(int j=0;j<k;j++)
		if(d[T[j].cuoi]>d[T[j].dau]+T[j].value) cout<<"Do thi chua chu trinh am !\n";
}
main()
{
	s=1;t=9;
	Init();
	BMF();
	cout<<"Duong di: ";
	do
	{
		cout<<t<<' ';
		t=truoc[t];
	}while(t!=s);
	cout<<s<<endl<<"Do dai : ";
	cout<<d[9];
}
