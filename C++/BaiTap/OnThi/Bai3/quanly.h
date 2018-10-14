#ifndef QUANLY_H
#define QUANLY_H
#include <iostream>
#include "nguoi.h"
#include "nhanvien.h"
#include "mathang.h"
#include "danhsach.h"
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
/*
 * No description
 */
class QuanLy
{
	// private section
	public:
		// class constructor
		QuanLy();
		// class destructor
		~QuanLy();
		
		void loadNhanVien();
		void loadMatHang();
		void loadDanhSach();
		
		void addNhanVien();
		void addMatHang();
		void addDanhSach();
		
		void saveNhanVien();
		void saveMatHang();
		void saveDanhSach();
		
		void printNhanVien();
		void printMatHang();
		void printDanhSach();
		
		void menuNhanVien();
		void menuMatHang();
		void menuDanhSach();
		
		void display();
	protected:
		vector <NhanVien> listNhanVien;
		vector <MatHang> listMatHang;
		vector <DanhSach> listDanhSach;
		
};

#endif // QUANLY_H

