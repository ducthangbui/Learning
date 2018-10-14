#include "menu.h" // class's header file
#include <iostream>
#include <cstdlib>
#include "bai36_a.h"
#include "bai36_b.h"
#include "bai36_c.h"
#include "bai36d.h"
#include "bai36e.h"
#include "bai36g.h"
#include "bai36g2.h"
#include "bai36h.h"
#include "bai36i.h"
#include "bai36p.h"

using namespace std;

void Menu::ListBai(){
	cout<<"1. Y a" << endl
		<<"2.Y b" <<endl
		<<"3.Y c" <<endl
		<<"4.Y d" <<endl
		<<"5.Y e" << endl
		<<"6.Y g"<<endl
		<<"7.Y g.Bai 17/Lan1"<<endl
		<<"8.Y h"<<endl
		<<"9.Y i"<<endl
		<<"10.Y p"<<endl
		<<"0.Exit"<<endl;
}
void Menu::ChonBai()
{
	Menu::ListBai();
	cout<<"Nhap bai:";
	cin>>bai;
	switch(bai){
		case 1: {
			Bai36 bai36;
			cout<<endl<<"Y a"<<endl;
			bai36.Nhap();
			bai36.Xuat();
			break;
		}
		case 2: {
			system("cls");
			cout<<endl<<"Y b"<<endl<<endl;
			bai36_b bai36b;
			bai36b.Nhap();
			bai36b.Xuat();
			break;
		}
		case 3:{
			system("cls");
			cout<<endl<<"Y c"<<endl<<endl;
			bai36_c bai36c;
			bai36c.Nhap();
			bai36c.Xuat();
			break;
		}
		case 4:{
			system("cls");
			cout<<endl<<"Y d"<<endl<<endl;
			Bai36d bai36d;
			bai36d.Nhap();
			bai36d.Xuat();
			break;
		}
		case 5:{
			system("cls");
			cout<<endl<<"Y e"<<endl<<endl;
			Bai36e bai36e;
			bai36e.CoSo();
			break;
		}
		case 6:{
			system("cls");
			cout<<endl<<"Y g"<<endl<<endl;
			Bai36g bai36g;
			//bai36g.Nhap();
			bai36g.TichNgto();
			break;
		}
		case 7:{
			system("cls");
			cout<<endl<<"Y g"<<endl;
			Bai36g2 bai36g;
			int n,a[100],x;
			bai36g.Nhap(n,a);
			cout<<"Mang vua nhap la:"<<endl;
			bai36g.Xuat(n,a);
			cout<<endl;
			bai36g.Max(n,a);
			cout<<"Mang sau khi da sap xep la:"<<endl;
			bai36g.Sort(n,a);
			bai36g.Xuat(n,a);
			cout<<endl;
			bai36g.Insert(n,x,a);
			cout<<"Mang sau khi chen la:";
			bai36g.Xuat(n,a);
			break;
		}
		case 8:{
			system("cls");
			Bai36h bai36h;
			bai36h.Nhap();
			bai36h.Xuat();
			break;
		}
		case 9:{
			system("cls");
			int a[100][100],n;
			Bai36i bai36i;
			bai36i.Nhap(a, n);
			cout << "Ma tran vua nhap la:" << endl;
			bai36i.Xuat(a, n);
			cout << endl;
			bai36i.Tong(a, n);
			bai36i.MTHoanVi(a, n);
			cout << endl;
			cout << "\nDet=" << bai36i.Det(a, n) << endl;
			cout<<endl <<"Ma tran nghich dao:"<<endl<<endl;
			bai36i.MTnghichdao(a, n);
			break;
		}
		case 10:{
				system("cls");
				cout<<"Y p"<<endl;
				Bai36p bai36p;
				bai36p.TachTen();
			break;
		}
		case 0:{
			system("cls");
			cout<<"Ban da chon thoat!!! Nhan phim bat ki de thoat!!!"<<endl;
			exit(0);
			break;
		}
	}
}


