#ifndef QUANLYMUONSACH_H
#define QUANLYMUONSACH_H
#include "bandoc.h"


#include <string.h>

/*
 * No description
 */
class QuanLyMuonSach
{
	friend class QuanLy;
	// private section
	public:
		// class constructor
		QuanLyMuonSach();
		QuanLyMuonSach(int ma,char *name,char *add,char *bookname,char *author,int iSL);
		// class destructor
		~QuanLyMuonSach();
	protected:
		int TongSoLuongSach;
		int maBanDoc;
		char ten[30], dchi[30], tenSach[30], tacGia[30];
};

#endif // QUANLYMUONSACH_H

