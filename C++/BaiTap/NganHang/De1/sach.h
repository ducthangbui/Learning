#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <fstream>

using namespace std;

/*
 * No description
 */
class Sach
{
	friend class QuanLyMuonSach;
	// private section
	public:
		// class constructor
		Sach();
		void Nhap();
		void Xuat();
		void GhiFile(fstream &sach){
			sach.write( reinterpret_cast<const char*>(this), sizeof(Sach));
		}
		void DocFile(fstream &sach)
		{
			sach.read( reinterpret_cast <char*> (this), sizeof(Sach));
		}
		int getMaSach()
		{
			return maSach;
		}
	protected:
		static int maS;
		int maSach;
		int ChuyenNganh,nxb;
		string tenSach, tacgia;
};

#endif // SACH_H

