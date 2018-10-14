#ifndef BANDOC_H
#define BANDOC_H
#include "nguoi.h"
#include <string.h>
#include <iostream>

using namespace std;
/*
 * No description
 */
class BanDoc:public Nguoi
{
	friend class QuanLy;
	friend class QuanLyMuonSach;
	// private section
	public:
		// class constructor
		BanDoc();
		BanDoc(char*,char*,int);
		int getMa(){
			return maThe;
		}
		void setGenMaBD(int x)
		{
			gerMaThe = x;
		}
	protected:
		int maThe;
		static int gerMaThe;
};

#endif // BANDOC_H

