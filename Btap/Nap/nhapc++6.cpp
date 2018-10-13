#include<iostream>
using namespace std;
main()
{
	int n,a[6];
	cout<<"nhap n la :";
	cin>>n;
	int i=0;
	    while(n>0)
	         {
	         	a[i]=n%10;
	         	i++;
	           //cout<<n%10<<"   ";
				n=n/10;
             }
    for(int j=i-1;j>=0;j--)
    {
    	cout<<a[j]<<"   ";
    }
}
