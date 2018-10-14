#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount: public Account
{
	public:
		SavingsAccount(double x=1.0, double y=0.0);
		virtual void Nhap();
		virtual double calculateInterest();
		virtual void Xuat();
	protected:
		double lai;
};

#endif
