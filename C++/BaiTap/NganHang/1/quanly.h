#ifndef QUANLY_H
#define QUANLY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "bandoc.h"
#include "sach.h"
#include <cstdlib>
#include "quanlymuonsach.h"

using namespace std;

/*
 * No description
 */
class QuanLy
{
	// private section
	public:
		QuanLy(char *fnameBD="BD.DAT",char *fnameS="SACH.DAT",char *fnameQL="QLMS.DAT");
		// class destructor
		~QuanLy();
		
		void loadBanDoc(char *fname);
		void loadSach(char *fname);
		void loadQuanLyMuonSach(char *fname);
		
		void saveBanDoc(char *fname);
		void saveSach(char *fname);
		void saveQuanLyMuonSach(char *fname);
		
		void addBanDoc();
		void addSach();
		void addQuanLyMuonSach();
		
		void printBanDoc();
		void printSach(int);
		void printQuanLyMuonSach();
		
		void menuBanDoc();
		void menuSach();
		void menuQuanLyMuonSach();
		
		void SxTen();
		void SxSoLuongSach();
		void TimTen();
		
		void display();
	protected:
		int SoLuongSach[30];
		//int tongSL;
		
		char filenameBD[30], filenameS[30],filenameQL[30];
		vector <BanDoc> listBanDoc;
		vector <Sach> listSach;
		vector <QuanLyMuonSach> listQLMS;
};

#endif // QUANLY_H

