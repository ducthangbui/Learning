#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
using namespace std;
/*
 * No description
 */
class Rational
{
	// private section
	public:
		// class constructor
		Rational(int x=1,int y=1);
		void Nhap();
		void Cong(Rational,Rational);
		void Tru(Rational,Rational);
		void Nhan(Rational,Rational);
		void Chia(Rational,Rational);
		void RutGon();
		void Xuat()
		{
			if(mau!=1)
			cout<<tu<<"/"<<mau<<"\t"<<(float)tu/mau;
			else 	cout<<tu<<"\t"<<tu<<"."<<0;
		}
	private:
		int mau;
		int tu;
};

#endif // RATIONAL_H
