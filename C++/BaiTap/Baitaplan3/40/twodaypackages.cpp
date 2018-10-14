#include "overnightpackage.h"
#include "packages.h" 
#include "twodaypackages.h"
#include<iostream>
using namespace std;
TwoDayPackages::TwoDayPackages(double p2d)
{
	p2d=phi2ngay;
}
void TwoDayPackages::NhapPhi2ngay()
{
	Packages::Nhap();
	cout<<"Nhap phi luu kho trong 2 ngay:";
	cin>>phi2ngay;
}
double TwoDayPackages::calculateCost()
{

	return (getKhoiLuong()*getPhiVanChuyen())+phi2ngay;
}
void TwoDayPackages::Xuat()
{
	cout<<"Tong chi phi la :" << this->calculateCost() << endl;
}

