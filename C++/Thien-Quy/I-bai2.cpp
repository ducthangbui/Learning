#include<iostream>
#include<math.h>
using namespace std;
void TichNgto(int n)
{
	int i=2;
	while(i<=sqrt(n))
	{
		while(n%i==0)
		{
			if(n==i) cout<<i;
			else cout<<i<<"*";
			n=n/i;
		}
		i++;
	}
}
main()
{
	int n;
	cin>>n;
	TichNgto(n);
}

