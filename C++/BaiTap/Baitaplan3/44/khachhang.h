#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "nguoi.h"
/*
 * No description
 */
class KhachHang: public Nguoi
{
	// private section
	public:
		void Nhap();
		void Xuat();
		void GhiFile();
		friend class BangSapXep;
	protected:
		string maKhachHang, kieuphong, mota;
};

#endif // KHACHHANG_H

