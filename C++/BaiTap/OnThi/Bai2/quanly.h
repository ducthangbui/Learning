#ifndef QUANLY_H
#define QUANLY_H
#include <iostream>
#include "nguoi.h"
#include "sinhvien.h"
#include "monhoc.h"
#include "bandangky.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
 * No description
 */
 
class QuanLy
{
	// private section
	public:
		QuanLy();
		~QuanLy();
		
		void loadSinhVien();
		void loadMonHoc();
		void loadBanDangKy();
		
		void saveSinhVien();
		void saveMonHoc();
		void saveBanDangKy();
		
		void addSinhVien(SinhVien &);
		void addMonHoc();
		void addBanDangKy();
		
		void printSinhVien();
		void printMonHoc();
		void printBanDangKy();
		
		void menuSinhVien();
		void menuMonHoc();
		void menuBanDangKy();
		
		void SxTen();
		//void SxTgian();
		
		void display();
	protected:
		vector <BanDangKy> listBanDangKy;
		vector <SinhVien> listSinhVien;
		vector <MonHoc> listMonHoc;
};

#endif // QUANLY_H

