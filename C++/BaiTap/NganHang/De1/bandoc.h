#ifndef BANDOC_H
#define BANDOC_H

#include <iostream>
#include "nguoi.h"
#include <fstream>

using namespace std;

/*
 * No description
 */
class BanDoc:public Nguoi
{
	friend class QuanLyMuonSach;
	// private section
	public:
		// class constructor
		BanDoc();
		void Nhap();
		void Xuat();
		void GhiFile(fstream &banDoc)
		{
			banDoc.write(reinterpret_cast <const char*> (this),sizeof(BanDoc));

		}
		void DocFile(fstream &banDoc)
		{
			banDoc.read(reinterpret_cast <char*>(this),sizeof(BanDoc));
		}
		int getMa(){
			return maBanDoc;
		}
	protected:
		int maBanDoc;
		static int ma;
		int loaiBanDoc;
};

#endif // BANDOC_H

