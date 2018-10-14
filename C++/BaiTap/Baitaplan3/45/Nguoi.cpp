#include "Nguoi.h"
#include <iostream>

using namespace std;

void Nguoi::Nhap(){
	cout<<"Nhap ho va ten:";
	getline(cin,hoten);
	cout<<"Nhap Email:";
	getline(cin,email);
	cout<<"Nhap SDT:";
	getline(cin,sdt);
}

void Nguoi::Xuat(){
	cout<<"Ho va ten:"<<hoten<<endl
		<<"Email:"<<email<<endl
		<<"SDT:"<<sdt<<endl;
}
