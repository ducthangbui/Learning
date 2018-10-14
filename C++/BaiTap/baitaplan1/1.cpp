#include<iostream>
using namespace std;
//float a,b;
float tong(float a,float b)
{
	return a+b;
}
float tich(float a,float b)
{
	return a*b;
}
void PhanNguyen(float a,float b)
{
	int c,d;
	c=(int )a;
	d=(int)b;
	cout<<"\nPhan nguyen cua a la:"<<c<<"\nPhan nguyen cua b la:"<<d;
}
int ktra(float a)
{
	if(a==(int)a) return 1;
					return 0;
}
void PhanDu(float a,float b)
{
	float c,d;
	c=a-(int)a;
	d=b-(int)b;
	cout<<"\nPhan du cua a la:"<<c;
	cout<<"\nPhan du cua b la:"<<d;
}
main()
{
	float a,b;
	cin>>a>>b;
	cout<<"Tong="<<tong(a,b)<<endl;
	cout<<"Tich="<<tich(a,b)<<endl;
	PhanNguyen(a,b);
	PhanDu(a,b);
}
