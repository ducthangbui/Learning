#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string.h>

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
	friend class DanhSach;
	friend class QuanLy;
	protected:
		int maNV;
		static int tangmaNV;
		int ngayKy;
	public:
		friend istream & operator >> (istream &is,NhanVien &nv)
		{
			Nguoi *a = reinterpret_cast<Nguoi*> (&nv);
			is >> *a;
			cout << "Nhap ngay ky hop dong:";
			nv.maNV = tangmaNV++;
			is >> nv.ngayKy;
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

int NhanVien::tangmaNV = 1000;

class MatHang{
	friend class DanhSach;
	friend class QuanLy;
	protected:
		int maHang;
		static int tangmaHang;
		char tenHang[30];
		int nhomHang;
		int giaBan;
		int soLuong;
	public:
		friend istream & operator >> (istream &is,MatHang &mh)
		{
			cout << "Nhap ten hang:";
			is >> mh.tenHang;
			cout<<"Nhap nhom hang"<<endl
				<<"1.Dien tu"<<endl
				<<"2.Dien lanh"<<endl
				<<"3.Thiet bi van phong"<<endl
				<<"Ban chon:";
			is >> mh.nhomHang;
			cout<<"Nhap gia ban:";
			is >> mh.giaBan;
			cout<<"Nhap so luong:";
			is>>mh.soLuong;
			mh.maHang = tangmaHang++;
			return is;
		}
		void settangmaHang(int x)
		{
			tangmaHang = x;
		}
		int getmaHang()
		{
			return maHang;
		}
};

int MatHang::tangmaHang = 1000;
/////////
class DanhSach{
	friend class QuanLy;
	protected:
		char hoten[30],tenHang[30];
		int maNV,maHang;
	public:
		DanhSach(){
			
		}
		DanhSach(int MaNV,char *ten,char *TenHang,int MaHang)
		{
			maNV = MaNV;
			strcpy(hoten,ten);
			strcpy(tenHang,TenHang);
			maHang = MaHang;
		}
};


/////////////
class QuanLy{
	protected:
		vector <NhanVien> listNhanVien;
		vector <MatHang> listMatHang;
		vector <DanhSach> listDanhSach;
	public:
		QuanLy();
		~QuanLy();
		
		void loadNhanVien();
		void loadMatHang();
		void loadDanhSach();
		
		void addNhanVien();
		void addMatHang();
		void addDanhSach();
		
		void saveNhanVien();
		void saveMatHang();
		void saveDanhSach();
		
		void printNhanVien();
		void printMatHang();
		void printDanhSach();
		
		void menuNhanVien();
		void menuMatHang();
		void menuDanhSach();
		
		void display();
		
};
//Ham cua QUanly
QuanLy::QuanLy()
{
	loadNhanVien();
	loadMatHang();
	loadDanhSach();
	cout<<"Bam phim bat ki de bat dau"<<endl;
	system("pause");
}

QuanLy::~QuanLy()
{
	saveNhanVien();
	saveMatHang();
	saveDanhSach();
	system("pause");
}

void QuanLy::loadDanhSach()
{
	fstream danhSach("QLBH.DAT",ios::in | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu QLBH.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu QLBH.DAT"<<endl;
	listDanhSach.clear();
	DanhSach tmp;
	while(danhSach.read(reinterpret_cast<char*>(&tmp),sizeof(DanhSach)))
	{
		listDanhSach.push_back(tmp);
	}
	danhSach.close();
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

void QuanLy::loadMatHang()
{
	fstream matHang("MH.DAT",ios::in | ios::binary);
	if(!matHang)
	{
		cerr<<"Tao du lieu MH.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu MH.DAT"<<endl;
	listMatHang.clear();
	
	MatHang tmp;
	while(matHang.read(reinterpret_cast<char*>(&tmp),sizeof(MatHang)))
	{
		listMatHang.push_back(tmp);
		tmp.settangmaHang(listMatHang[listMatHang.size()-1].getmaHang()+1);
	}
	matHang.close();
}

/////save

void QuanLy::saveDanhSach()
{
	fstream danhSach("QLBH.DAT",ios::out | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu QLBH.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu QLBH.DAT"<<endl;
	for(int i=0;i<listDanhSach.size();i++)
	danhSach.write(reinterpret_cast<char*>(&listDanhSach[i]),sizeof(DanhSach));
	danhSach.close();
}

void QuanLy::saveNhanVien()
{
	fstream nhanVien("NV.DAT",ios::out | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu NV.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu NV.DAT"<<endl;
	for(int i=0;i<listNhanVien.size();i++)
	nhanVien.write(reinterpret_cast<char*>(&listNhanVien[i]),sizeof(NhanVien));
	nhanVien.close();
}

void QuanLy::saveMatHang()
{
	fstream matHang("MH.DAT",ios::out | ios::binary);
	if(!matHang)
	{
		cerr<<"Tao du lieu MH.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu MH.DAT"<<endl;
	for(int i=0;i<listMatHang.size();i++)
	matHang.write(reinterpret_cast<char*>(&listMatHang[i]),sizeof(MatHang));
	matHang.close();
}

/////print
void QuanLy::printDanhSach()
{
	for(int i=0;i<listDanhSach.size();i++)
	{	
		cout<<endl<<"Ma NV:"<<listDanhSach[i].maNV<<endl
			<<"Ten:"<<listDanhSach[i].hoten<<endl
			<<"Ma Hang"<<listDanhSach[i].maHang<<endl
			<<"Ten Hang:"<<listDanhSach[i].tenHang<<endl;
	}
}
void QuanLy::printNhanVien()
{
	for(int i=0;i<listNhanVien.size();i++)
	{	
		cout<<endl<<"Ma NV:"<<listNhanVien[i].maNV<<endl
			<<"Ten:"<<listNhanVien[i].hoten<<endl
			<<"Dia chi:"<<listNhanVien[i].diachi<<endl
			<<"SDT:"<<listNhanVien[i].sdt<<endl;
	}
}

void QuanLy::printMatHang()
{
	for(int i=0;i<listMatHang.size();i++)
	{	
		cout<<endl<<"Ma MH:"<<listMatHang[i].maHang<<endl
			<<"Ten:"<<listMatHang[i].tenHang<<endl
			<<"Gia ban:"<<listMatHang[i].giaBan<<endl
			<<"So luong:"<<listMatHang[i].soLuong<<endl
			<<"Nhom Hang:";
		switch(listMatHang[i].nhomHang)
		{
			case 1:{
				cout<<"Dien tu"<<endl;
				break;
			}
			case 2:{
				cout<<"Dien lanh"<<endl;
				break;
			}
			case 3:{
				cout<<"Thiet bi van phong"<<endl;
				break;
			}
		}
	}
}

///add
void QuanLy::addDanhSach()
{
	system("cls");
	cout<<endl<<"Danh sach Nhan Vien"<<endl;
	this->printNhanVien();
	cout<<endl<<"-------------------------------------"<<endl
		<<"Nhap ma nhan vien:";
	int maNV;
	cin>>maNV;
	
	cout<<endl<<"----------------------------------------"<<endl;
	cout<<"Danh sach mat hang"<<endl;
	this->printMatHang();
	cout<<endl<<"--------------------------------------------"<<endl;
	
	cout<<"Nhap so luong hang ban duoc:"<<endl;
	int so;
	cin>>so;
	int maHang;
	for(int i=0;i<so;i++)
	{	
		cout<<"Nhap ma mat hang:";
		
		cin>>maHang;
	
		DanhSach tmp(listNhanVien[maNV-1000].maNV,listNhanVien[maNV-1000].hoten,
					listMatHang[maHang-1000].tenHang,listMatHang[maHang-1000].maHang);
		listDanhSach.push_back(tmp);
	}
}
void QuanLy::addNhanVien()
{
	NhanVien nv;
	cin>>nv;
	listNhanVien.push_back(nv);
}

void QuanLy::addMatHang()
{
	MatHang nv;
	cin>>nv;
	listMatHang.push_back(nv);
}
////menu
void QuanLy::menuDanhSach()
{
	int chon;
	do{
		system("cls");
		cout<<"MENU DanhSach"<<endl
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
				printDanhSach();
				system("pause");
				break;
			}
			case 2:{
				addDanhSach();
				system("pause");
				break;
			}
			case 3:{
				saveDanhSach();
				system("pause");
				break;
			}
		}
	}while(chon != 0);
}
void QuanLy::menuNhanVien()
{
	int chon;
	do{
		system("cls");
		cout<<"MENU NhanVien"<<endl
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
			}
			case 3:{
				saveNhanVien();
				system("pause");
				break;
			}
		}
	}while(chon != 0);
}

void QuanLy::menuMatHang()
{
	int chon;
	do{
		system("cls");
		cout<<"MENU MatHang"<<endl
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
				printMatHang();
				system("pause");
				break;
			}
			case 2:{
				addMatHang();
				system("pause");
				break;
			}
			case 3:{
				saveMatHang();
				system("pause");
				break;
			}
		}
	}while(chon != 0);
}

/////Menu
void QuanLy::display()
{
		int chon;
	do{
		system("cls");
		cout<<"MENU "<<endl
			<<"1.Menu NhanVien"<<endl
			<<"2.Menu MatHang"<<endl
			<<"3.Menu DanhSach"<<endl
			<<"0.KetThuc"<<endl
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
				menuMatHang();
				break;
			}
			case 3:{
					system("cls");
				menuDanhSach();
				break;
			}
		}
	}while(chon != 0);
}

/////Main
int main()
{
	QuanLy q;
	q.display();
	return 0;
}
