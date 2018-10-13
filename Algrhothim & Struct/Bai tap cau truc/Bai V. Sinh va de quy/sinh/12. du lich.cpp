#include<iostream>
#define MAX 100
#include<fstream>
using namespace std;
ifstream fi;
int mt[100][100],x[100],n,kq[100],mini=10000,OK=1;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void Init()
{
	fi.open("du lich.txt");
		fi>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				fi>>mt[i][j];
			x[i]=i;
			kq[i]=0;
		}
	fi.close();
}
void next_per(int *x,int n,int &OK)
{
	int i=n-1;
	while(i>0&&x[i]>x[i+1]) i--;
	if(i==0) OK=0;
	else
	{
		int j=n;
		while(x[j]<x[i]) j--;
		int r=x[i];x[i]=x[j];x[j]=r;
		int a=i+1,b=n;
		while(a<b)
		{
			r=x[a];x[a]=x[b];x[b]=r;
			a++;b--;
		}
	}
}
void Update()
{
	int tong=0;
	for(int i=1;i<n;i++)
		tong+=mt[x[i]][x[i+1]];
	tong+=mt[x[n]][x[1]];// quay tro lai thanh pho ban dau
	if(tong<mini)
	{
		mini=tong;
		for(int i=1;i<=n;i++)// sao luu ket qua
			kq[i]=x[i];
	}
}
main()
{
	Init();
	while(OK)
	{
		Update();
		next_per(x,n,OK);
	}
	cout<<"Gia tien nho nhat:"<<mini<<endl;
	cout<<"Cach di:";Xuat(kq,n);
}
