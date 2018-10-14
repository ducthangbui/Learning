#include "danhsach.h" // class's header file

// class constructor
DanhSach::DanhSach(int MaNV,char *ten,int MaHang,char *TenHang,int SoLuong)
{
	maNV = MaNV;
	strcpy(hoten,ten);
	maHang = MaHang;
	strcpy(tenHang,TenHang);
	//nhomHang = NhomHang;
	soLuong = SoLuong;
}
DanhSach::DanhSach()
{
	// insert your code here
}
// class destructor
DanhSach::~DanhSach()
{
	// insert your code here
}

