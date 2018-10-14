#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include"packages.h"
/*
 * No description
 */
class OvernightPackage: public Packages{
	// private section
	public:
		virtual void Nhap();
		virtual double calculateCost();
		virtual void Xuat();
	protected:
		double chiphiphutroi;
};

#endif // OVERNIGHTPACKAGE_H

