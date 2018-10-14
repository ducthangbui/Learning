#include <iostream>
#include "khachhang.h"
#include "bangsapxep.h"
#include "phong.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*KhachHang khach;
	khach.Nhap();
	khach.Xuat();*/
	KhachHang k;
	/*int kn, demk=1;
	cout<<"Nhap so khach hang can them:";
	cin>>kn;
	while (demk <= kn)
	{
		k.Nhap();
		k.GhiFile();
		demk++;	
	}*/
	k.Xuat();
	
	Phong p;
	/*int n,dem=1;
	cout<<"Nhap so phong can them:";
	cin>>n;
	while(dem<=n)
	{
		p.Nhap();
		p.GhiFile();
		dem++;
	}
	//p.Xuat();
	/*BangSapXep b;
	b.Nhap(k,p);
	b.Xuat(k,p);*/
	return 0;
}
