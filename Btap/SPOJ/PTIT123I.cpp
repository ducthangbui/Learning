#include<iostream>
#include<math.h>
using namespace std;
int ngto(long long n)
{
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
	return 1;
}
void ktra(long long n)
{
	do
	{
		int dem=0;
		cin>>n;
		if(n==0) return;
		for(long long i=n+1;i<=(2*n);i++)
		if(ngto(i)==1) dem++;
		cout<<dem<<endl;
	}
	while(n!=0);
}
main()
{
	long long n;
	ktra(n);
}
