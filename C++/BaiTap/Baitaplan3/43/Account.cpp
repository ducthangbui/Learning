#include "Account.h"
#include <iostream>

using namespace std;


Account::Account(double x)
{
	if (x >= 0.0) soduTK = x;
	else {
		soduTK = 0.0;
		cout<<"Gia tri khoi tao khong hop le!!!";
	}
}

void Account::Credit(double them){
	soduTK = soduTK + them;
}

void Account::Debit(double tru){
	if(tru <= soduTK){
		soduTK = soduTK - tru;
	} 
	else {
		cout<<"Hay nhap so tien rut <= soduTK"<<endl;
	}
}

double Account::getBalance(){
	return soduTK;
}

void Account::Nhap(){
	cout<<"Nhap so du TK:";
	cin>>soduTK;
	if(soduTK < 0.0){
		cout<<"So du TK vua nhap k hop le!!!"<<endl;
		soduTK = 0.0;
	}
}

void Account::Xuat(){
	cout<<"So du Tk hien tai la:"<<getBalance();
}
