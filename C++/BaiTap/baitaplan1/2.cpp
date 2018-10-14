#include<iostream>
using namespace std;
void Nhap(int &a,int &b,int &c)
{
	cout<<"Nhap vao 3 so nguyen:";
	cin>>a>>b>>c;
}
int Tong(int a,int b,int c)
{
	int s=a+b+c;
	return s;
}
float TrungBinh(int a,int b,int c)
{
	return (a+b+c)/3;
}
int Tich(int a,int b,int c)
{
	return a*b*c;
}
int Min(int a,int b,int c)
{
	int min=a;
	if(min>b) min=b;
		 if(min>c) min=c;
		return min;
}
int Max(int a,int b,int c)
{
	int max=a;
	if(max<b) max =b;
else	if(max<c) max=c;
	return max;
}
main()
{
	int a,b,c;
	Nhap(a,b,c);
	cout<<"Tong la:"<<Tong(a,b,c)<<endl;
	cout<<"Trung binh la:"<<TrungBinh(a,b,c)<<endl;
	cout<<"Nho nhat la:"<<Min(a,b,c)<<endl;
	cout<<"Lon nhat la:"<<Max(a,b,c)<<endl;
}
