#include "rational.h" // class's header file
#include<iostream>
#include<cmath>
using namespace std;
// class constructor
Rational::Rational(int x,int y)
{

	tu=x;
	mau=y;
}

void Rational::Nhap()
{
	cout<<"Nhap tu:";
	cin>>tu;
	do{
	cout<<"Nhap mau:";
	cin>>mau;
	}while(mau==0);

}

void Rational::Cong(Rational p1,Rational p2)
{
	//Rational kqua;
	tu=p1.tu*p2.mau+p1.mau*p2.tu;
	mau=p1.mau*p2.mau;
}

void Rational::Tru(Rational p1, Rational p2)
{
	tu=p1.tu*p2.mau-p1.mau*p2.tu;
	mau=p1.mau*p2.mau;
}

void Rational::Nhan(Rational p1,Rational p2)
{
	tu=p1.tu*p2.tu;
	mau=p1.mau*p2.mau;
}

void Rational::Chia(Rational p1, Rational p2)
{
	tu=p1.tu*p2.mau;
	mau=p1.mau*p2.tu;
}
void Rational::RutGon()
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

