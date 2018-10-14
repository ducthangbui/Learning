#include "phong.h" // class's header file
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

fstream phong("PH.DAT", ios::in | ios::out | ios::app);

void Phong::Nhap(){
	cin.ignore();
	cout<<"Nhap ma phong:";
	cin>>maphong;
	fflush(stdin);
	cout<<"Nhap kieu phong:";
	getline(cin,kieuphong);
	cout<<"Nhap chi phi:";
	cin>>tienthue;
}

void Phong::GhiFile(){
	phong<<maphong<<endl
		<<kieuphong<<endl
		<<tienthue<<endl;
}
void Phong::Xuat(){
	int tien;
	int id;
	string kieu;
	cout<<"Danh sach phong co tien thue >1tr la:"<<endl;
	if(!phong){
		cerr<<"Khong mo dc file!!!"<<endl;
		exit(1);
	}
	while(phong>>id>>kieu>>tien)
	{
		
	if(tien >= 1000000){
		cout<<"Ma phong:"<<id<<endl
			<<"Kieu phong:"<<kieu<<endl
			<<"Chi phi:"<<tien<<endl;
		}
	}
}


