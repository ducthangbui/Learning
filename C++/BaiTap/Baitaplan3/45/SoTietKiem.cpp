#include "SoTietKiem.h"
#include <iostream>
#include "LoaiLaiSuat.h"
using namespace std;

void SoTietKiem::Nhap(KhachHang &k,LoaiLaiSuat &l){
	k.Nhap();
	l.Nhap();
	cout<<"Nhap so thang dinh gui:";
	cin>>thanggui;
}

int SoTietKiem::TongTien(LoaiLaiSuat &l){
	return l.tien + (l.Lai() * this->thanggui); 
}
void SoTietKiem::Xuat(KhachHang &k,LoaiLaiSuat &l){
	k.Xuat();
	l.Xuat();
	cout<<"Tong tien"<<TongTien(l)<<endl;
}
