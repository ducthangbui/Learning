#include "sach.h" // class's header file

// class constructor
Sach::Sach()
{
	// insert your code here
}

Sach::Sach(char* author,char* bookname,int dauSach)
{
	int i=0;
	maSach = germaSach++;
	strcpy(tacgia,author);
	strcpy(tensach,bookname);
	if(dauSach == 1) strcpy(DauSach,"KHTN");
	else if(dauSach == 2) strcpy(DauSach,"VH-NT");
	else if(dauSach == 3) strcpy(DauSach,"Dien tu vien thong");
	else if(dauSach == 4) strcpy(DauSach,"CNTT");
	cout<<endl;
}

int Sach::germaSach=10000;

