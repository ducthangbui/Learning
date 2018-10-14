#include "sach.h" // class's header file

// class constructor
Sach::Sach()
{
	// insert your code here
}
int Sach::maS = 10000;
void Sach::Nhap()
{
	maSach = maS++;
	cin.ignore();
	cout<<"Nhap ten sach:";
	getline(cin,tenSach);
	cout<<"Nhap ten tac gia:";
	getline(cin,tacgia);
	cout<<"Nhap nam xuat ban:";
	cin>>nxb;
	do{
		cout<<"Nhap chuyen nganh:"
			<<"1.KHTN"<<endl
			<<"2.VH-NT"<<endl
			<<"3.Dien tu"<<endl
			<<"4.CNTT"<<endl;
			cin>>ChuyenNganh;
		}while(ChuyenNganh < 1 || ChuyenNganh > 4);
}

void Sach::Xuat()
{
	cout<<"Ma Sach:"<<maSach<<endl
		<<"Ten Sach:"<<tenSach<<endl
		<<"Ten tac gia:"<<tacgia<<endl
		<<"Nam xuat ban:"<<nxb<<endl
		<<"Chuyen Nganh:";
	if(ChuyenNganh == 1) cout<<"KHTN"<<endl;
	else if(ChuyenNganh == 2) cout<<"VH-NT"<<endl;
	else if(ChuyenNganh == 3) cout<<"Dien tu"<<endl;
	else if(ChuyenNganh == 4) cout<<"CNTT"<<endl;
}





