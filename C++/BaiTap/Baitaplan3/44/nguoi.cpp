#include "nguoi.h" // class's header file
#include <iostream>

using namespace std;

void Nguoi::Nhap(){
	cout << "Nhap ho va ten:";
	getline(cin,hoten);
	cout<<"Nhap email:";
	getline(cin,email);
	cout<<"Nhap SDT:";
	getline(cin,SDT); 
}


