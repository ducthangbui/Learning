#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string.h>
#include "nguoi.h"
using namespace std;
/*
 * No description
 */
class SinhVien:public Nguoi
{
	friend class QuanLy;
	friend class BanDangKy;
	// private section
	public:
		friend istream & operator >> (istream &is,SinhVien &sv)
		{
			Nguoi *a= reinterpret_cast <Nguoi*> (&sv);
			is >> *a;
			cout<<"Nhap lop:";
			is>>sv.lop;
			sv.maSV = genMaSV++;
			return is;
		}
		friend ostream & operator << (ostream &os,SinhVien sv)
		{
			Nguoi *a = reinterpret_cast <Nguoi*> (&sv);
			os<<endl<<sv.maSV<<endl
			  << *a<<endl
			  <<sv.lop<<endl;
			return os;	
		}
		void setgenMaSV(int x)
		{
			genMaSV = x;
		}
		int getMaSV()
		{
			return maSV;
		}
		// class constructor
		SinhVien();
		// class destructor
		~SinhVien();
	protected:
		int maSV;
		static int genMaSV;
		char lop[30];
		
};

#endif // SINHVIEN_H

