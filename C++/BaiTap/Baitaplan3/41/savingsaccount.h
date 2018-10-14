#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"account.h"
/*
 * No description
 */
class SavingsAccount: public Account
{
	// private section
	public:
		// class constructor
		SavingsAccount(double x=0.0,double y=0.0);
		void Nhap();
		double calculateInterest();
	protected:
		double lai;
};

#endif // SAVINGSACCOUNT_H

