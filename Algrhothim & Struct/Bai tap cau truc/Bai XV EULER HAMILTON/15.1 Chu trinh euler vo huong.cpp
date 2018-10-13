#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
fstream fi;
stack <int > x,e;
int a[100][100],n,u;

void init()
{
	fi.open("chutrinheulervohuong.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	fi>>a[i][j];
	fi.close();
}
int ktchan()
{
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<=n;j++)
		{
			s+=a[i][j];

		}	
			if(s%2)
			return 0;
	}
	return 1;
}
void euler(int v)
{
	x.push(v);
	while(!x.empty())
	{
		int dem=1;
		int k=x.top();
		//cout<<"nhan";
		for(int i=1;i<=n;i++)
		{
			if(a[k][i]==1)
	  		{
			  	x.push(i); 
				a[k][i]=0;a[i][k]=0;
				dem++;
				break;//Duyet lan luot 1 canh 1 trong moi vong if
			
			}
		}
		if(dem==1)
		{
			e.push(k);
			x.pop();
		}
	}
}
void xuat()
{
	while(!e.empty())
	{
		cout<<e.top()<<" ";
		e.pop();
	}
}
main()
{
	init();
	cout<<"Bat dau tai dinh U : ";
	cin>> u;
	if(ktchan())
	{
		euler(u);
	}
	xuat();
}