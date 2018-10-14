#include "account.h" // class's header file
#include<iostream>
using namespace std;
// class constructor
Account::Account(double x)
{
	// insert your code here
	if(x>=0.0) soduTK=x;
	else {
		soduTK=0.0;
		cout<< "Gia tri khoi tao khong hop le "<< endl;
	}
}
double Account::Credit(double x)
{
	soduTK=soduTK+x;
	return soduTK;
}
double Account::Debit(double &y)
{
	//double kqua;

		cout<<" Nhap so tien can rut:";
		cin>>y;
		
		if(y>soduTK) {
	cout<<"Khong rut duoc so tien vuot qua so du hien co" <<endl;
	soduTK=soduTK+y;
	}
	soduTK= soduTK - y;
	
	return soduTK;
}
void Account::setsoduTK(double x)
{
	soduTK=x;
}
double Account::getBalance()
{
	return soduTK;
}


