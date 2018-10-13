#include<iostream>
#include<cmath>
using namespace std;
int ngto(int n)
{
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
				return 1;
}
int SumDigit(int n)
{
	int s=0;
	while(n!=0)
	{
		s=s+n%10;
		n=n/10;
	}
	return s;
}
int program(int n,int s)
{
	for(int i=pow(10,n-1);i<=pow(10,n)-1;i=i++)
		if(ngto(i)==1&&SumDigit(i)==s) return i;
										return 0;
}
main()
{
	int n,s;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter S:";
	cin>>s;
	if(program(n,s)!=0)	cout<<program(n,s)<<"	";
	else cout<<"Not have";
}
