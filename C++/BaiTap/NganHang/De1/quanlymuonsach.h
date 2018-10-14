#ifndef QUANLYMUONSACH_H
#define QUANLYMUONSACH_H

#include <iostream>
#include <fstream>
#include "bandoc.h"
#include "sach.h"
#include <cstdlib>

using namespace std;

/*
 * No description
 */
class QuanLyMuonSach
{
	// private section
	public:
		// class constructor
		//QuanLyMuonSach();
		void Nhap(BanDoc&);
		void Xuat(BanDoc&);
		void setTongSL(int t)
		{
			tongsl = t;
		}
		int getTongSL()
		{
			return tongsl;
		}
		int getSods()
		{
			return soDauSach;
		}
		void setSods(int sods)
		{
			soDauSach = sods;
		}
		void GhiFile(BanDoc&);
		void DocFile(fstream&);
	protected:
		int soLuong[15], tongsl;
		int soDauSach, maDauSach[5];
		BanDoc bdi;
	
};

#endif // QUANLYMUONSACH_H

