#ifndef TWODAYPACKAGES_H
#define TWODAYPACKAGES_H

/*
 * Phi luu kho trong 2 ngay
 * (Lop dan xuat(lop con cua lop Packages))
 */

class TwoDayPackages: public Packages
{
	// private section
	public:
		TwoDayPackages(double p2d=1);
		virtual void NhapPhi2ngay();
		virtual double calculateCost();
		virtual void Xuat();
	protected:
		double phi2ngay;
};

#endif // TWODAYPACKAGES_H

