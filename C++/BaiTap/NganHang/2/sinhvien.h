#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <stdio.h>
#include "nguoi.h"
/*
 * No description
 */
class SinhVien:public Nguoi
{
	// private section
	public:
		// class constructor
		SinhVien();
		void Nhap();
		void Xuat();
		int getMa()
		{
			return MSV;
		}
		void setMa(int ma)
		{
			MSV = x;
		}
		// class destructor
		~SinhVien();
	protected:
		int MSV;
		static int maSV;
		
};

#endif // SINHVIEN_H

