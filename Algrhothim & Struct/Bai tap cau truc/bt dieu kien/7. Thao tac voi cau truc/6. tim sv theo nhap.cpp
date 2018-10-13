#include<iostream>
#include<list>
using namespace std;
int kieu_sosanh=1;
struct sinhvien
{
	int id;
	char name[100];
	
	
	sinhvien(int id_=-1,char name_[]="!")
	{
		id=id_;
		strcpy(name,name_);
	}
	void Nhap()
	{
		cout<<"Nhap msv: ";cin>>id;
		cout<<"Nhap ten sv: ";fflush(stdin);gets(name);
	}
	void Xuat()
	{
		cout<<"Sinh vien "<<name<<endl;
		cout<<"Ma sinh vien : "<<id<<endl;
	}
	bool operator>(sinhvien p)
	{
		if(kieu_sosanh==1) 
			if(id>p.id) return true;
			else return false;
		if(kieu_sosanh==2)
			if(strcmp(name,p.name)==1) return true;
			else return false;
	}
	bool operator==(sinhvien p)
	{
		if(id==p.id&&strcmp(name,p.name)==0) return true;
		else return false;
	}
	
};
void thay_khoa(int k)
{
	// k=1 so sanh theo ID
	// k=2 so sanh theo ten
	if(k==1||k==2) kieu_sosanh=k;
	else cout<<"Khoa ko hop le!";
}
main()
{
	sinhvien SV1[100],SV2[100];
	list <sinhvien> T;
	int s1,s2;
	cout<<"Nhap sinh so sinh vien lop A:";cin>>s1;
	for(int i=1;i<=s1;i++)
	{
 		cout<<"\nNhap sv thu "<<i<<": \n";
 		SV1[i].Nhap();
 		cout<<"---------------\n";
	}
	cout<<"------------------ MENU ----------------\n\n";
	cout<<"1. Tim kiem theo msv\n";
	cout<<"2. Tim kiem theo ten\n";
	int luachon;
	cin>>luachon;
	if(luachon==1)
	{
		int msv;
		cout<<"Nhap msv: ";cin>>msv;
		cout<<"Ket qua tim kiem: \n";
		for(int i=1;i<=s1;i++)
			if(SV1[i].id==msv) SV1[i].Xuat();
	}
	if(luachon==2)
	{
		char ten[100];
		cout<<"Nhap ten: ";
		cout<<"Ket qua tim kiem: \n";
		fflush(stdin);gets(ten);
		for(int i=1;i<=s1;i++)
			if(strcmp(SV1[i].name,ten)==0) SV1[i].Xuat();
	}

	
}