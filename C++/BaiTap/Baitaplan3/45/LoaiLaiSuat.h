#ifndef LOAILAISUAT_H
#define LOAILAISUAT_H
#include <iostream>
using namespace std;
class LoaiLaiSuat
{
	public:
		void Nhap();
		int Lai();
		int TongTien();
		void Xuat();
		void GhiFile();
		friend class SoTietKiem;
	protected:
		string loaiLS;
		int lai,tien;
		string mota;
};

#endif
