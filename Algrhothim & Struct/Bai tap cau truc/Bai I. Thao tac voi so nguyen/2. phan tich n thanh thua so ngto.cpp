#include "iostream"
#include<math.h>
using namespace std;

bool ngto(int k)
{
	int r=int(sqrt(k));
	if(k<=1) return false;
	for(int i=2;i<=r;i++)
		if(k%i==0) return false;
	return true;
}

main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	for(int i=2;i<=n;i++)
	{
		while(ngto(i)&&n%i==0)//lay het cac ngto giong nhau
		{
			cout<<i<<"*";
			n/=i;
		}
	}
	cout<<'\b';
}