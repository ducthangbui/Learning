#include "overnightpackage.h"
#include "packages.h" 
#include "twodaypackages.h"
#include<iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Packages p,*p2;
	TwoDayPackages tp;
	//p=&tp;
	OvernightPackage op;
	//p2=&op;
	//p.Nhap();
	//p.Xuat();
	cout<<endl;
	tp.NhapPhi2ngay();
	tp.Xuat();
	//p=&op;
	cout<<endl;
	op.Nhap();
	op.Xuat();
	return 0;
}
