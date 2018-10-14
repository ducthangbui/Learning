#include "quanly.h" // class's header file

// class constructor
QuanLy::QuanLy(char *fnameBD,char *fnameS,char*fnameQL)
{
		strcpy(filenameBD,fnameBD);
		strcpy(filenameS,fnameS);
		strcpy(filenameQL,fnameQL);
		loadBanDoc(filenameBD);
		loadSach(filenameS);
		loadQuanLyMuonSach(filenameQL);
		cout<<"san sang bam phim bat ki de khoi dong !!!"<<endl;
		system("pause");
}
QuanLy::~QuanLy()
{
	saveBanDoc(filenameBD);
	saveSach(filenameS);
	saveQuanLyMuonSach(filenameQL);
	system("pause");
}
///Load Family////////////////////
void QuanLy::loadBanDoc(char *fname)
{
	fstream banDoc;
	banDoc.open(fname,ios::in | ios::binary);
	if(!banDoc)
	{
		cerr<<"Tao du lieu tu file BD.DAT"<<endl;
		return;
	}
	cout<<"Doc file du lieu tu file BD.DAT"<<endl;
	listBanDoc.clear();
	BanDoc tmp;
	while(banDoc.read((char*)&tmp,sizeof(BanDoc)))
	{
		listBanDoc.push_back(tmp);
	}
	if(tmp.maThe != 0) tmp.setGenMaBD(tmp.getMa());
	banDoc.close();
}

void QuanLy::loadSach(char *fname)
{
	fstream sach;
	sach.open(fname,ios::in | ios::binary);
	if(!sach)
	{
		cerr<<"Tao du lieu tu file Sach.DAT"<<endl;
		return;
	}
	cout<<"Doc file du lieu tu file Sach.DAT"<<endl;
	listSach.clear();
	Sach tmp;
	while(sach.read((char*)&tmp,sizeof(Sach)))
	{
		listSach.push_back(tmp);
	};
	if(tmp.maSach != 0) tmp.setGenMaSach(tmp.getMa());
	sach.close();
}

void QuanLy::loadQuanLyMuonSach(char *fname)
{
	fstream quanLy;
	quanLy.open(fname,ios::in | ios::binary);
	if(!quanLy)
	{
		cerr<<"Tao du lieu tu file QLMS.DAT"<<endl;
		return;
	}
	cout<<"Doc file du lieu tu file QLMS.DAT"<<endl;
	listQLMS.clear();
	QuanLyMuonSach tmp;
	while(quanLy.read((char*)&tmp,sizeof(QuanLyMuonSach)))
	{
		listQLMS.push_back(tmp);
	};
	quanLy.close();
}
///Save Family//////////////////
void QuanLy::saveBanDoc(char *fname)
{
	fstream banDoc;
	banDoc.open(fname,ios::out | ios::binary);
	if(!banDoc)
	{
		cerr<<"Tao file du lieu moi: BD.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu vao file BD.DAT"<<endl;
	for(int i=0;i<listBanDoc.size();i++)
	banDoc.write((char*)&(listBanDoc[i]),sizeof(BanDoc));
		cout<<"Thanh cong"<<endl;
	banDoc.close();
}

void QuanLy::saveSach(char *fname)
{
	fstream sach;
	sach.open(fname,ios::out | ios::binary);
	if(!sach)
	{
		cerr<<"Tao file du lieu moi: Sach.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu vao file Sach.DAT"<<endl;
	for(int i=0;i<listSach.size();i++)
	sach.write((char*)&(listSach[i]),sizeof(Sach));
		cout<<"Thanh cong"<<endl;
	sach.close();
}


void QuanLy::saveQuanLyMuonSach(char *fname)
{
	fstream quanLy;
	quanLy.open(fname,ios::out | ios::binary);
	if(!quanLy)
	{
		cerr<<"Tao file du lieu moi: QLMS.DAT"<<endl;
		return;
	}
	cout<<"Ghi du lieu vao file QLMS.DAT"<<endl;
	for(int i=0;i<listQLMS.size();i++)
	quanLy.write((char*)&(listQLMS[i]),sizeof(QuanLyMuonSach));
		cout<<"Thanh cong"<<endl;
	quanLy.close();
}
////Add Family//////////////////
void QuanLy::addBanDoc()
{
	char name[30],add[30];
	int phonenumber;
	cout<<"Nhap ho ten:";
	cin.getline(name,30);
	cout<<"Nhap dia chi:";
	cin.getline(add,30);
	cout<<"Nhap sdt:";
	cin>>phonenumber;
	BanDoc tmp(name,add,phonenumber);
	listBanDoc.push_back(tmp);
}

void QuanLy::addSach()
{
	char bookname[30],author[30];
	cout<<"Nhap ten sach:";
	cin.getline(bookname,30);
	cout<<"Nhap tac gia:";
	cin.getline(author,30);
	int dauSach;
	cout<<endl<<"Nhap dau sach:"<<endl
		<<"1.KHTN"<<endl
		<<"2.VH-NT"<<endl
		<<"3.Dien tu vien thong"<<endl
		<<"4.CNTT"<<endl
		<<"Ban chon:";
	cin>>dauSach;
	Sach tmp(bookname,author,dauSach);
	listSach.push_back(tmp);
}



void QuanLy::addQuanLyMuonSach()
{
	system("cls");
	cout<<endl<<"Danh sach ban doc"<<endl;
	this->printBanDoc();
	cout<<endl<<"Danh sach Sach"<<endl;
	this->printSach(0);
	cout<<"---------------------------------"<<endl;
	if(listBanDoc.size() == 0)
	{
		cout<<"Khong co du lieu ban doc"<<endl;
		system("cls");
		return;
	}
	int bDoc;
	cout<<"Nhap ma ban doc muon tao bang QLMS:";
	cin>>bDoc;
	
	int mSach; // ma sach muong them
	int SoLuongDauSach;
	cout<<"Nhap so luong dau sach muon them:";
	cin>>SoLuongDauSach;
	while(SoLuongDauSach < 0 || SoLuongDauSach > 5)
	{
		cout<<"Chi duoc muon nhieu nhat 5 dau sach"<<endl;
		cout<<"Hay nhap lai:";
		cin>>SoLuongDauSach;
	}
	
	int l = 0;// chi so cua mang SoLuongSach[]
	for(int i=0;i<SoLuongDauSach;i++)
{	
	int loaiDauSach;
	cout<<"Nhap loai dau sach muon them:";
	cin>>loaiDauSach;
	while(loaiDauSach<1 || loaiDauSach>5)
	{
		cout<<"Hay nhap loai tu 1-5:";
		cin>>loaiDauSach;
	}
	cout<<"---------Loai Dau Sach "<< loaiDauSach <<"-------------------"<<endl;
	printSach(loaiDauSach);
	cout<<"---------------------------------------------------"<<endl;
	int soLuongSach;

	cout<<"Nhap so luong sach muon them:";
	cin>>soLuongSach;
	while(soLuongSach<0 || soLuongSach >3)
	{
		cout<<"So luong sach ban duoc muon nhieu nhat la 3"<<endl
			<<"Hay nhap lai:";
		cin>>soLuongSach;
		
	}

	SoLuongSach[l] = soLuongSach;
	l++;
	for(int i=0;i<soLuongSach;i++)
		{
			cout<<"Nhap ma Sach muon them:";
			cin>>mSach;
				
	QuanLyMuonSach tmp(listBanDoc[bDoc-10000].getMa(),listBanDoc[bDoc-10000].hoten,listBanDoc[bDoc-10000].diachi
						,listSach[mSach-10000].tensach,listSach[mSach-10000].tacgia,soLuongSach);
	listQLMS.push_back(tmp);
		}
	
}
}
/////Print Family///////////////////
void QuanLy::printBanDoc()
{
	int i=0;
	for(int i=0;i<listBanDoc.size();i++)
	cout<<"Ma Ban doc:"<<listBanDoc[i].maThe<<endl
		<<"Ho ten:"<<listBanDoc[i].hoten<<endl
		<<"Dia chi:"<<listBanDoc[i].diachi<<endl
		<<"SDT:"<<listBanDoc[i].sdt<<endl;
		
}

void QuanLy::printSach(int loaiDauSach)
{
	string sDauSach[]={"-----------","KHTN","VH-NT","Dien tu vien thong","CNTT"};
	for(int i=0;i<listSach.size();i++)
	{
		if (loaiDauSach != 0) if (listSach[i].DauSach != sDauSach[loaiDauSach]) continue;
	cout<<"Ma sach:"<<listSach[i].maSach<<endl
		<<"Tac gia:"<<listSach[i].tacgia<<endl
		<<"Ten sach:"<<listSach[i].tensach<<endl
		<<"Dau Sach:"<<listSach[i].DauSach<<endl;
	}
}

void QuanLy::printQuanLyMuonSach()
{

	for(int i=0;i<listQLMS.size();i++)
	{

		
		//cout<<endl<<"Ma sach:"<<listQLMS[i].maSach<<endl
		cout<<"HO ten:"<<listQLMS[i].ten<<endl
			<<"Dia chi:"<<listQLMS[i].dchi<<endl
			<<"Tac gia:"<<listQLMS[i].tenSach<<endl
			<<"Ten Sach:"<<listQLMS[i].tacGia<<endl;
	}
}
////Sort family/////////////
void QuanLy::SxTen()
{
	for(int i=0;i<listQLMS.size();i++)
		for(int j=listQLMS.size()-1;j>i;j--)
		{
			if(strcmp(listQLMS[i].ten,listQLMS[j].ten) == 1) 
			 		swap(listQLMS[i],listQLMS[j]);
			
		}
}

void QuanLy::SxSoLuongSach()
{
	for(int i=0;i<listQLMS.size();i++)
		for(int j=listQLMS.size()-1;j>i;j--)
			if(listQLMS[i].TongSoLuongSach < listQLMS[j].TongSoLuongSach) 
				swap(listQLMS[i],listQLMS[j]);
}
/////Find Family////////////
void QuanLy::TimTen()
{
	char findName[30];
	cout<<endl<<"Nhap ten cam tim:";
	cin.getline(findName,30);
	cout<<"Ten"<<setw(23)<<"Dia Chi"<<setw(20)<<"Ten sach"<<setw(15)<<"Tac Gia"<<endl;
	for(int i=0;i<listQLMS.size();i++)
		{
			if(strcmp(listQLMS[i].ten,findName) == 0) 
			 {
			 		
			 		cout<<endl<<listQLMS[i].ten
						<<setw(15)<<listQLMS[i].dchi
						<<setw(15)<<listQLMS[i].tenSach
						<<setw(15)<<listQLMS[i].tacGia<<endl;
			 }		
		}
}
///Menu Family///////////
void QuanLy::menuBanDoc()
{
	int choice;
	do
	{
		system("cls");
		cout<<"MENU BAN DOC"<<endl<<endl;
		cout<<"1.Hien thi danh sach ban doc"<<endl
			<<"2.Them ban doc"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl;
		cout<<"Lua chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		switch(choice)
		{
			case 1:{
				printBanDoc();
				system("pause");
				break;
			}
			case 2:{
				addBanDoc();
				cout<<"Them thanh cong!"<<endl;
				system("pause");
				break;
			}
			case 3:{
				saveBanDoc(filenameBD);
			
				system("pause");
				break;
			}
		}
	}while(choice!=0);
}


void QuanLy::menuSach()
{
	int choice;
	do
	{
		system("cls");
		cout<<"MENU Sach"<<endl<<endl;
		cout<<"1.Hien thi danh sach Sach"<<endl
			<<"2.Them Sach"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl;
		cout<<"Lua chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		switch(choice)
		{
			case 1:{
					int dauSach;
					cout<<endl<<"Nhap dau sach:"<<endl
						<<"1.KHTN"<<endl
						<<"2.VH-NT"<<endl
						<<"3.Dien tu vien thong"<<endl
						<<"4.CNTT"<<endl
						<<"0.Toan bo danh sach:"<<endl
						<<"Ban chon:";
						cin>>dauSach;
				printSach(dauSach);
				system("pause");
				break;
			}
			case 2:{
				addSach();
				cout<<"Them thanh cong!"<<endl;
				system("pause");
				break;
			}
			case 3:{
				saveSach(filenameS);
			
				system("pause");
				break;
			}
		}
	}while(choice!=0);
}


void QuanLy::menuQuanLyMuonSach()
{
		int choice;
	do
	{
		system("cls");
		cout<<"MENU Quan Ly Muon Sach"<<endl<<endl;
		cout<<"1.Hien thi QLMS"<<endl
			<<"2.Them QLMS"<<endl
			<<"3.Luu"<<endl
			<<"0.Quay lai"<<endl;
		cout<<"Lua chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		switch(choice)
		{
			case 1:{
				printQuanLyMuonSach();
				system("pause");
				break;
			}
			case 2:{
				addQuanLyMuonSach();
				cout<<"Them thanh cong!"<<endl;
				system("pause");
				break;
			}
			case 3:{
				saveQuanLyMuonSach(filenameQL);
			
				system("pause");
				break;
			}
		}
	}while(choice!=0);
}

void QuanLy::display()
{
	int choice;
	do{
		system("cls");
		cout<<"MENU CHINH"<<endl<<endl
			<<"1.Ban doc"<<endl
			<<"2.Sach"<<endl
			<<"3.Quan ly muon sach"<<endl
			<<"4.Sap xep ten"<<endl
			<<"5.Sx theo so luong sach muon"<<endl
			<<"6.Tim ten"<<endl
			<<"0.Ket thuc"<<endl
			<<"Lua chon:";
		cin>>choice;
		cin.clear();
		cin.get();
		switch(choice)
		{
			case 1:{
				system("cls");
				menuBanDoc();
				break;
			}
			case 2:{
				system("cls");
				menuSach();
				break;
			}
			case 3:{
				system("cls");
				menuQuanLyMuonSach();
				break;
			}
			case 0:{
				system("cls");
				cout<<"press any key to exit"<<endl;
				exit(0);
				
				break;
			}
			case 4:{
				system("cls");
				SxTen();
				printQuanLyMuonSach();
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				SxSoLuongSach();
				printQuanLyMuonSach();
				system("pause");
				break;
			}
			case 6:{
				system("cls");
				TimTen();
				system("pause");
				break;
			}
		}
	}while(choice != 0);
}
