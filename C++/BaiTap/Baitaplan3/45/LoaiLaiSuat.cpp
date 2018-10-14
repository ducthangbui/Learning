#include "LoaiLaiSuat.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream LaiSuat("laisuat.DAT", ios::app | ios::in);

void LoaiLaiSuat::Nhap()
{
	cout<<"Nhap tien gui:";
	cin>>tien;
	cout<<"Nhap loai LS:";
	getline(cin,loaiLS);
	cout<<"Nhap lai:";
	cin>>lai;
	cout<<"Mo ta:";
	getline(cin,mota);
}

int LoaiLaiSuat::Lai(){
	return (lai / 100) * tien;
}

void LoaiLaiSuat::GhiFile(){
	LaiSuat<<tien<<endl
		<<loaiLS<<endl
		<<lai<<endl
		<<mota<<endl;
}
void LoaiLaiSuat::Xuat(){
	int tiengui,laisuat;
	string loai,mota;
	while(getline(LaiSuat,loai) && getline(LaiSuat,mota))
	{
		LaiSuat>>tiengui>>laisuat;
		cout<<"Tien gui:"<<tiengui<<endl
			<<"Loai LS:"<<loai<<endl
			<<"Lai:"<<laisuat<<endl
			<<"So tien lai trong 1 thang"<<Lai();
	}
}
