#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount: public Account
{
	public:
		CheckingAccount(double x=0.0,double y=0.0);
		virtual void Nhap();
		virtual void Credit(double );
		virtual void Debit(double );
		virtual void Xuat();
	protected:
		double phi;
};

#endif
