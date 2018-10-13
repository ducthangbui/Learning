#include<iostream>
#include<fstream>
#include<conio.h>
#include<list>
using namespace std;
#define MAX 100
int n,mt[MAX][MAX],chuaxet[MAX];
struct canh
{
	int dau,cuoi,value;
	void xuat()
	{
		cout<<"("<<dau<<','<<cuoi<<") = "<<value<<endl;
	}
	bool operator < (canh p)
	{
		if(p.value>value) return true;
		return false;
	}
};
list <canh> T,kq;
void nhap()
{
	ifstream fi("mtkc.txt");
	fi>>n;
	int k;
	canh a;
	for(int i=1;i<=n;chuaxet[i]=i,i++)
	for(int j=1;j<=n;j++)
	{
		fi>>k;
		if(j>i&&k) 
		{
			a.dau=i;a.cuoi=j;
			a.value=k;
			T.push_back(a);
		}
	}
	fi.close();
}
void Noi_cay(int a,int b)
{
	int x=chuaxet[a],y=chuaxet[b];
	if(y>x)for(int i=1;i<=n;i++) if(chuaxet[i]==y) chuaxet[i]=x;
	if(y<x)for(int i=1;i<=n;i++) if(chuaxet[i]==x) chuaxet[i]=y;
}
void Kruskal()
{
	T.sort();
	do
	{
		canh a=T.front();T.pop_front();//lay canh nho nhat
		if(chuaxet[a.dau]!=chuaxet[a.cuoi]) 
		{
			Noi_cay(a.dau,a.cuoi);
			kq.push_front(a);
		}
	}while(!T.empty());
}
main()
{
	nhap();
	Kruskal();
	while(!kq.empty())
	{
		cout<<kq.front().dau<<' '<<kq.front().cuoi<<endl;
		kq.pop_front();
	}

}
