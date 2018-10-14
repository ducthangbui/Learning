#include "khachhang.h" // class's header file
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

fstream khach("KH.DAT", ios::in | ios::out | ios::app);

void KhachHang::Nhap(){
	fflush(stdin);
	Nguoi::Nhap();
	cout<<"Nhap ma khach hang:";
	getline(cin,maKhachHang);
	cout<<"Nhap kieu phong thue:";
	getline(cin,kieuphong);
	cout<<"Mo ta:";
	getline(cin,mota);
}

void KhachHang::GhiFile(){
	khach<<hoten<<endl
		<<email<<endl
		<<SDT<<endl
		<<maKhachHang<<endl
		<<kieuphong<<endl
		<<mota<<endl;
	cout<<"Da ghi xong"<<endl;
}

void KhachHang::Xuat(){
	string ten, mail, dt, ma, kieu, ta;
	if(!khach){
		cerr<<"Khong mo dc file!!!"<<endl;
		exit(1);
	} 
	cout<<"Danh sach khach hang la:"<<endl;
	while (getline(khach,ten) && getline(khach,mail) && getline(khach,dt))
	{
		//fflush(stdin);
		getline(khach,ma);
		getline(khach,kieu);
		getline(khach,ta);
		cout<<"Ho va ten:"<<ten<<endl
			<<"Email:"<<mail<<endl
			<<"SDT:"<<dt<<endl
			<<"Ma Khach Hang:"<<ma<<endl
			<<"Kieu phong thue:"<<kieu<<endl
			<<"Mo ta:"<<ta<<endl<<endl;
	}
}



