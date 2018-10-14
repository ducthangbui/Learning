#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "Nguoi.h"
class KhachHang:public Nguoi
{
	public:
		friend class SoTietKiem;
		void Nhap();
		void Xuat();
		void GhiFile();
	protected:
		int maKH;
		string loaiKH;
};

#endif
