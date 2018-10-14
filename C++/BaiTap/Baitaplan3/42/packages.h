#ifndef PACKAGES_H
#define PACKAGES_H
#include<iostream>
using namespace std;
/*
 * Lop cha
 * Base Class
 */
class Packages
{
	// private section
	public:
		//Packages();
		virtual void Nhap();
		virtual void Xuat();
		virtual double getKhoiLuong();
		virtual void setKhoiLuong(double);
		//void setPhiVanChuyen(double);
		virtual double getPhiVanChuyen();
		virtual double calculateCost();
		virtual string getAddGui();
		virtual string getAddNhan();
	protected:
		string tenNggui,tenNgnhan;
		string diachiNggui,diachiNgnhan;
		double khoiluong;
		double phivanchuyen;
		
};

#endif // PACKAGES_H

