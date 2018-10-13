#include "iostream"
#include <math.h>
using namespace std;
bool ngto(int k)
{
	int r=int(sqrt(k));
	if(k<=1) return false;
	for(int i=2;i<=r;i++)
		if(k%i==0) return false;
	return true;
}
int tong_cacso(int k)
{
	int s=0;
	while(k)
	{
		s=s+k%10;
		k/=10;
	}
	return s;
}

main()
{
	int n,s;
	cout<<"Nhap n=";cin>>n;
	cout<<"Nhap s=";cin>>s;
	for(int i=1;i<n;i++)
		if(ngto(i)&&tong_cacso(i)==s)
			cout<<i<<endl;
}