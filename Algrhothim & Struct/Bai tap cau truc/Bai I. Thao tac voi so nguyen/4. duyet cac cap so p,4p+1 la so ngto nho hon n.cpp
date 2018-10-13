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
	int r=(n-1)/4;//Dieu kien dung  de 4p +1 ngto < n
	for(int i=2;i<=r;i++)
	{
		if(ngto(i)&&ngto(4*i+1))
		cout<<i<<' '<<4*i+1<<endl;
	}
}