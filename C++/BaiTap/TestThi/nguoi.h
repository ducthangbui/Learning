#ifndef NGUOI_H
#define NGUOI_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <iosmanip>
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
		friend istream & operator >> (istream &is,Nguoi &ng)
		{
			cout<<"Nhap ten:";
			fflush(stdin);
			is.getline(ng.ten,30);
			cout<<"Nhap dia chi:";
			is>>ng.diachi;
			cout<<"Nhap sdt:";
			is>>ng.sdt;
			return is;
		}
		friend ostream & operator << (ostream &os,Nguoi ng)
		{
			cout<<left<<setw(20)<<ng.ten<<setw(20)<<ng.diachi<<setw(20)<<ng.sdt;
			return os;
		}
		
		// class destructor
		~Nguoi();
	protected:
		char ten[30], diachi[30];
		int sdt;
};

#endif // NGUOI_H

