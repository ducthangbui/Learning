#include<iostream>
#include<math.h>
using namespace std;
long ngto(long long n)
{
	long long m=sqrt(n);
	if(n<2) return 0;
	for(int i=2;i<=m;i++)
	if(n%i==0) return 0;
	return 1;
}
int main()
{
	long long n;
	long dem;
	long a[100000],na=0;
	for(int i=2;i<2*123456;i++)
	if(ngto(i)==1) a[na++]=i;
	while(-1)
	{
		cin>>n;
		if(n==0) break;
		dem=0;
		for(int j=0;j<na;j++)
		if(a[j]>n && a[j]<=(2*n)) dem++;
		cout<<dem;
		cout<<endl;
	}
	return 0;
}
