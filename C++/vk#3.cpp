#include<iostream>
using namespace std;
void nhap (int &a, int &b, int &c)
{
cout<<"nhap vao 3 so nguyen :"<<endl;
cin>>a>>b>>c;
}
void tong (int a, int b, int c)
{     
    int s;
    s=a+b+c;
    cout<<"tong la:"<<s<<endl;
}
void tb (int a, int b, int c)
{
    int tb;
    tb=(a+b+c)/3;
    cout<<"trung binh la:"<<tb<<endl;
}
void tich (int a, int b, int c)
{
    cout<<"tich la:"<<a*b*c<<endl;
}
void max (int a, int b, int c)
{
    int max;
    max=a;
    if(max<b) max=b;
    if(max<c) max=c;
   cout<<"so lon nhat la:"<<max<<endl; 
}
void min (int a, int b, int c)
{
 int  min;
