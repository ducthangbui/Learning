#ifndef MONHOC_H
#define MONHOC_H

#include <string.h>
#include <iostream>
using namespace std;
/*
 * No description
 */
class MonHoc
{
	friend class QuanLy;
	friend class BanDangKy;
	// private section
	public:
		// class constructor
		MonHoc();
		// class destructor
		~MonHoc();
		friend istream & operator >> (istream &is,MonHoc &monHoc)
		{
			cout<<"Nhap ten mon hoc:";
			is>>monHoc.tenMonHoc;
			cout<<"Nhap loai mon hoc"<<endl
				<<"1.Dai Cuong"<<endl
				<<"2.Co so nganh"<<endl
				<<"3.Chuyen nganh"<<endl
				<<"4.Tu chon"<<endl
				<<"Ban chon:";
			is>>monHoc.loaiMonHoc;
			cout<<"Nhap tong so tiet:";
			is>>monHoc.tongSoTiet;
			monHoc.maMonHoc = genmaMonHoc++;
			return is;
		}
		void setgenMaMonHoc(int x)
		{
			genmaMonHoc = x;
		}
		int getmaMonHoc()
		{
			return maMonHoc;
		}
	protected:
		int maMonHoc;
		static int genmaMonHoc;
		char tenMonHoc[30];
		int loaiMonHoc;
		int tongSoTiet;
};

#endif // MONHOC_H

