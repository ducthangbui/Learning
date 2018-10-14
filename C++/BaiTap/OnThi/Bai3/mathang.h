#ifndef MATHANG_H
#define MATHANG_H
#include <iostream>
using namespace std;
/*
 * No description
 */
class MatHang
{
	friend class QuanLy;
	
	// private section
	public:
		// class constructor
		MatHang();
		// class destructor
		~MatHang();
		
		friend istream &operator >> (istream &is,MatHang &mh)
		{
			cout<<"Nhap ten hang:";
			is >> mh.tenHang;
			cout<<"Nhap nhom hang"<<endl
				<<"1.Dien Tu"<<endl
				<<"2.Dien lanh"<<endl
				<<"3.Thiet bi van phong"<<endl
				<<"Ban chon:";
			is >> mh.nhomHang;
			mh.maHang = tangmaHang++;
			return is;
		}
		void settangmaHang(int x)
		{
			tangmaHang = x;
		}
		int getmaHang()
		{
			return maHang;
		}
	protected:
		int maHang;
		static int tangmaHang;
		char tenHang[30];
		int nhomHang;
		int soLuong;
};

#endif // MATHANG_H

