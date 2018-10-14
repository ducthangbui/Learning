#include "quanlymuonsach.h" // class's header file

// class constructor
QuanLyMuonSach::QuanLyMuonSach()
{
	// insert your code here
}

QuanLyMuonSach::QuanLyMuonSach(int ma,char *name,char *add,char *bookname,char *author,int iSL)
{
	//BanDoc b;
	maBanDoc = ma;
	strcpy(ten,name);
	strcpy(dchi,add);
	//Sach s;
	strcpy(tenSach,bookname);
	strcpy(tacGia,author);
	TongSoLuongSach = iSL;
}
//int QuanLyMuonSach::TongSoLuongSach=0;
// class destructor
QuanLyMuonSach::~QuanLyMuonSach()
{
	// insert your code here
}

