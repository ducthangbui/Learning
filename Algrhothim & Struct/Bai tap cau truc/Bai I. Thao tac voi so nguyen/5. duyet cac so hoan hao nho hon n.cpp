//so hoan hao la so nguyen duong co tong cac uoc so nguyen duong be hon no va tong bang chinh no
#include "iostream"
#include <math.h>
using namespace std;
int tong_uoc(int k)
{
	int r=k/2,tong=1;
	for(int i=2;i<=r;i++)
		if(k%i==0) tong+=i;
	return tong;
}
main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	for(int i=2;i<n;i++)
		if(tong_uoc(i)==i) cout<<i<<endl;
}
