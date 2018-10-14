#include "overnightpackage.h"
#include "packages.h" 
#include "twodaypackages.h"
#include<iostream>
#include<stdio.h>
using namespace std;
void OvernightPackage::Nhap()
{
	fflush(stdin);
	Packages::Nhap();
	cout<<"Nhap chi phi phu troi:";
	cin>>chiphiphutroi;
}
double OvernightPackage::calculateCost()
{
	return getKhoiLuong()*getPhiVanChuyen()+chiphiphutroi*getKhoiLuong();
}
void OvernightPackage::Xuat()
{

	cout<<"Tong chi phi trong ngay la:" << this->calculateCost() <<endl;
	
}

