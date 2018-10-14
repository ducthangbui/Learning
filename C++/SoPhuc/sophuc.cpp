#include "sophuc.h" // class's header file
#include<iostream>
using namespace std;
// class constructor
sophuc::sophuc(int x,int y)
{
	// insert your code here
	setThuc(x);
	setAo(y);
}
void sophuc::setThuc(int x)
{
	thuc=x;
}
void sophuc::setAo(int y)
{
	ao=y;
}
int sophuc::getThuc()
{
	return thuc;
}
int sophuc::getAo()
{
	return ao;
}
void sophuc::Tong(sophuc p1,sophuc p2)
{
	sophuc kqua;
	kqua.setThuc(p1.getThuc()+p2.getThuc());
	kqua.setAo(p1.getAo()+p2.getAo());
	//cout<<endl<<kqua.getThuc();
	kqua.Display();
}
void sophuc::Input()
{
	int x,y;
	cout<<"Nhap phan thuc:";
	cin>>x;
	setThuc(x);
	cout<<"Nhap phan ao:";
	cin>>y;
	setAo(y);
}
void sophuc::Display()
{
	cout<<getThuc()<<"+"<<getAo()<<"i";
}
