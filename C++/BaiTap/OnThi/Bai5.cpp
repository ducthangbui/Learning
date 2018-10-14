#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string.h>
using namespace std;

class Nguoi{
	public:
		
	protected:
		char hoten[30];
		char diachi[30];
		int sdt;
};

class NhanVien:public Nguoi{
	friend class QuanLy;
	friend class DanhSach;
	public:
		
		//Nap cong toan tu nhap
		friend istream &operator >> (istream &is,NhanVien &nv)
		{
			cout<<"Nhap ten:";
			is >> nv.hoten;
			cout<<"Nhap dia chi:";
			is >> nv.diachi;
			cout<<"Nhap sdt:";
			is >> nv.sdt;
			cout<<"Nhap bac luong:";
			is >> nv.bacLuong;
			nv.maNV = tangmaNV++;
			return is;
		}
		//Nhap tangmaNV
		void settangmaNV(int x)
		{
			tangmaNV = x;
		}
		//lay ma nv
		int getmaNV(){
			return maNV;
		}
		
	protected:
		int maNV;
		static int tangmaNV;
		int bacLuong;
};

int NhanVien::tangmaNV = 1000;

class PhongBan{
	friend class QuanLy;
	friend class DanhSach;
	protected:
		int maPhong;
		static int tangmaPhong;
		char mota[30];
		int hesocongviec;
	public:
		friend istream &operator >> (istream &is,PhongBan &phongBan)
		{
			cout << "Nhap he so cong viec:";
			is >> phongBan.hesocongviec;
			cout << "Nhap mo ta:";
			is >> phongBan.mota;
			phongBan.maPhong = tangmaPhong++;
			return is;
		}
		//Nhap tangmaPhong
		void settangmaPhong(int x)
		{
			tangmaPhong = x;
		}
		//lay ma nv
		int getmaPhong(){
			return maPhong;
		}
};

///Cac ham cua class PhongBan
int PhongBan::tangmaPhong = 100;

////////////////////
class DanhSach{
	friend class QuanLy;
	protected:
		char hoten[30], diachi[30];
		int sdt,maNV,maPhong,soNgayLam;
	public:
		DanhSach(int MaNV,char *ten,char *add,int SDT,int MaPhong,int SoNgayLam);
		DanhSach();
};
DanhSach::DanhSach(){
	
}
DanhSach::DanhSach(int MaNV,char *ten,char *add,int SDT,int MaPhong,int SoNgayLam)
{
	maNV = MaNV;
	strcpy(hoten,ten);
	strcpy(diachi,add);
	sdt = SDT;
	maPhong = MaPhong;
	soNgayLam = SoNgayLam;
}
////////////
class QuanLy{
	protected:
		vector <NhanVien> listNhanVien;
		vector <PhongBan> listPhongBan;
		vector <DanhSach> listDanhSach;
	public:
		//Ham tao
		QuanLy();
		//ham huy
		~QuanLy();
		
		//Doc du lieu tu file va luu vao vector tuong ung
		void loadNhanVien();
		void loadPhongBan();
		void loadDanhSach();
		
		//Them vao vecctor
		void addNhanVien();
		void addPhongBan();
		void addDanhSach();
		
		//Ghi du lieu tu vector vao file
		void saveNhanVien();
		void savePhongBan();
		void saveDanhSach();
		//In du lieu ra man hinh
		void printNhanVien();
		void printPhongBan();
		void printDanhSach();
		
		//Menu
		void menuNhanVien();
		void menuPhongBan();
		void menuDanhSach();
		//Menu chinh
		void display();
};
//cac ham cua class QuanLy
QuanLy::QuanLy()
{
	loadNhanVien();
	loadPhongBan();
	loadDanhSach();
	cout<<"Bam phim bat ky de bat dau"<<endl;
	system("pause");
}

QuanLy::~QuanLy()
{
	saveNhanVien();
	savePhongBan();
	saveDanhSach();
	system("pause");
}
//load 
void QuanLy::loadNhanVien(){
	fstream nhanVien("NV.DAT",ios::in | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu tu file NV.Dat"<<endl;//Chi la cho dep
		return;									//k co cung k sao
	}
	cout<<endl<<"Doc d lieu tu NV.DAT"<<endl;//cai nay cung nhu cai tren chi la thong bao cho dep thoi :v
	listNhanVien.clear();
	NhanVien tmp;
	while(nhanVien.read(reinterpret_cast<char*>(&tmp),sizeof(NhanVien)))
	{
		listNhanVien.push_back(tmp);
		tmp.settangmaNV(listNhanVien[listNhanVien.size()-1].getmaNV()+1);//load lai maNV de no k bi trung voi maNV cua file da luu
	}
	nhanVien.close();
	
}

void QuanLy::loadPhongBan(){
	fstream phongBan("PB.DAT",ios::in | ios::binary);
	if(!phongBan)
	{
		cerr<<"Tao du lieu tu file PB.DAT"<<endl;
		return;
	}
	cout<<endl<<"Doc du lieu tu PB.DAT"<<endl;
	listPhongBan.clear();
	PhongBan tmp;
	while(phongBan.read(reinterpret_cast<char*>(&tmp),sizeof(PhongBan)))
	{
		listPhongBan.push_back(tmp);
		tmp.settangmaPhong(listPhongBan[listPhongBan.size()-1].getmaPhong()+1);
	}
	phongBan.close();
}

void QuanLy::loadDanhSach(){
	fstream danhSach("PB.DAT",ios::in | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu tu file DS.DAT"<<endl;
		return;
	}
	cout<<endl<<"Doc du lieu tu DS.DAT"<<endl;
	listDanhSach.clear();
	DanhSach tmp;
	while(danhSach.read(reinterpret_cast<char*>(&tmp),sizeof(DanhSach)))
	{
		listDanhSach.push_back(tmp);
	}
	danhSach.close();
}
//////////add
void QuanLy::addNhanVien()
{
	NhanVien nv;
	cin>>nv;
	listNhanVien.push_back(nv);
}
void QuanLy::addPhongBan()
{
	PhongBan pb;
	cin>>pb;
	listPhongBan.push_back(pb);
}

void QuanLy::addDanhSach()
{
	system("cls");
	cout<<"---------------------"<<endl;
	cout<<"Danh sach Nhan vien"<<endl;
	this->printNhanVien();
	
	int maNV;
	cout<<"Nhap ma Nhan vien can lam dan sach:";
	cin>>maNV;
	
	cout<<endl<<"-------------------"<<endl;
	cout<<"Danh sach Phong Ban"<<endl;
	this->printPhongBan();
	cout<<endl;
	
	int so;
	int maPhong;
		int soNgayLam;
	vector <int> kiemtraPhong;
	cout<<"Nhap so phong ban ma nhan vien lam:";
	cin>>so;
	for(int i=0;i<so;i++)
{
	cout<<"Nhap ma phong ban:";
	cin>>maPhong;
	kiemtraPhong.push_back(maPhong);
	///Kiem tra co Phong co xuat hien >2 lan k
	bool chuaco = true;
	for(int i=0;i<kiemtraPhong.size();i++)
	{
		if(kiemtraPhong.size() >= 2)
		{
			if(kiemtraPhong[i] == maPhong) chuaco = false;
			while (chuaco == false)
			{
				cout<<"Phong da ton tai"<<endl
					<<"Nhap lai:";
				cin>>maPhong;
				chuaco = true;
			}
		}
	}

	cout<<"Nhap so ngay lam:";
	cin>>soNgayLam;
	
	///////////
	DanhSach tmp(listNhanVien[maNV-1000].maNV,listNhanVien[maNV-1000].hoten,listNhanVien[maNV-1000].diachi,
				listNhanVien[maNV-1000].sdt,listPhongBan[maPhong-100].maPhong,soNgayLam);
	listDanhSach.push_back(tmp);
}
}
///////save
void QuanLy::saveNhanVien(){
	fstream nhanVien("NV.DAT",ios::out | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu NV.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu tu NV.DAT"<<endl;
	for(int i=0;i<listNhanVien.size();i++)
	nhanVien.write(reinterpret_cast<char*>(&listNhanVien[i]),sizeof(NhanVien));
	cout<<"Thanh cong"<<endl;
	nhanVien.close();
}

void QuanLy::savePhongBan()
{
	fstream phongBan("PB.DAT",ios::out | ios::binary);
	if(!phongBan)
	{
		cerr<<"Tao du lieu PB.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu vao PB.DAT"<<endl;
	for(int i=0;i<listPhongBan.size();i++)
	phongBan.write(reinterpret_cast<char*>(&listPhongBan[i]),sizeof(PhongBan));
	cout<<"Thanh cong"<<endl;
	phongBan.close();
}

void QuanLy::saveDanhSach()
{
	fstream danhSach("DS.DAT",ios::out | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu DS.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu vao DS.DAT"<<endl;
	for(int i=0;i<listDanhSach.size();i++)
	danhSach.write(reinterpret_cast<char*>(&listDanhSach[i]),sizeof(DanhSach));
	cout<<"Thanh cong"<<endl;
	danhSach.close();
}
/////////print
void QuanLy::printNhanVien()
{
	for(int i=0;i<listNhanVien.size();i++)
	{
		cout<<"Ma Nv:"<<listNhanVien[i].maNV<<endl
			<<"Ten:"<<listNhanVien[i].hoten<<endl
			<<"Bac luong:"<<listNhanVien[i].bacLuong<<endl;
	}
}

void QuanLy::printPhongBan()
{
	for(int i=0;i<listPhongBan.size();i++)
	{
		cout<<"Ma Phong:"<<listPhongBan[i].maPhong<<endl
			<<"Mo ta:"<<listPhongBan[i].mota<<endl
			<<"he so cong viec:"<<listPhongBan[i].hesocongviec<<endl;
			
	}
}

void QuanLy::printDanhSach()
{
	for(int i=0;i<listDanhSach.size();i++)
	{
		cout<<endl<<"Ma Nv:"<<listDanhSach[i].maNV<<endl
			<<"Ten:"<<listDanhSach[i].hoten<<endl
			<<"Dia chi:"<<listDanhSach[i].diachi<<endl
			<<"sdt:"<<listDanhSach[i].sdt<<endl
			<<"Ma Phong:"<<listDanhSach[i].maPhong<<endl
			<<"So ngay lam:"<<listDanhSach[i].soNgayLam<<endl;
			
	}
}
///////menu
void QuanLy::menuNhanVien()
{
	int chon;
	do
	{
		system("cls");
		cout<<"MENU Nhan vien"<<endl
			<<"1.hien thi danh sach nhan vien"<<endl
			<<"2.Them nhan vien"<<endl
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

void QuanLy::menuPhongBan()
{
	int chon;
	do
	{
		system("cls");
		cout<<"MENU  Phong Ban"<<endl
			<<"1.hien thi danh sach  Phong Ban"<<endl
			<<"2.Them  Phong Ban"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>chon;
		
		cin.clear();
		cin.get();
		
		switch(chon)
		{
			case 1:{
				printPhongBan();
				system("pause");
				break;
			}
			case 2:{
				addPhongBan();
				system("pause");
				break;
			}
			case 3:{
				savePhongBan();
				system("pause");
				break;
			}
		}
	}while(chon != 0);
}

void QuanLy::menuDanhSach()
{
	int chon;
	do
	{
		system("cls");
		cout<<"MENU  Danh Sach"<<endl
			<<"1.hien thi danh sach  Danh Sach"<<endl
			<<"2.Them  Danh Sach"<<endl
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
///menuchinh
void QuanLy::display()
{
	int chon;
	do
	{
		system("cls");
		cout<<"MENU"<<endl
			<<"1.Menu nhan vien"<<endl
			<<"2.Menu phong ban"<<endl
			<<"3.Menu Danh Sach"<<endl
			<<"0.Ket thuc"<<endl
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
				menuPhongBan();
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

int main()
{
	QuanLy q;
	q.display();
	return 0;
}
