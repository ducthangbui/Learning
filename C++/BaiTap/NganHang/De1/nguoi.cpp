#include "nguoi.h" // class's header file

// class constructor
Nguoi::Nguoi()
{
	// insert your code here
}

void Nguoi::Nhap()
{
	cout<<"Nhap ho ten:";
	getline(cin,hoten);
	cout<<"Nhap dia chi:";
	getline(cin,diachi);
	cout<<"Nhap SDT:";
	getline(cin,sdt);
}

void Nguoi::Xuat()
{
	cout<<"Ho ten:"<<hoten<<endl
		<<"Dia chi:"<<diachi<<endl
		<<"SDT:"<<sdt<<endl;
}
