#include "ps1.h" // class's header file
#include<iostream>
#include<cmath>
using namespace std;
// class constructor
PS1::PS1(int x,int y)
{

	tu=x;
	mau=y;
}

void PS1::Nhap()
{
	cout<<"Nhap tu:";
	cin>>tu;
	do{
	cout<<"Nhap mau:";
	cin>>mau;
	}while(mau==0);

}

void PS1::Cong(PS1 p1,PS1 p2)
{
	tu=p1.tu*p2.mau+p1.mau*p2.tu;
	mau=p1.mau*p2.mau;
}

void PS1::RutGon()
{
	int temp1=tu,temp2=mau;
		while(temp1!=0)
	{
		int tmp=temp1;
		temp1=temp2%temp1;
		temp2=tmp;
	}
	tu=tu/abs(temp2);
	mau=mau/abs(temp2);
	
}



