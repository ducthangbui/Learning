#include "KhachHang.h"
#include <iostream>
#include <fstream>

using namespace std;

fstream khach("KH.DAT",ios::app | ios::in);

void KhachHang::Nhap(){
	Nguoi::Nhap();
	cout<<"Nhap ma khach hang:";
	cin>>maKH;
	cout<<"Nhap loai khach hang:";
	getline(cin,loaiKH);
}

void KhachHang::Xuat(){
	string ten,mail,dt,loai;
	int ma;
	while(getline(khach,ten) && getline(khach,mail) && getline(khach,dt) && getline(khach,loai)){
		khach>>ma;
		cout<<"Ho va ten:"<<ten<<endl
			<<"Email:"<<mail<<endl
			<<"SDT:"<<dt<<endl
			<<"Ma KH:"<<ma<<endl
			<<"Loai KH:"<<loai<<endl;
	}
}

void KhachHang::GhiFile(){
	khach<<hoten<<endl
		 <<email<<endl
		 <<sdt<<endl
		 <<maKH<<endl
		 <<loaiKH<<endl;
}




