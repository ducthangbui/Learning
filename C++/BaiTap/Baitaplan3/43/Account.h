#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
	public:
		Account(double x=0.0);
		virtual void Credit(double );
		virtual void Debit(double );
		virtual double getBalance();
		virtual void Xuat();
		virtual void Nhap();
		virtual double calculateInterest();
	protected:
		double soduTK;
};

#endif
