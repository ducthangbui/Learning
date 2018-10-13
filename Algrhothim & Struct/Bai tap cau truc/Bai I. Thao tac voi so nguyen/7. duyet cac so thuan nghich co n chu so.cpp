#include "iostream"
#include <math.h>
using namespace std;
bool thuannghich(int k)
{
	int r=k,tn=0;
	while(r)
	{
		tn=tn*10+r%10;
		r/=10;
	}
	if(tn==k) return true;
	return false;
}
main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	int dem=0;
	for(int i=pow(10,n-1)+1;i<=(pow(10,n)-1);i++)
	{
		if(thuannghich(i))
		{
			dem++;
			cout<<i<<endl;
		} 
	}
	cout<<"\n So thoa man thuan nghich co " << n <<" chu so : "<<dem<<"\n";
}
