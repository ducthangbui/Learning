#include "bai36_a.h" // class's header file
#include<iostream>
using namespace std;
void Bai36::Nhap()
{
	cout<<"Nhap so thu nhat:";
	cin>>x;
	cout<<"Nhap so thu hai:";
	cin>>y;
}
float Bai36::Tong(float x,float y)
{
	return x+y;
}
float Bai36::Tich(float x,float y)
{
	return x*y;
}
void Bai36::PhanNguyen(float x,float y)
{
	cout<<endl<<"Phan nguyen cua "<<x<<" la:"<<(int)x;
	cout<<endl<<"Phan nguyen cua "<<y<<" la:"<<(int)y;
}
void Bai36::PhanDu(float x,float y)
{
	cout<<endl<<"Phan du cua "<<x<<" la:"<<x-(int)x;
	cout<<endl<<"Phan du cua "<<y<<" la:"<<y-(int)y;
}

void Bai36::Xuat()
{
	cout<<endl<<"Tong:"<<Tong(x,y)<<endl
		<<"Tich:"<<Tich(x,y)<<endl;
	Bai36::PhanDu(x,y);
	Bai36::PhanNguyen(x,y);
}

