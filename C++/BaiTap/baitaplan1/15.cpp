#include<iostream>
using namespace std;
int fibo(int n)
{
	int fn=1,f0=0,f1=1;
	int i;
	if(n>2)
	{
		for(int i=2;i<n;i++)
		{
			f0=f1;
			f1=fn;
			fn=f0+f1;
		}
	}
	return fn;
}
main()
{
	int n;
	cin>>n;
	cout<<"Fibo thu "<<n<<" la:"<<fibo(n);
}
