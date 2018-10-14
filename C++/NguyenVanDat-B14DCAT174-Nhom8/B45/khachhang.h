#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <string>
#include "nguoi.h"
//#include "quanly.h"
#define MAXSTK 30

class KhachHang : public Nguoi
{
	friend class QuanLy;
	public:
		KhachHang();
		KhachHang(char* name, char* type, char* num, char* email);
		~KhachHang();
		int GetMaKH(); // returns the value of MaKH
		static void SetgenMaKH(int x){
			genMaKH = x;
		}; // sets the value of genMaKH
		static int GetgenMaKH(){
			return genMaKH;
		}; // returns the value of genMaKH
	private:
		int MaKH;
		int MaSTK[MAXSTK];
		int SoSTK;
		double Tongtiengui;
		static int genMaKH;
		char LoaiKH[7];
	private:
	protected:
};

#endif
