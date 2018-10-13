#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long n;
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	long long tong=0;
	while(n!=0)
	{
		tong=tong+n%10;
		n=n/10;
	}
	if(tong%9==0) cout<<9<<endl;
	else cout<<tong%9<<endl;
	}
}
