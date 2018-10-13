#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,OK,k,dayso[MAX],truoc;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
bool test()
{
	truoc=0;
	for(int i=1;i<=k;i++)
	{
		if(dayso[x[i]]<dayso[truoc]) return false;
		truoc=x[i];
	}
	return true;
}
void Init_NC_(int *x,int &n,int &k,int &OK)
{
	do
	{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap k= ";cin>>k;
	if(k>n) cout<<"Nhap sai roi ! \n";
	}while(k>n);
	for(int i=1;i<=k;x[i]=i,i++);
	OK=1;
}

void next_com(int *x,int n,int k,int &OK)
{
	int i=k;
	while(x[i]==n-k+i) i--;
	if(i>0)
	{
		x[i]++;
		for(int j=i+1;j<=n;j++)
			x[j]=x[i]+j-i;
	}
	else OK=0;
}
main()
{
	Init_NC_(x,n,k,OK);
	dayso[0]=-100;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<" : ";cin>>dayso[i];
	}
	while(OK)
	{
		if(test())
		{
			for(int i=1;i<=k;i++)
				cout<<dayso[x[i]]<<' ';
			cout<<endl;
		}
		next_com(x,n,k,OK);
	}
}

