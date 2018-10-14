#include "packages.h" // class's header file
#include<iostream>
#include <stdio.h>
using namespace std;
void Packages::Nhap()
{
	fflush(stdin);
	cout<<"Nhap ten nguoi gui:";
	getline(cin,tenNggui);
	cout<<"Nhap dia chi nguoi gui:";
	getline(cin,diachiNggui);
	cout<<"Nhap ten nguoi nhan:";
	getline(cin,tenNgnhan);
	cout<<"Nhap dia chi nguoi nhan:";
	getline(cin,diachiNgnhan);
	do{
	cout<<"Nhap khoi luong(kg) hang van chuyen:";
	cin>>khoiluong;
	cout<<"Nhap phi van chuyen/kg:";
	cin>>phivanchuyen;
	}while(khoiluong<0 || phivanchuyen<0);
}
double Packages::calculateCost()
{
	return khoiluong*phivanchuyen;
}
double Packages::getKhoiLuong()
{
	return khoiluong;
}
void Packages::setKhoiLuong(double x)
{
	khoiluong=x;
}
double Packages::getPhiVanChuyen()
{
	return phivanchuyen;
}
void Packages::Xuat()
{
	cout<<"Phi van chuyen tuong ung la:"<< calculateCost();
}

string Packages::getAddGui(){
	return diachiNggui;
}

string Packages::getAddNhan(){
	return diachiNgnhan;
}
