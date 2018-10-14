#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

fstream sach("SACH.DAT",ios::app | ios::in | ios::binary);
fstream banDoc("BD.DAT",ios::app | ios::in | ios::binary);

vector<BanDoc> listBanDoc;
vector<Sach> listSach;

int ma=10000;

class Nguoi{
	public:
		void Nhap();
		void Xuat();
	protected:
		string hoten;
		string diachi;
		int sdt;
};

void Nguoi::Nhap(){
	cout<<"Nhap ho ten:";
	getline(cin,hoten);
	cout<<"Nhap dia chi:";
	getline(cin,diachi);
	cout<<"Nhap SDT:";
	cin>>sdt;
}

void Nguoi::Xuat(){
	cout<<"Ho ten:"<<hoten<<endl
		<<"Dia chi:"<<diachi<<endl
		<<"SDT:"<<sdt<<endl;
}
//////////////////////////////////////////
class BanDoc:public Nguoi{
	public:
		BanDoc(string,string,int,int,string);
		void addBanDoc();
		void Nhap();
		void Xuat();
		void GhiFile();
		class friend QLMuonSach;
	protected:
		int maThe;
		string loaiBandoc;
};
BanDoc::BanDoc(string ten,string add,int phone,int ma,string loai){
	hoten = ten;
	diachi = add;
	sdt = phone;
	maThe = ma;
	loaiBandoc = loai;
}

void BanDoc::Nhap(){
	maThe=ma++;
	Nguoi::Nhap();
	cout<<"Nhap loai ban doc:";
	getline(cin,loaiBandoc);
	BanDoc tmp(hoten,diachi,sdt,maThe,loaiBandoc);
	listBanDoc.push_back(tmp);
}
void BanDoc::Xuat(){
	BanDoc xuat;
	while(banDoc.read((char*)&xuat),sizeof(BanDoc)){
		listBanDoc.push_back(tmp);
	}
	for(int i=0;i<listBanDoc.size();i++)
	{
		cout<<"Ho ten:"<<listBanDoc[i].hoten<<endl
			<<"Dia chi:"<<listBanDoc[i].diachi<<endl
			<<"SDT:"<<listBanDoc[i].sdt<<endl
			<<"Ma The:"<<listBanDoc[i].maThe<<endl
			<<"Loai Ban Doc:"<<listBanDoc[i].loaiBandoc<<endl;
	}
}
void BanDoc::GhiFile(){
	for(int i=;i<listBanDoc.size();i++)
	banDoc.write((char*)&(listBanDoc[i]),sizeof(BanDoc));
}
/////////////////////////////////////////////
class Sach{
	public:
		void Nhap();
		void Xuat();
		void GhiFile();
		friend class QLMuonSach;
	protected:
		int maSach;
		string tensach,tacgia,chuyenNganh;
		int namxb;
};
void Sach::Nhap(){
	
	cout<<"Nhap ten sach:";
	getline(cin,tensach);
	cout<<"Nhap tac gia:";
	getline(cin,tacgia);
	cout<<"Nhap chuyen nganh:";
	getline(cin,chuyenNganh);
	cout<<"Nhap nam xuat ban:";
	cin>>namxb;
}

void Sach::Xuat(){
	int year;
	string tenSach,tacGia,Nganh;
	while(	getline(sach,tenSach) &&
		getline(sach,tacgia) &&
		getline(sach,chuyenNganh)){
		sach>>year;
	}
	cout<<"Ten sach:"<<tenSach<<endl
		  <<"Tac gia:"<<tacGia<<endl
		  <<"Chuyen nganh:"<<Nganh<<endl
		  <<"Nam xuat ban:"<<year<<endl;
}
void Sach::GhiFile(){
	sach<<tensach<<endl
		<<tacgia<<endl
		<<chuyenNganh<<endl
		<<namxb<<endl;
}
///////////////////////////////////////////
class QLMuonSach{
	public:
		void Nhap();
		void Xuat();
		void GhiFile();
	protected:
		
};
