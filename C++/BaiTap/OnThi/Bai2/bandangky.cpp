#include "bandangky.h" // class's header file

// class constructor
BanDangKy::BanDangKy(int maSV,char *nameSV,char *add,int sdt,int maMH,char *nameMon,int tongSoTiet,int loaiMH)
{
	// insert your code here
	MaSV = maSV;
	strcpy(nameSv,nameSV);
	strcpy(diachi,add);
	SDT = sdt;
	MaMH = maMH;
	strcpy(tenMonHoc,nameMon);
	tongsotiet = tongSoTiet;
	loaiMonHoc = loaiMH;
	switch(loaiMonHoc)
		{
			case 1:{
				cout<<"Dai cuong"<<endl;
				break;
			}
			case 2:{
				cout<<"Co so nganh"<<endl;
				break;
			}
			case 3:{
				cout<<"Chuyen nganh"<<endl;
				break;
			}
			case 4:{
				cout<<"Tu chon"<<endl;
				break;
			}
		}
	}

BanDangKy::BanDangKy()
{
	
}
// class destructor
BanDangKy::~BanDangKy()
{
	// insert your code here
}


