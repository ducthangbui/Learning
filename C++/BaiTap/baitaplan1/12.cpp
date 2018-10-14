#include<iostream>
using namespace std;
int Amstrong(int n)
{
	int tmp=n,a;
	int s=0;
	while(n!=0)
	{
		a=n%10;
		s=s+a*a*a;
		n=n/10;
	}
	if(s==tmp) return 1;
				return 0;
}
main()
{
	int dem=0;
	for(int i=100;i<=999;i++)
	if(Amstrong(i))
	{
		dem++;
		cout<<i<<" ";
	}
	cout<<endl<<"Co tat ca "<<dem<<" so"<<endl;
}
