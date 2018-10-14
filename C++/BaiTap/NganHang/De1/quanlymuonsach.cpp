#include "quanlymuonsach.h" // class's header file

// class constructor
//QuanLyMuonSach::QuanLyMuonSach()
//{
	// insert your code here
//}

void QuanLyMuonSach::Nhap(BanDoc &b)
{
	system("cls");
	int ktraDauSach, ktraMaSach, l=0;
	Sach sach[100];
	fstream fsach("SACH.DAT",ios::in);
	while(fsach)
	{
		sach[l].DocFile(fsach);
		l++;
	}  
	cout<<endl<<"Nhap thong tin muon sach cho ban doc"<<endl;
	b.Xuat();
	do
	{
		cout<<endl<<"Nhap so luong dau sach:";
		cin>>soDauSach;
	}while(soDauSach < 0 || soDauSach > 5);
	for(int i=0;i<soDauSach;i++)
	{
		do
		{
			ktraDauSach = 0, ktraMaSach = 0;
			cout<<endl<<"Nhap ma Sach:";
			cin>>maDauSach[i];
			for(int j=0;j<i;j++) if(maDauSach[i] == maDauSach[j]) ktraDauSach = 1;
			for(int k = 0;k<l;k++) if(sach[k].getMaSach() == maDauSach[i]) ktraMaSach = 1;
			
		}while(ktraDauSach == 1 || ktraMaSach == 0);
		cout<<endl<<"Nhap so luong sach:";
		cin>>soLuong[i];
		while(soLuong[i]<0 || soLuong[i]>3) 
		{
			cout<<endl<<"Nhap lai so luong:";
			cin>>soLuong[i];
		}
		tongsl += soLuong[i];
	}
}

void QuanLyMuonSach::GhiFile(BanDoc &b)
{
	fstream qlms("QLMS.DAT", ios::app);
	qlms<<b.maBanDoc<<endl
		<<soDauSach<<endl;
		for(int i=0;i<soDauSach;i++)
		qlms<<maDauSach[i]<<" ";
		qlms<<endl;
		for(int i=0;i<soDauSach;i++)
		qlms<<soLuong[i]<<" ";
		qlms<<endl;
		qlms<<tongsl<<endl;
		qlms.close();
	
}

void QuanLyMuonSach::DocFile(fstream &qlms)
{
	qlms>>bdi.maBanDoc;
	qlms.ignore();
	qlms>>soDauSach;
	qlms.ignore();
	for(int i=0;i<soDauSach;i++) qlms>>maDauSach[i];
	for(int i=0;i<soDauSach;i++) qlms>>soLuong[i];
	qlms>>tongsl;
}

void QuanLyMuonSach::Xuat(BanDoc &b)
{
	cout<<endl<<"Thong tin Ban doc"<<endl;
	b.Xuat();
	cout<<"So luong dau sach:"<<soDauSach;
	cout<<endl<<"Ma sach:";
	for(int i=0;i<soDauSach;i++)
	{
		cout<<"  "<<maDauSach[i];
	}
	cout<<endl<<"Tong so:"<<tongsl<<endl;
	
}
