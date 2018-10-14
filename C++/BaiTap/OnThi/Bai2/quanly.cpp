#include "quanly.h" // class's header file

QuanLy::QuanLy()
{
	loadSinhVien();
	loadMonHoc();
	loadBanDangKy();
	cout<<"San sang bam phim at ky de hoat dong"<<endl;
	system("pause");
	
}

QuanLy::~QuanLy()
{
	saveSinhVien();
	saveMonHoc();
	saveBanDangKy();
	system("pause");
}
/////////load family/////////
void QuanLy::loadSinhVien()
{
	fstream sinhVien;
	sinhVien.open("SV.DAT",ios::in | ios::binary);
	if(!sinhVien)
	{
		cerr<<"Tao du lieu SV.DAT "<<endl;
		return;
	}
	cout<<"Doc du lieu tu SV.DAT"<<endl;
	listSinhVien.clear();
	SinhVien tmp;
	while (sinhVien.read((char*)&tmp,sizeof(SinhVien)))
	{
		listSinhVien.push_back(tmp);
		tmp.setgenMaSV(listSinhVien[listSinhVien.size()-1].getMaSV()+1);
	}
	
	sinhVien.close();
}

void QuanLy::loadMonHoc()
{
	fstream monHoc;
	monHoc.open("MH.DAT",ios::in | ios::binary);
	if(!monHoc)
	{
		cerr<<"Tao du lieu MH.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu tu MH.DAT"<<endl;
	listMonHoc.clear();
	MonHoc tmp;
	while(monHoc.read((char*)&tmp,sizeof(MonHoc)))
	{
		listMonHoc.push_back(tmp);
		tmp.setgenMaMonHoc(listMonHoc[listMonHoc.size()-1].getmaMonHoc()+1);
	}
	monHoc.close();
}

void QuanLy::loadBanDangKy()
{
	fstream banDangKy;
	banDangKy.open("QLDK.DAT",ios::in | ios::binary);
	if(!banDangKy)
	{
		cerr<<"Tao du lieu tu QLDK.DAT"<<endl;
		return;
	}
	cout<<"Doc du lieu tu QLDK.DAT"<<endl;
	listBanDangKy.clear();
	BanDangKy tmp;
	while(banDangKy.read((char*)&tmp,sizeof(BanDangKy)))
	{
		listBanDangKy.push_back(tmp);
	}
	banDangKy.close();
}
/////save family
void QuanLy::saveSinhVien()
{
	fstream sinhVien;
	sinhVien.open("SV.DAT",ios::out | ios::binary);
	if(!sinhVien)
	{
		cerr<<"Tao du lieu tu SV.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu tu SV.DAT"<<endl;
	for(int i=0;i<listSinhVien.size();i++)
	{
		sinhVien.write((char*)&(listSinhVien[i]),sizeof(SinhVien));
	}
	
	cout<<endl<<"Thanh cong"<<endl;
	sinhVien.close();
}

void QuanLy::saveMonHoc()
{
	fstream monHoc;
	monHoc.open("MH.DAT",ios::out | ios::binary);
	if(!monHoc)
	{
		cerr<<"Tao du lieu tu MH.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu tu MH.DAT"<<endl;
	for(int i=0;i<listMonHoc.size();i++)
	monHoc.write((char*)&(listMonHoc[i]),sizeof(MonHoc));
	
	cout<<endl<<"THanh cong"<<endl;
	monHoc.close();
}

void QuanLy::saveBanDangKy()
{
	fstream banDangKy;
	banDangKy.open("QLDK.DAT",ios::out | ios::binary);
	if(!banDangKy)
	{
		cerr<<"Tao du lieu tu QLDK.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu tu QLDK.DAT"<<endl;
	for(int i=0;i<listBanDangKy.size();i++)
	banDangKy.write((char*)&(listBanDangKy[i]),sizeof(BanDangKy));
	cout<<endl<<"Thanh cong"<<endl;
	banDangKy.close();
}
//////add
void QuanLy::addSinhVien(SinhVien &sv)
{
	//SinhVien sv;
	cin>>sv;
	listSinhVien.push_back(sv);
}

void QuanLy::addMonHoc()
{
	MonHoc monHoc;
	cin>>monHoc;
	listMonHoc.push_back(monHoc);
}

void QuanLy::addBanDangKy()
{
	system("cls");
	cout<<"-------------------------------------"<<endl;
	cout<<"Danh sach sinh vien"<<endl<<endl;
	this->printSinhVien();
	cout<<endl<<endl<<"------------------------------------"<<endl;

	
	int maSV;
	cout<<"Nhap ma sinh vien can dang ky:"<<endl;
	cin>>maSV;
	
	int soluongmon;
	cout<<"Nhap so luong mon hoc:";
	cin>>soluongmon;
	while (soluongmon <= 0 || soluongmon > 8)
	{
		cout<<"So luong mon hoc >0 va <=8"<<endl;
		cout<<"Nhap lai so luong mon hoc:";
		cin>>soluongmon;
	}
	
	cout<<endl<<"Danh sach mon hoc"<<endl;
	this->printMonHoc();
	cout<<endl<<"-----------------------------"<<endl;
	
	int maMonHoc;
	int ngayDK,thangDK,namDK;
	
	vector <int> kiemtraMH;
	
	for(int i=0;i<soluongmon;i++)
	{
		cout<<"Nhap ma mon hoc thu "<<i+1<<":";
		cin>>maMonHoc;
		kiemtraMH.push_back(maMonHoc);
			//Kiem tra
		bool chuaco = true;
			for(int i=0;i<kiemtraMH.size();++i)
			{
				if(kiemtraMH.size() >=2)
				{
					if(kiemtraMH[i] == maMonHoc) chuaco = false;
					while(chuaco == false)
					{
						cout<<"Mon hoc da ton tai"<<endl
							<<"Nhap lai ma mon hoc dang ky:";
						cin>> maMonHoc;
						chuaco = true;
					}
				}
			}
			
		cout<<"Nhap ngay dang ky mon hoc:";
		cin>>ngayDK;
		cout<<"Nhap thang dang ky mon hoc:";
		cin>>thangDK;
		cout<<"Nhap nam dang ky mon hoc:";
		cin>>namDK;
		
		BanDangKy tmp(listSinhVien[maSV-10000].getMaSV(),listSinhVien[maSV-10000].hoten,listSinhVien[maSV-10000].diachi,
								listSinhVien[maSV-10000].sdt,
								listMonHoc[maMonHoc-1000].getmaMonHoc(),listMonHoc[maMonHoc-1000].tenMonHoc,
								listMonHoc[maMonHoc-1000].tongSoTiet,listMonHoc[maMonHoc-1000].loaiMonHoc);
		listBanDangKy.push_back(tmp);
	}	
}
/////print
void QuanLy::printSinhVien()
{
	for(int i=0;i<listSinhVien.size();i++)
	{
		cout<<endl<<"Ma SV:"<<listSinhVien[i].maSV<<endl
			<<"Ho ten:"<<listSinhVien[i].hoten<<endl
			<<"Dia chi:"<<listSinhVien[i].diachi<<endl
			<<"SDT:"<<listSinhVien[i].sdt<<endl
			<<"Lop:"<<listSinhVien[i].lop<<endl;
	}
}
void QuanLy::printMonHoc()
{
	for(int i=0;i<listMonHoc.size();i++)
	{
		cout<<endl<<"Ma mon hoc:"<<listMonHoc[i].maMonHoc<<endl
			<<"Ten mon hoc:"<<listMonHoc[i].tenMonHoc<<endl
			<<"Tong so tiet:"<<listMonHoc[i].tongSoTiet<<endl
			<<"Loai Mon hoc:";
		switch(listMonHoc[i].loaiMonHoc)
		{
			case 1:{
				cout<<"Dai cuong"<<endl;
				break;
			}
			case 2:{
				cout<<"Co so nganh"<<endl;
				break;
			}
			case 3:{
				cout<<"Chuyen nganh"<<endl;
				break;
			}
			case 4:{
				cout<<"Tu chon"<<endl;
				break;
			}
		}
	}
}

void QuanLy::printBanDangKy()
{
	cout<<endl<<"--------------------------------"<<endl;
	for(int i=0;i<listBanDangKy.size();i++)
	{
		cout<<endl<<"Ma SV:"<<listBanDangKy[i].MaSV<<endl
			<<"Ho ten:"<<listBanDangKy[i].nameSv<<endl
			<<"Dia chi:"<<listBanDangKy[i].diachi<<endl
			<<"SDT:"<<listBanDangKy[i].SDT<<endl;
			
		cout<<endl<<"Ma mon hoc:"<<listBanDangKy[i].MaMH<<endl
			<<"Ten mon hoc:"<<listBanDangKy[i].tenMonHoc<<endl
			<<"Tong so tiet:"<<listBanDangKy[i].tongsotiet<<endl
			<<"Loai Mon hoc:";
		switch(listBanDangKy[i].loaiMonHoc)
		{
			case 1:{
				cout<<"Dai cuong"<<endl;
				break;
			}
			case 2:{
				cout<<"Co so nganh"<<endl;
				break;
			}
			case 3:{
				cout<<"Chuyen nganh"<<endl;
				break;
			}
			case 4:{
				cout<<"Tu chon"<<endl;
				break;
			}
		}
		
		/*cout<<endl<<"Ngay Dang Ky:"<<listBanDangKy[i].ngayDK<<endl
			<<"Thang Dang ky:"<<listBanDangKy[i].thangDK<<endl
			<<"Nam dang ky:"<<listBanDangKy[i].namDK<<endl;
		*/	
	}
}
///////menu
void QuanLy::menuSinhVien()
{
	SinhVien sv;
	int choice;
	do
	{
		system("cls");
		cout<<"MENU Sinh Vien"<<endl<<endl;
		cout<<"1.Hien thi danh sach sinh vien"<<endl
			<<"2.Them sinh vien"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		
		switch(choice)
		{
			case 1:{
				printSinhVien();
				system("pause");
				break;
			}
			case 2:{
				//SinhVien sv;
				addSinhVien(sv);
				system("pause");
				break;
			}
			case 3:{
				saveSinhVien();
				system("pause");
				break;
			}
		}
	}while(choice != 0);
}

void QuanLy::menuMonHoc()
{
	MonHoc monHoc;
	int choice;
	do
	{
		system("cls");
		cout<<"MENU Mon Hoc"<<endl<<endl;
		cout<<"1.Hien thi danh sach mon hoc"<<endl
			<<"2.Them mon hoc"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		
		switch(choice)
		{
			case 1:{
				printMonHoc();
				system("pause");
				break;
			}
			case 2:{
				//SinhVien sv;
				addMonHoc();
				system("pause");
				break;
			}
			case 3:{
				saveMonHoc();
				system("pause");
				break;
			}
		}
	}while(choice != 0);
}

void QuanLy::menuBanDangKy()
{
	BanDangKy banDangKy;
	int choice;
	do
	{
		system("cls");
		cout<<"MENU Bang Dang Ky"<<endl<<endl;
		cout<<"1.Hien thi danh sach Ban Dang Ky"<<endl
			<<"2.Them Ban Dang Ky"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl
			<<"Ban chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		
		switch(choice)
		{
			case 1:{
				printBanDangKy();
				system("pause");
				break;
			}
			case 2:{
				addBanDangKy();
				system("pause");
				break;
			}
			case 3:{
				saveBanDangKy();
				system("pause");
				break;
			}
		}
	}while(choice != 0);
}
///////Sort family
void QuanLy::SxTen()
{
	for(int i=0;i<listBanDangKy.size();i++)
		for(int j=listBanDangKy.size()-1;j>i;j--)
			if(strcmp(listBanDangKy[i].nameSv,listBanDangKy[j].nameSv) == 1)
				swap(listBanDangKy[i],listBanDangKy[j]);
}


//////////////////
void QuanLy::display()
{
	int choice;
	do
	{
		system("cls");
		cout<<"MENU chinh"<<endl<<endl;
		cout<<"1.Menu Sinh Vien"<<endl
			<<"2.Menu Mon Hoc"<<endl
			<<"3.Menu Ban dang ky"<<endl
			<<"0.Ket thuc"<<endl
			<<"Ban chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		switch(choice)
		{
			case 1:{
				system("cls");
				menuSinhVien();
				break;
			}
			case 2:{
				system("cls");
				menuMonHoc();
				break;
			}
			case 3:{
				system("cls");
				menuBanDangKy();
				break;
			}
		}
	}while (choice != 0);
}
