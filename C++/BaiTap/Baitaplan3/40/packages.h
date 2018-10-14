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
		void Nhap();
		void Xuat();
		double getKhoiLuong();
		void setKhoiLuong(double);
		//void setPhiVanChuyen(double);
		double getPhiVanChuyen();
		double calculateCost();
	protected:
		string tenNggui,tenNgnhan;
		string diachiNggui,diachiNgnhan;
		double khoiluong;
		double phivanchuyen;
		
};

#endif // PACKAGES_H

