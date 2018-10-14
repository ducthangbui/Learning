#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
 * lop cha
 */
class Account
{
	// private section
	public:
		// class constructor
		Account(double x=0.0);
		double Credit(double);
		double Debit(double&);
		double getBalance();
		void setsoduTK(double);
	protected:
		double soduTK;
};

#endif // ACCOUNT_H

