#include "quanly.h" // class's header file

// class constructor
QuanLy::QuanLy()
{
	// insert your code here
	loadNhanVien();
	loadMatHang();
	loadDanhSach();
	cout<<"Nhan phim bat ky de bat dau"<<endl;
	system("pause");
}

// class destructor
QuanLy::~QuanLy()
{
	// insert your code here
	saveNhanVien();
	saveMatHang();
	saveDanhSach();
	system("pause");
}
/////////load
void QuanLy::loadNhanVien()
{
	fstream nhanVien;
	nhanVien.open("NV.DAT",ios::in | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu cho file NV.DAT"<<endl;
		return ;
	}
	cout<<"Doc du lieu tu file NV.DAT"<<endl;
	listNhanVien.clear();
	NhanVien tmp;
	while(nhanVien.read((char*)&tmp,sizeof(NhanVien)))
	{
		listNhanVien.push_back(tmp); 
		tmp.settangmaNV(listNhanVien[listNhanVien.size()-1].getmaNV()+1);
	}
	nhanVien.close();
}

void QuanLy::loadMatHang()
{
	fstream matHang;
	matHang.open("MH.DAT",ios::in | ios::binary);
	if(!matHang)
	{
		cerr<<"Tao du lieu cho file MH.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu tu file MH.DAT"<<endl;
	listMatHang.clear();
	MatHang tmp;
	while(matHang.read((char*)&tmp,sizeof(MatHang)))
	{
		listMatHang.push_back(tmp); 
		tmp.settangmaHang(listMatHang[listMatHang.size()-1].getmaHang()+1);
	}
	matHang.close();
}

void QuanLy::loadDanhSach()
{
	fstream danhSach("QLBH.DAT",ios::in | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu cho file QLBH.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu tu file QLBH.DAT"<<endl;
	listDanhSach.clear();
	DanhSach tmp;
	while(danhSach.read(reinterpret_cast<char*>(&tmp),sizeof(DanhSach)))
	{
		listDanhSach.push_back(tmp);
	}
}
/////////add
void QuanLy::addNhanVien()
{
	NhanVien nv;
	cin>>nv;
	listNhanVien.push_back(nv);
}

void QuanLy::addMatHang()
{
	MatHang mh;
	cin>>mh;
	listMatHang.push_back(mh);
}

void QuanLy::addDanhSach()
{
	system("cls");
	cout<<endl<<"----------------------"<<endl;
	cout<<"Danh sach Khach Hang"<<endl;
	this->printNhanVien();
	cout<<endl<<"---------------------------"<<endl;
	
	int maNV;
	cout<<"Nhap ma Khach hang can lam danh sach:";
	cin>>maNV;

	cout<<endl<<"---------------------------------"<<endl;
	cout<<"Danh sach mat hang"<<endl;
	this->printMatHang();
	cout<<endl<<"----------------------------------";
		
	int soLuong;
	cout<<"Nhap so luong mat hang ma khach hang mua:";
	cin>>soLuong;
	
	int maHang;
	for(int i=0;i<soLuong;i++)
	{
		cout<<"Nhap ma mat hang:";
		cin>>maHang;
		DanhSach tmp(listNhanVien[maNV-10000].maNV,listNhanVien[maNV-10000].hoten,
					listMatHang[maHang-1000].maHang,listMatHang[maHang-1000].tenHang,soLuong);
		listDanhSach.push_back(tmp);
	}
}
////////save
void QuanLy::saveNhanVien()
{
	fstream nhanVien;
	nhanVien.open("NV.DAT",ios::out | ios::binary);
	if(!nhanVien)
	{
		cerr<<"Tao du lieu cho file NV.DAT"<<endl;
		return ;
	}
	cout<<"Ghi du lieu tu file NV.DAT"<<endl;
	for(int i=0;i<listNhanVien.size();i++)
	nhanVien.write((char*)&listNhanVien[i],sizeof(NhanVien));
	cout<<endl<<"Thanh cong"<<endl;
	nhanVien.close();
}

void QuanLy::saveMatHang()
{
	fstream matHang;
	matHang.open("MH.DAT",ios::out | ios::binary);
	if(!matHang)
	{
		cerr<<"Tao du lieu cho file MH.DAT"<<endl;
		return ;
	}
	cout<<"Ghi du lieu tu file MH.DAT"<<endl;
	for(int i=0;i<listMatHang.size();i++)
	matHang.write((char*)&listMatHang[i],sizeof(MatHang));
	cout<<endl<<"Thanh cong"<<endl;
	matHang.close();
}

void QuanLy::saveDanhSach()
{
	fstream danhSach("QLBH.DAT",ios::out | ios::binary);
	if(!danhSach)
	{
		cerr<<"Tao du lieu QLBH.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu tu file QLBH.DAT"<<endl;
	for(int i=0;i<listDanhSach.size();i++)
	{
		danhSach.write(reinterpret_cast<char*>(&listDanhSach[i]),sizeof(DanhSach));
	}
	cout<<"Thanh cong"<<endl;
	danhSach.close();
}
/////////print

void QuanLy::printNhanVien()
{
	cout<<endl<<"----------------------"<<endl;
	for(int i=0;i<listNhanVien.size();i++)
		{
			cout<<"Ma Nhan Vien:"<<listNhanVien[i].maNV<<endl
				<<"Ten:"<<listNhanVien[i].hoten<<endl
				<<"Dia chi:"<<listNhanVien[i].diachi<<endl
				<<"SDT:"<<listNhanVien[i].sdt<<endl;
		}
}

void QuanLy::printMatHang()
{
	cout<<endl<<"----------------------"<<endl;
	for(int i=0;i<listMatHang.size();i++)
	{
		cout<<"Ma Mat Hang:"<<listMatHang[i].maHang<<endl
			<<"Ten Hang:"<<listMatHang[i].tenHang<<endl
			<<"So luong:"<<listMatHang[i].soLuong<<endl;
		switch(listMatHang[i].nhomHang)
		{
			case 1:{
				cout<<"Dien Tu"<<endl;
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

void QuanLy::printDanhSach()
{
	cout<<endl<<"----------------------"<<endl;
	for(int i=0;i<listDanhSach.size();i++)
	{
		cout<<"Ma khach hang:"<<listDanhSach[i].maNV<<endl
			<<"Ten khach hang:"<<listDanhSach[i].hoten<<endl
			<<"Ma mat hang:"<<listDanhSach[i].maHang<<endl
			<<"Ten hang:"<<listDanhSach[i].tenHang<<endl
			<<"So luong:"<<listDanhSach[i].soLuong<<endl;
	}
}
//////////menu
void QuanLy::menuNhanVien()
{

	int chon;
	do{
		system("cls");
	cout<<"MENU Khach Hang"<<endl
		<<"1.Hien thi danh sach Khach Hang"<<endl
		<<"2.Them Nhan Vien"<<endl
		<<"3.Luu"<<endl
		<<"0.Quay lai:"<<endl
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
	}while (chon != 0);
}

void QuanLy::menuMatHang()
{
	
	int chon;
	do{
	
	system("cls");
	cout<<"MENU Mat Hang"<<endl
		<<"1.Hien thi danh sach Mat Hang"<<endl
		<<"2.Them Nhan Vien"<<endl
		<<"3.Luu"<<endl
		<<"0.Quay lai:"<<endl
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

void QuanLy::menuDanhSach()
{
	
	int chon;
	do{
	
	system("cls");
	cout<<"MENU Danh Sach"<<endl
		<<"1.Hien thi danh sach Danh Sach"<<endl
		<<"2.Them Danh Sach"<<endl
		<<"3.Luu"<<endl
		<<"0.Quay lai:"<<endl
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

////////
void QuanLy::display()
{
	
	int chon;
	do{
		system("cls");
	cout<<"MENU"<<endl
		<<"1.Menu Khach Hang"<<endl
		<<"2.Menu Mat Hang"<<endl
		<<"3.Menu danh sach mat hang"<<endl
		<<"0.Ket thuc:"<<endl
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
