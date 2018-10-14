#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include "nguoi.h"
using namespace std;
/*
 * No description
 */
class NhanVien:public Nguoi
{
	friend class QuanLy;
	// private section
	public:
		// class constructor
		NhanVien();
		// class destructor
		~NhanVien();
		friend istream &operator >> (istream &is,NhanVien &nv)
		{
			Nguoi *a = reinterpret_cast <Nguoi*> (&nv);
			is >> *a;
			cout<<"Nhap ngay ky hop dong:";
			is >> nv.ngayKy;
			nv.maNV = tangmaNV++;
			return is; 
		}
		
		void settangmaNV(int x)
		{
			tangmaNV = x;
		}
		
		int getmaNV()
		{
			return maNV;
		}
	protected:
		int maNV;
		static int tangmaNV;
		int ngayKy;
		
};

#endif // NHANVIEN_H

