#ifndef PS1_H
#define PS1_H
#include<iostream>
using namespace std;
/*
 * No description
 */
class PS1
{
	// private section
	public:
		// class constructor
		PS1(int x=1,int y=1);
		void Nhap();
		void Cong(PS1,PS1);
		void RutGon();
		void Xuat()
		{
			if(mau!=1)
			cout<<tu<<"/"<<mau;
			else 	cout<<tu;
		}
	protected:
		int mau;
		int tu;
};

#endif // PS1_H

