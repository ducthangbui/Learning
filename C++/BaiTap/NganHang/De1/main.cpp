#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bandoc.h"
#include "sach.h"
#include "quanlymuonsach.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu()
{
	BanDoc b[100];
	Sach s[100];
	QuanLyMuonSach qlms[100];
	int nb,ns;
	
	fstream banDoc("BD.DAT",ios::out );
	fstream sach("SACH.DAT",ios::out );
	//fstream qlms("QLMS.DAT",ios::out | ios::in);
	
	int chon;
	do
	{
		cout<<"MENU"<<endl
			<<"1.Sach"<<endl
			<<"2.Ban Doc "<<endl
			<<"3.Quan Ly Muon Sach"<<endl
			<<"0.Thoat"<<endl
			<<"Ban chon:";
			cin>>chon;
		switch(chon)
		{
			case 2:{
				system("cls");
				cout<<"Nhap so luong ban doc:";
				cin>>nb;
				for(int i=0;i<nb;i++)
				{
					cout<<endl<<"Nhap ban doc thu "<<i<<":"<<endl;
					b[i].Nhap();
					b[i].GhiFile(banDoc);
				}banDoc.close();
				system("cls");
				BanDoc b1;
				if(!banDoc)
				{
					cerr<<endl<<"Khong mo dc file"<<endl;
				}
				while(banDoc)
				{
					b1.DocFile(banDoc);
					if(!banDoc.eof()) b1.Xuat();
				}banDoc.close();
				break;
			}
			case 1:{
				system("cls");
				cout<<endl<<"Nhap so luong dau sach:";
				cin>>ns;
				//cin.ignore();
				for(int i=0;i<ns;i++)
				{
					cout<<endl<<"Nhap thong tin dau sach thu "<<i<<":"<<endl;
					s[i].Nhap();
					s[i].GhiFile(sach);
				}sach.close(); system("cls");
				cout<<endl<<"Cac dau sach co trong file"<<endl;
				fstream isach("SACH.DAT",ios::in);
				Sach *s2;
				if(!isach)
				{
					cerr<<endl<<"Khong mo duoc file"<<endl;
					exit(1);
				}
				while(isach)
				{
					s2 = new Sach;
					s2->DocFile(sach);
					if(!isach.eof()) s2->Xuat();
				}isach.close();
				break;
			}
			case 3:{
				system("cls");
				for(int i=0;i<nb;i++)
				{
					qlms[i].Nhap(b[i]);
					qlms[i].GhiFile(b[i]);
				}
				system("cls");
				for(int i=0;i<nb;i++)
				{
					qlms[i].Xuat(b[i]);
				}
				break;
			}
		}
	}while(chon!=0);
}
int main(int argc, char *argv[]) {
	menu();
	return 0;
}
