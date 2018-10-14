#include<iostream>
using namespace std;
void nhap (int &n)
{
 cout<<"nhap ban kinh la:";
 cin>>n;
}
void duongkinh (int n)
{
 int d;
 d=2*n;
 cout<<"duong kinh la:"<<d<<endl; 
}
void chuvi (int n)
{
 double pi,p;
 pi=3.14159;
 p=2*pi*n;
 cout<<"chu vi la:"<<p<<endl;
}
void dientich (int n)
{
 double pi,s;
 pi=3.14159;
 s=pi*pi*n;
 cout<<"dien tich la:"<<s;
}
int main()
{
int n;
nhap(n);
duongkinh(n);
chuvi(n);
dientich(n);
return 0;
}
