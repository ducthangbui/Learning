#ifndef SOTIETKIEM_H
#define SOTIETKIEM_H
#include "LoaiLaiSuat.h"
#include "KhachHang.h"

class SoTietKiem
{
	public:
		void Nhap(KhachHang&,LoaiLaiSuat&);
		void Xuat(KhachHang&,LoaiLaiSuat&);
		int TongTien(LoaiLaiSuat&);
	protected:
		int thanggui;
};

#endif
