#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <vector>

using namespace std;

class Nguoi{
	protected:
		char hoten[30];
		char diachi[30];
		int sdt;
	public:
		friend istream & operator >> (istream &is,Nguoi &nguoi)
		{
			cout<<"Nhap ten:";
			is>>nguoi.hoten;
			cout<<"Nhap dia chi:";
			is>>nguoi.diachi;
			cout<<"Nhap sdt:";
			is>>nguoi.sdt;
			return is;
		}
};

class NhanVien:public Nguoi{
	friend class PhanCong;
	friend class QuanLy;
	protected:
		int maNV;
		static int tangmaNV;
		char chuyenMon[30];
	public:
			friend istream & operator >> (istream &is,NhanVien &nv)
		{
			Nguoi *a = reinterpret_cast <Nguoi*> (&nv);
			is >> *a;
			cout<<"Nhap chuyen mon:";
			is>>nv.chuyenMon;
			nv.maNV = tangmaNV++;
			return is;
		}
		void settangmaNV(int x)
		{
			tangmaNV = x;

		}
		int getmaNV()
		{
			return maNV;
		}
};

int NhanVien::tangmaNV = 10000;

class DuAn{
	friend class PhanCong;
	friend class QuanLy;
	protected:
		int maDuAn;
		static int tangmaDuAn;
		char tenDuAn[30];
		int kieuDuAn;
		int tongKinhPhi;
	public:
			friend istream & operator >> (istream &is,DuAn &dv)
		{
			cout<<"Nhap ten du an:";
			is>>dv.tenDuAn;
			cout<<"Nhap kieu du an"<<endl
				<<"1.Nho"<<endl
				<<"2.Trung binh"<<endl
				<<"3.Lon"<<endl
				<<"Ban chon:";
			is>>dv.kieuDuAn;
			cout<<"Nhap tong kinh phi:";
			is>>dv.tongKinhPhi;
			dv.maDuAn = tangmaDuAn++; 
			return is;
		}
		void settangmaDuAn(int x)
		{
			tangmaDuAn = x;

		}
		int getmaDuAn()
		{
			return maDuAn;
		}
};
int DuAn::tangmaDuAn = 10000;
//////
class PhanCong{
	friend class QuanLy;
	protected:
		int maNV;
		char hoten[30];
		int maDuAn;
		char tenDuAn[30];
	public:
		PhanCong(){
			
		}
		PhanCong(int MaNV,char *ten,int MaDuAn,char *TenDA)
		{
			maNV = maNV;
			strcpy(hoten,ten);
			maDuAn=MaDuAn;
			strcpy(tenDuAn,TenDA);
		}
};
class QuanLy{
	protected:
		vector <NhanVien> listNhanVien;
		vector <DuAn> listDuAn;
		vector <PhanCong> listPhanCong;
	public:
		QuanLy(){
			loadNhanVien();
			loadDuAn();
			loadPhanCong();
			cout<<"Nhan phim bat ki de bat dau:"<<endl;
			system("pause");
		}
		~QuanLy(){
			saveNhanVien();
			saveDuAn();
			savePhanCong();
			system("pause");
		}
		
		void loadNhanVien();
		void loadDuAn();
		void loadPhanCong();
		
		void saveNhanVien();
		void saveDuAn();
		void savePhanCong();
		
		void printNhanVien();
		void printDuAn();
		void printPhanCong();
		
		void addNhanVien();
		void addDuAn();
		void addPhanCong();
		
		void menuNhanVien();
		void menuDuAn();
		void menuPhanCong();
		
		void display();
};

//Cac ham Quan ly
void QuanLy::loadPhanCong()
{
	fstream phanCong("PHANCONG.DAT",ios::in | ios::binary);
	if(!phanCong)
	{
		cerr<<"Tao du lieu PHANCONG.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu PHANCONG.DAT"<<endl;
	listPhanCong.clear();
	PhanCong tmp;
	while(phanCong.read(reinterpret_cast<char*>(&tmp),sizeof(PhanCong)))
	{
		listPhanCong.push_back(tmp);
	}
	phanCong.close();
}

void QuanLy::loadNhanVien()
{
	fstream nhanVien("NV.DAT",ios::in | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu NV.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu NV.DAT"<<endl;
	listNhanVien.clear();
	NhanVien tmp;
	while(nhanVien.read(reinterpret_cast<char*>(&tmp),sizeof(NhanVien)))
	{
		listNhanVien.push_back(tmp);
		tmp.settangmaNV(listNhanVien[listNhanVien.size()-1].getmaNV()+1);
	}
	nhanVien.close();
}

void QuanLy::loadDuAn()
{
	fstream duAn("DA.DAT",ios::in | ios::binary);
	if(!duAn)
	{
		cerr<<"Tao du lieu DA.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu DA.DAT"<<endl;
	listDuAn.clear();
	DuAn tmp;
	while(duAn.read(reinterpret_cast<char*>(&tmp),sizeof(DuAn)))
	{
		listDuAn.push_back(tmp);
		tmp.settangmaDuAn(listDuAn[listDuAn.size()-1].getmaDuAn()+1);
	}
	duAn.close();
}

///////save
void QuanLy::savePhanCong(){
	fstream phanCong("PHANCONG.DAT",ios::out | ios::binary);
	if(!phanCong)
	{
		cerr<<"Tao du lieu PHANCONG.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu PHANCONG.DAT"<<endl;
	for(int i=0;i<listPhanCong.size();i++)
	phanCong.write(reinterpret_cast<char*>(&listPhanCong[i]),sizeof(PhanCong));
	cout<<"Thanh cong"<<endl;
	phanCong.close();
}

void QuanLy::saveNhanVien(){
	fstream nhanVien("NV.DAT",ios::out | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu NV.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu NV.DAT"<<endl;
	for(int i=0;i<listNhanVien.size();i++)
	nhanVien.write(reinterpret_cast<char*>(&listNhanVien[i]),sizeof(NhanVien));
	cout<<"Thanh cong"<<endl;
	nhanVien.close();
}

void QuanLy::saveDuAn(){
	fstream duAn("DA.DAT",ios::out | ios::binary);
	if(!duAn)
	{
		cerr<<"Tao du lieu DA.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu DA.DAT"<<endl;
	for(int i=0;i<listDuAn.size();i++)
	duAn.write(reinterpret_cast<char*>(&listDuAn[i]),sizeof(DuAn));
	cout<<"Thanh cong"<<endl;
	duAn.close();
}

//////add
void QuanLy::addPhanCong()
{
	system("cls");
	cout<<"Danh sach nhan vien:"<<endl;
	printNhanVien();
	cout<<endl<<"-------------------------"<<endl	
		<<"Nhap ma nv:";
	int maNV;
	cin>>maNV;
	
	cout<<endl<<"-----------------------------"<<endl;
	cout<<"Danh sach du an"<<endl;
	printDuAn();
	
	int maDuAn;
	cout<<endl<<"Nhap so du an:";
	int so;
	cin>>so;
	for(int i=0;i<so;i++)
	{
		cout<<"Nhap ma du an:";
		cin>>maDuAn;
		PhanCong tmp(listNhanVien[maNV-10000].maNV,listNhanVien[maNV-10000].hoten,
						listDuAn[maDuAn-10000].maDuAn,listDuAn[maDuAn-10000].tenDuAn);
		listPhanCong.push_back(tmp);
	} 
}

void QuanLy::addNhanVien()
{
	NhanVien nv;
	cin>>nv;
	listNhanVien.push_back(nv);
}

void QuanLy::addDuAn()
{
	DuAn tmp;
	cin>>tmp;
	listDuAn.push_back(tmp);
}

///print
void QuanLy::printPhanCong()
{
	for(int i=0;i<listPhanCong.size();i++)
	{
		cout<<endl<<"Ma nv:"<<listPhanCong[i].maNV<<endl
			<<"Ten:"<<listPhanCong[i].hoten<<endl
			<<"Ma Du an"<<listPhanCong[i].maDuAn<<endl
			<<"Ten du an:"<<listPhanCong[i].tenDuAn<<endl;
	}
}

void QuanLy::printNhanVien()
{
	for(int i=0;i<listNhanVien.size();i++)
	{
		cout<<endl<<"Ma nv:"<<listNhanVien[i].maNV<<endl
			<<"Ten:"<<listNhanVien[i].hoten<<endl
			<<"Dia chi:"<<listNhanVien[i].diachi<<endl
			<<"SDT:"<<listNhanVien[i].diachi<<endl;
	}
}

void QuanLy::printDuAn()
{
	for(int i=0;i<listDuAn.size();i++)
	{
		cout<<endl<<"Ma Du an:"<<listDuAn[i].maDuAn<<endl
			<<"Ten du an:"<<listDuAn[i].tenDuAn<<endl
			<<"Tong kinh phi:"<<listDuAn[i].tongKinhPhi<<endl
			<<"Loai du an:";
		switch(listDuAn[i].kieuDuAn)
		{
			case 1:{
				cout<<"Nho"<<endl;
				break;
			}
			case 2:{
				cout<<"Trung binh"<<endl;
				break;
			}
			case 3:{
				cout<<"Lon"<<endl;
				break;
			}
		}
	}
}

//////menu
void QuanLy::menuPhanCong()
{
	int chon;
	do{
		system("cls");
		cout<<"MENU PhanCong"<<endl
			<<"1.Hien thi"<<endl
			<<"2.Them"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>chon;
		
		cin.clear();
		cin.get();
		
		switch(chon)
		{
			case 1:{
				printPhanCong();
				system("pause");
				break;
			}
			case 2:{
				addPhanCong();
				system("pause");
				break;
			}
			case 3:{
				savePhanCong();
				system("pause");
				break;
			}
		}
	}while(chon != 0);
}
void QuanLy::menuNhanVien()
{
	int chon;
	do
	{
		system("cls");
		cout<<"Menu NhanVien"<<endl
			<<"1.Hien thi"<<endl
			<<"2.Them"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>chon;
		
		cin.clear();
		cin.get();
		
		switch(chon)
		{
			case 1:{
				printNhanVien();
				system("pause");
				break;
			}
			case 2:{
				addNhanVien();
				system("pause");
				break;
			};
			case 3:{
				saveNhanVien();
				system("pause");
				break;
			}
		}
	}while(chon!=0);
}

void QuanLy::menuDuAn()
{
	int chon;
	do
	{
		system("cls");
		cout<<"Menu DuAn"<<endl
			<<"1.Hien thi"<<endl
			<<"2.Them"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>chon;
		
		cin.clear();
		cin.get();
		
		switch(chon)
		{
			case 1:{
				printDuAn();
				system("pause");
				break;
			}
			case 2:{
				addDuAn();
				system("pause");
				break;
			};
			case 3:{
				saveDuAn();
				system("pause");
				break;
			}
		}
	}while(chon!=0);
}

///menu
void QuanLy::display()
{
	int chon;
	do
	{
		system("cls");
		cout<<"Menu"<<endl
			<<"1.Menu Nhanvien"<<endl
			<<"2.menu du an"<<endl
			<<"3.menu phan cong"<<endl
			<<"0.exit"<<endl
			<<"Ban chon:";
		cin>>chon;
		
		cin.clear();
		cin.get();
		
		switch(chon)
		{
			case 1:{
				system("cls");
				menuNhanVien();
				
				break;
			}
			case 2:{
				system("cls");
				menuDuAn();
				break;
			};
			case 3:{
				system("cls");
				menuPhanCong();
				break;
			}
		}
	}while(chon!=0);
}

int main()
{
	QuanLy q;
	q.display();
	return 0;
}
