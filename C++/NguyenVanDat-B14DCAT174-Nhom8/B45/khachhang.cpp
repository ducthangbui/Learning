#include "khachhang.h"

KhachHang::KhachHang():Nguoi()
{
	MaKH=0;
	strcpy(LoaiKH,"null");
	SoSTK=0;
	Tongtiengui=0;
}

KhachHang::KhachHang(char* name, char* type, char* num, char* email):Nguoi(name, num, email)
{
	MaKH=++genMaKH;
	strcpy(LoaiKH,type);
	SoSTK=0;
	Tongtiengui=0;
}

KhachHang::~KhachHang()
{
}

// returns the value of MaKH
int KhachHang::GetMaKH()
{
	return MaKH;
}

int KhachHang::genMaKH=10000;
