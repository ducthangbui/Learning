#include<iostream>
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
		cout<<"Ma sinh vien : "<<id;
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
	int s1,s2;
	cout<<"Nhap sinh so sinh vien lop A:";cin>>s1;
	for(int i=1;i<=s1;i++)
	{
 		cout<<"\nNhap sv thu "<<i<<": \n";
 		SV1[i].Nhap();
 		cout<<"---------------\n";
	}
}