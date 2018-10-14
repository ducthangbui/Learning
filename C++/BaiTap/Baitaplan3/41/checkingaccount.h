#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include"account.h"
/*
 * No description
 */
class CheckingAccount: public Account
{
	// private section
	public:
		// class constructor
		CheckingAccount(double x=0.0,double y=0.0);
		bool Debit1(Account&,double);
		double Credit(Account&,double);
		double Debit(Account&,double);
		void Nhap();
	protected:
		double phigiaodich;
};

#endif // CHECKINGACCOUNT_H

