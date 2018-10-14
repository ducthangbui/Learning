#include "checkingaccount.h" // class's header file
#include"account.h"
#include<iostream>
using namespace std;
// class constructor
CheckingAccount::CheckingAccount(double x,double y)
{
	// insert your code here
	soduTK=x;
	phigiaodich=y;
}
double CheckingAccount::Credit(Account &a,double y)
{
	a.setsoduTK(a.getBalance()+y-phigiaodich);
	return a.getBalance();
}
bool CheckingAccount::Debit1(Account &a,double sotienrut)
{
	double tong=a.getBalance()-phigiaodich-sotienrut;
	if(tong>=0) return true;
	else return false;
}
double CheckingAccount::Debit(Account &a,double sotienrut)
{
	double tong=a.getBalance()-phigiaodich-sotienrut;
	if(Debit1(a,sotienrut)==true)
	a.setsoduTK(tong);
	else {
		cout<<"So du trong tai khoan khong du" <<endl;
		return 0;
	}
	cout << endl <<"so tien rut :"<< sotienrut <<endl;
	return a.getBalance();
}
void CheckingAccount::Nhap()
{
	cout<<"Nhap chi phi giao dich:";
	cin>>phigiaodich;
	/*do{
		cout<<"Nhap so du tk:";
		cin>>soduTK;
	}while(soduTK < 0.0);*/
}


