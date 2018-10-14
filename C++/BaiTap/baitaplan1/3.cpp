#include<iostream>
#define pi 3.14159
using namespace std;
int duongkinh(int a)
{
	return 2*a;
}
float chuvi(int a)
{
	return 2*pi*a;
}
float dientich(int a)
{
	return pi*a*a;
}
main()
{
	int a;
	cout<<"Nhap R:";
	cin>>a;
	cout<<"Duong kinh:"<<duongkinh(a)<<endl;
	cout<<"Chu vi:"<<chuvi(a)<<endl;
	cout<<"Dien tich:"<<dientich(a)<<endl;
}
