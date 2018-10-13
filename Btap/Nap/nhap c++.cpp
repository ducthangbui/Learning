#include<iostream>
#include<cmath>
using namespace std;
int nt(int n)
{   
int i;
	if(n<2)return 0;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0)return 0;
	return 1;
}
 int tong (int a,int b)
  {
	return a+b;
  }
main()
{
	int a,b;
	cout<<"nhap a la:";
	cin>>a;
	cout<<"nhap b la:";
	cin>>b;
	cout<<tong(a,b)<<endl;
	    for(int i=2;i<=30;i++)
	    {
	    if(nt(i)==1) cout<<i;
	   }
	   
}
