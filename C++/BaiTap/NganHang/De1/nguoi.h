#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>
using namespace std;
/*
 * No description
 */
class Nguoi
{
	// private section
	public:
		// class constructor
		Nguoi();
		void Nhap();
		void Xuat();
	protected:
		string hoten,diachi,sdt;
};

#endif // NGUOI_H

