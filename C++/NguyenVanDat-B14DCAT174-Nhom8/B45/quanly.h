#ifndef QUANLY_H
#define QUANLY_H
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "khachhang.h"
#include "loailaisuat.h"
#include "sotietkiem.h"
#include <iostream>
using namespace std;

class QuanLy
{
	public:
		QuanLy(char *fnameKH="KH.DAT", char *fnameLLS="LOAILAISUAT.DAT", char *fnameSTK="SOTK.DAT");
		~QuanLy();
		void loadKH(char* fname);
		void loadLLS(char* fname);
		void loadSTK(char* fname);
		
		void saveKH(char* fname);
		void saveLLS(char* fname);
		void saveSTK(char* fname);
		
		void addKH();
		void addLLS();
		void addSTK();
		
		void removeKH(char* fname);
		void removeLLS(char* fname);
		void removeSTK(char* fname);
		
		void editKH(char* fname);
		void editLLS(char* fname);
		void editSTK(char* fname);
		
		void printKH(int option);
		void printLLS();
		void printSTK();
		
		void sortSTK();
		
		void makeReport();
		
		void menuKH();
		void menuLLS();
		void menuSTK();
		
		void display();
	private:
		char fileNameKH[50], fileNameLLS[50], fileNameSTK[50];
		vector <KhachHang> dsKH;
		vector <LoaiLaiSuat> dsLLS;
		vector <SoTietKiem> dsSTK;
	protected:
};

#endif
