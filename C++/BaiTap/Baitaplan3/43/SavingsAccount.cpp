#include "SavingsAccount.h"
#include <iostream>

using namespace std;


SavingsAccount::SavingsAccount(double x,double y)
{
	lai = x;
	soduTK = y;
}

void SavingsAccount::Nhap(){
	Account::Nhap();
	cout<<"Nhap lai suat(%):";
	cin>>lai;
}

double SavingsAccount::calculateInterest(){
	return (lai / 100) * soduTK;
}

void SavingsAccount::Xuat(){
	cout<<"So du TK hien tai la:"<<soduTK<<endl;
}
