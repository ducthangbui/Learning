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
main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	int dem=0;
	for(int i=pow(10,n-1)+1;i<=(pow(10,n)-1);i++)
	{
		if(ngto(i))
		{
			dem++;
			cout<<i<<endl;
		} 
	}
	cout<<"\n So thoa man ngto " << n <<" chu so : "<<dem<<"\n";
	 cout<<i<<endl;
}
