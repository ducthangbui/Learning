#ifndef PHONG_H
#define PHONG_H
#include <iostream>
#include <fstream>

using namespace std;


/*
 * No description
 */
class Phong
{
	// private section
	public:
		void Nhap();
		void Xuat();
		void GhiFile();
		friend class BangSapXep;
	protected:
		int maphong;
		string kieuphong;
		int tienthue;
};

#endif // PHONG_H

