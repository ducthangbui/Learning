#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>

using namespace std;
/*
 * No description
 */
class Nguoi
{
	friend class QuanLyMuonSach;
	// private section
	public:
		// class constructor
		Nguoi();
	protected:
		char hoten[30];
		char diachi[30];
		int sdt;
};

#endif // NGUOI_H

