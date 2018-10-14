#include "quanly.h"

QuanLy::QuanLy(char* fnameKH, char* fnameLLS, char* fnameSTK)
{
	strcpy(fileNameKH,fnameKH);
	strcpy(fileNameLLS,fnameLLS);
	strcpy(fileNameSTK,fnameSTK);
	loadKH(fileNameKH);
	loadLLS(fileNameLLS);
	loadSTK(fileNameSTK);
	cout<<"San sang! Bam phim bat ky de khoi dong..."<<endl;
	system("pause");
}

QuanLy::~QuanLy()
{
	saveKH(fileNameKH);
	saveLLS(fileNameLLS);
	saveSTK(fileNameSTK);
	system("pause");
}

void QuanLy::loadKH(char* fname)
{
	fstream file;
	file.open(fname, ios::in|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Doc file du lieu: "<<fname<<endl;
	dsKH.clear();
	KhachHang tmp;
	while (file.read((char *)&tmp,sizeof(KhachHang))){
		dsKH.push_back(tmp);
	};
	if(tmp.MaKH!=0) tmp.SetgenMaKH(tmp.GetMaKH());
	file.close();
}

void QuanLy::loadLLS(char *fname)
{
	fstream file;
	file.open(fname, ios::in|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Doc file du lieu: "<<fname<<endl;
	dsLLS.clear();
	LoaiLaiSuat tmp;
	while (file.read((char *)&tmp,sizeof(LoaiLaiSuat))){
		dsLLS.push_back(tmp);
	};
	file.close();
}

void QuanLy::loadSTK(char *fname)
{
	fstream file;
	file.open(fname, ios::in|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Doc file du lieu: "<<fname<<endl;
	dsSTK.clear();
	SoTietKiem tmp;
	while (file.read((char *)&tmp,sizeof(SoTietKiem))){
		dsSTK.push_back(tmp);
	};
	if(tmp.GetMaSTK()!=0) tmp.SetgenMaSTK(tmp.GetMaSTK()+1);
	file.close();
}

void QuanLy::saveKH(char* fname)
{
	fstream file;
	file.open(fname, ios::out|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Ghi de lieu vao file: "<<fname<<endl;
	for(int i=0; i<dsKH.size();i++){
		file.write((char *)&(dsKH[i]),sizeof(KhachHang));
	}
	file.close();
}

void QuanLy::saveLLS(char *fname)
{
	fstream file;
	file.open(fname, ios::out|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Ghi de lieu vao file: "<<fname<<endl;
	for(int i=0; i<dsLLS.size();i++){
		file.write((char *)&(dsLLS[i]),sizeof(LoaiLaiSuat));
	}
	file.close();
}

void QuanLy::saveSTK(char *fname)
{
	fstream file;
	file.open(fname, ios::out|ios::binary);
	if (!file){
		cerr<<"Tao file du lieu moi: "<<fname<<endl;
		return;
	}
	cout<<"Ghi de lieu vao file: "<<fname<<endl;
	for(int i=0; i<dsSTK.size();i++){
		file.write((char *)&(dsSTK[i]),sizeof(SoTietKiem));
	}
	file.close();
}

void QuanLy::printKH(int option){
	int i=0, n=dsKH.size();
	string type[3]={"-------","CA NHAN","TAP THE"};
	cout<<"----------------------- THONG TIN KHACH HANG "<<type[option]<<"------------------"<<endl;
	cout<<"TT | MaKH  | LoaiKH  |    Ho va Ten    |        Email         |  SDT  "<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	for(i=0; i<n; i++)
	{
		if (option!=0) if(dsKH[i].LoaiKH!=type[option]) continue;
		cout<<setw(2)<<i<<" | "<<setw(5)<<dsKH[i].MaKH<<" | "<<setw(7)<<dsKH[i].LoaiKH<<" | "
			<<setw(15)<<setiosflags(ios::left)<<dsKH[i].HoTen<<" | "<<setw(20)<<dsKH[i].Email
			<<" | "<<setw(10)<<resetiosflags(ios::left)<<dsKH[i].Sdt<<endl;
	}
	cout<<"----------------------------------------------------------------------"<<endl;
}

void QuanLy::printLLS(){
	int i=0, n=dsLLS.size();
	cout<<"-------------------------- CAC LOAI LAI SUAT -------------------------"<<endl;
	cout<<"| TT |  Loai lai suat  |  Lai suat  |           Mo ta                 "<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	for(i=0; i<n; i++){
		cout<<"| "<<setw(2)<<i<<" | "<<setw(15)<<setiosflags(ios::left)<<dsLLS[i].LoaiLS<<" | "
			<<setw(10)<<resetiosflags(ios::left)<<fixed<<setprecision(2)<<dsLLS[i].Laisuat<<" | "
			<<setw(30)<<setiosflags(ios::left)<<dsLLS[i].Mota<<" | "<<resetiosflags(ios::left)<<endl;
	}
	cout<<"----------------------------------------------------------------------"<<endl;
}

void QuanLy::printSTK(){
	int i=0, n=dsSTK.size();
	cout<<"----------------------- DANH SACH SO TIET KIEM -----------------------"<<endl;
	cout<<"| TT |MaSTK|  MaKH  |       So tien gui        |    So thang gui      "<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	for(i=0; i<n; i++){
		cout<<"| "<<setw(2)<<i<<" | "<<setw(3)<<dsSTK[i].MaSTK<<" | "<<setw(6)<<dsSTK[i].MaKH<<" | "
			<<setw(20)<<fixed<<setprecision(2)<<dsSTK[i].Sotiengui<<" VND | "
			<<setw(2)<<dsSTK[i].Sothanggui<<" thang"<<endl;
	}
	cout<<"----------------------------------------------------------------------"<<endl;
}

void QuanLy::addKH(){
	char *name= new char[25], *mail=new char[50], *num=new char[12], *type=new char[7];
	int loai;
	cout<<"---------------------- NHAP THONG TIN KHACH HANG ---------------------"<<endl;
	cout<<"Ho Ten: "; cin.getline(name,25);
	cout<<"Email: "; cin>>mail;
	cout<<"Sdt: "; cin>>num;
	cout<<"Chon loai khach hang:"<<endl;
	cout<<"1. Ca nhan		2. Tap the"<<endl;
	cin>>loai;
	while(loai!=1&&loai!=2){
		cout<<"Loai khong dung, chon lai: ";
		cin>>loai;
	}
	cin.clear();
	cin.get();
	if (loai==1) strcpy(type,"CA NHAN");
	else strcpy(type,"TAP THE");
	KhachHang tmp(name,type,num,mail);
	delete [] num;
	delete [] name;
	delete [] mail;
	delete [] type;
	dsKH.push_back(tmp);
}

void QuanLy::addLLS(){
	char type[20], detail[50];
	float ls;
	cout<<"-------------------------- THEM LOAI LAI SUAT ------------------------"<<endl;
	cout<<"Nhap ten loai lai suat: ";
	cin.getline(type,20);
	cout<<"Nhap mo ta: ";
	cin.getline(detail,50);
	cout<<"Nhap lai suat: ";
	cin>>ls;
	while (ls<0){
		cout<<"Nhap lai: ";
		cin>>ls;
	}
	cin.clear();
	cin.get();
	LoaiLaiSuat tmp(type,ls,detail);
	dsLLS.push_back(tmp);
}

void QuanLy::addSTK(){
	system("cls");
	cout<<"--------------------------- CHON KHACH HANG --------------------------"<<endl;
	printKH(0);
	if (dsKH.size()==0){
		cout<<"Khong co du lieu khach hang. KHONG THE TAO STK!"<<endl;
		system("pause");
		return;
	}
	cout<<"Nhap so thu tu khach hang muon lap so tiet kiem: ";
	int kh;
	cin>>kh;
	while(kh<0||kh>=dsKH.size()){
		cout<<"Nhap lai:";
		cin>>kh;
	}
	int pass=0;
	do{
		if (dsKH[kh].SoSTK>=MAXSTK){
			cout<<"Khach hang da co toi da so STK, KHONG THE TAO THEM."<<endl;
			system("pause");
			return;
		}
		system("cls");
		cout<<"-------------------------- CHON LOAI LAI SUAT -----------------------"<<endl;
		printLLS();
		if (dsLLS.size()==0){
			cout<<"Khong co du lieu loai lai suat. KHONG THE TAO STK!"<<endl;
			system("pause");
			return;
		}
		cout<<"Nhap so thu tu loai lai suat: ";
		int lls;
		cin>>lls;
		while(lls<0||lls>=dsLLS.size()){
			cout<<"Nhap lai:";
			cin>>lls;
		}
		system("cls");
		cout<<"--------------------------- TAO SO TIET KIEM ------------------------"<<endl;
		cout<<"-------------------------- CHON LOAI LAI SUAT -----------------------"<<endl;
		cout<<"Nhap so tien gui: ";
		double stg;
		cin>>stg;
		while(stg<0){
			cout<<"Nhap lai:";
			cin>>stg;
		}
		cout<<"Nhap so thang gui: ";
		unsigned int sthg;
		cin>>sthg;
		while(sthg<0){
			cout<<"Nhap lai:";
			cin>>sthg;
		}
		SoTietKiem tmp(dsKH[kh].MaKH, dsLLS[kh].LoaiLS,stg,sthg);
		dsSTK.push_back(tmp);
		dsKH[kh].MaSTK[dsKH[kh].SoSTK]=tmp.GetMaSTK();
		dsKH[kh].SoSTK++;
		dsKH[kh].Tongtiengui+=tmp.Sotiengui;
		cout<<"Them thanh cong!"<<endl;
		cout<<"1. Them tiep cho khach hang nay		0. Thoi"<<endl;
		cin>>pass;
		cin.clear();
		cin.get();
	} while (pass==1);
}

void QuanLy::removeKH(char *fname){
	
}

void QuanLy::removeLLS(char *fname){
	
}

void QuanLy::removeSTK(char *fname){
	
}

void QuanLy::editKH(char *fname){
	
}

void QuanLy::editLLS(char *fname){
	
}

void QuanLy::editSTK(char *fname){
	
}

void QuanLy::sortSTK(){
	int n=dsSTK.size();
	for (int i=0; i<n; i++){
		for (int j=0; j<n-i-1; j++){
			if (dsSTK[j].GetSotiengui()>dsSTK[j+1].GetSotiengui()){
				SoTietKiem tmp;
				tmp=dsSTK[j];
				dsSTK[j]=dsSTK[j+1];
				dsSTK[j+1]=tmp;
			}
		}
	}
}

void QuanLy::makeReport(){
	system("cls");
	cout<<"------------------------ BANG KE TONG TIEN GUI -----------------------"<<endl;
	for (int i=0; i<dsKH.size(); i++){
		cout<<setw(5)<<dsKH[i].MaKH<<" | "<<setiosflags(ios::left)<<setw(20)<<dsKH[i].HoTen<<" | "<<setw(8)
		<<dsKH[i].LoaiKH<<" | "<<setw(12)<<setiosflags(ios::showpoint)<<resetiosflags(ios::left)<<fixed<<dsKH[i].Tongtiengui<<" VND"<<endl;
	}
	system("pause");
}

void QuanLy::menuKH(){
	int c;
	do{
		system("cls");
		cout<<"------------------------- QUAN LY KHACH HANG -------------------------"<<endl;
		cout<<"1. Hien thi danh sach khach hang"<<endl;
		cout<<"2. Them khach hang"<<endl;
		cout<<"3. Tim kiem, xoa, sua khach hang"<<endl;
		cout<<"4. Luu lai"<<endl;
		cout<<"0. Quay lai..."<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"Lua chon: ";
		cin>>c;
		cin.clear();
		cin.get();
		cout<<"----------------------------------------------------------------------"<<endl;
		switch(c){
			case 1:{
				int i =0;
				cout<<"0. Toan bo danh sach"<<"\t";
				cout<<"1. Ca nhan"<<"\t";
				cout<<"2. Tap the"<<endl;
				cout<<"Lua chon: ";
				cin>>i;
				cin.clear();
				cin.get();
				printKH(i);
				system("pause");
				break;
			}
			case 2:{
				addKH();
				cout<<"Them thanh cong!"<<endl;
				system("pause");
				break;
			}
			case 3:{
				cout<<"Chuc nang chua hoan thien ..."<<endl;
				system("pause");
				break;
			}
			case 4:{
				saveKH(fileNameKH);
				cout<<"Thanh cong!"<<endl;
				system("pause");
				break;
			}
		}
	} while (c!=0);
}

void QuanLy::menuLLS(){
	int c;
	do{
		system("cls");
		cout<<"-------------------------- QUANG LY LAI SUAT -------------------------"<<endl;
		cout<<"1. Hien thi danh cac loai lai suat"<<endl;
		cout<<"2. Them loai lai suat"<<endl;
		cout<<"3. Tim kiem, xoa, sua loai lai suat"<<endl;
		cout<<"4. Luu lai"<<endl;
		cout<<"0. Quay lai..."<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"Lua chon: ";
		cin>>c;
		cin.clear();
		cin.get();
		switch(c){
			case 1:{
				printLLS();
				system("pause");
				break;
			}
			case 2:{
				addLLS();
				break;
			}
			case 3:{
				cout<<"Chuc nang chua hoan thien ..."<<endl;
				system("pause");
				break;
			}
			case 4:{
				saveLLS(fileNameLLS);
				cout<<"Thanh cong!"<<endl;
				system("pause");
				break;
			}
		}
	} while (c!=0);
}

void QuanLy::menuSTK(){
	int c;
	do{
		system("cls");
		cout<<"------------------------ QUAN LY SO TIET KIEM ------------------------"<<endl;
		cout<<"1. Hien thi danh sach so tiet kiem"<<endl;
		cout<<"2. Them so tiet kiem"<<endl;
		cout<<"3. Tim kiem, xoa, sua so tiet kiem"<<endl;
		cout<<"4. Sap xep so tiet kiem theo so tien gui"<<endl;
		cout<<"5. Luu lai"<<endl;
		cout<<"0. Quay lai..."<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"Lua chon: ";
		cin>>c;
		cin.clear();
		cin.get();
		switch(c){
			case 1:{
				printSTK();
				system("pause");
				break;
			}
			case 2:{
				addSTK();
				break;
			}
			case 3:{
				cout<<"Chuc nang chua hoan thien ..."<<endl;
				system("pause");
				break;
			}
			case 4:{
				sortSTK();
				printSTK();
				system("pause");
				break;
			}
			case 5:{
				saveSTK(fileNameSTK);
				cout<<"Thanh cong!"<<endl;
				system("pause");
				break;
			}
		}
	} while (c!=0);
}

void QuanLy::display(){
	int c;
	do{
		system("cls");
		cout<<"--------------- CHUONG TRINH QUAN LY TIEN GUI TIET KIEM --------------"<<endl;
		cout<<"1. Quan ly khach hang..."<<endl;
		cout<<"2. Quan ly loai lai suat..."<<endl;
		cout<<"3. Quan ly so tiet kiem..."<<endl;
		cout<<"4. Ket xuat bao cao."<<endl;
		cout<<"0. Ket thuc"<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"Lua chon: ";
		cin>>c;
		cin.clear();
		cin.get();
		switch(c){
			case 1: {
				menuKH();
				break;
			}
			case 2: {
				menuLLS();
				break;
			}
			case 3: {
				menuSTK();
				break;
			}
			case 4: {
				makeReport();
				break;
			}
		}
	} while (c!=0);
}
