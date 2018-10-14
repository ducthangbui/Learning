#ifndef BANDANGKY_H
#define BANDANGKY_H

#include <iostream>
#include <string.h>
using namespace std;
/*
 * No description
 */
class BanDangKy
{
	// private section
	public:
		// class constructor
		BanDangKy();
		BanDangKy(int maSV,char *nameSV,char *add,int sdt,int maMH,char *nameMon,int tongSoTiet,int loaiMH);
		// class destructor
		~BanDangKy();
		//void Nhap();
	public:
		int MaSV,SDT,MaMH,tongsotiet,loaiMonHoc;
		char nameSv[30],diachi[30],tenMonHoc[30];
		int ngayDK;
		int thangDK,namDK;
};

#endif // BANDANGKY_H

