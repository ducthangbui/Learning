#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
fstream fi;
stack <int > x,e;
int a[100][100],n,u,k;

void init()
{
	fi.open("duongdieulervohuong.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	fi>>a[i][j];
	fi.close();
}
int ktle()
{
	int dem=0;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<=n;j++)
		{
			s+=a[i][j];

		}	
		if(s%2!=0)
		{
			k=i;
			dem++;
		}
	}
	if(dem==2)
	return 1;
	else
	return 0;
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
	if(ktle())
	{
		euler(k);
	}
	else
	cout<<"Khong co gi :D ";
	xuat();
}