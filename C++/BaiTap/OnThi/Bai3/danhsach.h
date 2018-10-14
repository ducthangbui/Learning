#ifndef DANHSACH_H
#define DANHSACH_H
#include <iostream>
#include <string.h>
using namespace std;
/*
 * No description
 */
class DanhSach
{
	friend class QuanLy;
	// private section
	public:
		// class constructor
		DanhSach();
		DanhSach(int MaNV,char *ten,int MaHang,char *TenHang,int SoLuong);
		// class destructor
		~DanhSach();
	protected:
		int maNV;
		char hoten[30];
		int maHang;
		char tenHang[30];
		int nhomHang;
		int soLuong;
};

#endif // DANHSACH_H

