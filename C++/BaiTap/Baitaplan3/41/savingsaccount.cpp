#include "savingsaccount.h" // class's header file
#include"account.h"
#include<iostream>
using namespace std;
// class constructor
SavingsAccount::SavingsAccount(double x,double y)
{
	// insert your code here
	soduTK=x;
	lai=y;
}
double SavingsAccount::calculateInterest()
{
	return (lai / 100) * soduTK + soduTK;
}
void SavingsAccount::Nhap()
{
	cout<<"Nhap so tien lai(%):";
	cin>>lai;
	do{
		cout<<"Nhap so du tk:";
		cin>>soduTK;
	}while(soduTK < 0.0);
}

