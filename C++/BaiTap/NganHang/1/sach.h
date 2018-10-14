#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * No description
 */
class Sach
{
	friend class QuanLy;
	friend class QuanLyMuonSach;
	// private section
	public:
		// class constructor
		Sach();
		Sach(char*,char*,int);
		void setGenMaSach(int x)
		{
			germaSach = x;
		}
		int getMa(){
			return maSach;
		}
	protected:
		int maSach;
		char DauSach[30];
		static int germaSach;
		char tacgia[30], tensach[30];
		
};

#endif // SACH_H

