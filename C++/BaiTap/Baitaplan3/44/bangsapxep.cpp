#include "bangsapxep.h" // class's header file
#include <iostream>
#include "khachhang.h"
#include "phong.h"
#include "nguoi.h"

using namespace std;

void BangSapXep::Nhap(KhachHang &k,Phong &p){
	k.Nhap();
	cout<<"Da nhap thong tin khach hang xong!!"<<endl;
	p.Nhap();
	cout<<endl<<"Da nhap xong !!!"<<endl;
}

void BangSapXep::Xuat(KhachHang &k,Phong &p){
	k.Xuat();
	p.Xuat();
}


