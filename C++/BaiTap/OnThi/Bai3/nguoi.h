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
		// class destructor
		~Nguoi();
		friend istream & operator >> (istream &is,Nguoi &nguoi)
		{
			cout<<"Nhap ten:";
			is>>nguoi.hoten;
			cout<<"Nhap dia chi:";
			is>>nguoi.diachi;
			cout<<"Nhap sdt:";
			is>>nguoi.sdt;
			return is;
		}
	protected:
		char hoten[30];
		char diachi[30];
		int sdt;
};

#endif // NGUOI_H

