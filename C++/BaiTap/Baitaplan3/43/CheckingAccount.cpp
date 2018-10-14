#include "CheckingAccount.h"
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount(double x,double y)
{
	phi = x;
	soduTK = y;
}

void CheckingAccount::Nhap(){
	Account::Nhap();
	cout<<"Nhap phi giao dich:";
	cin>>phi;
}

void CheckingAccount::Credit(double them){
	soduTK = soduTK + them - phi;
}

void CheckingAccount::Debit(double tru){
	if(tru <= soduTK){
		soduTK = soduTK - tru - phi;
	} 
	else {
		cout<<"Hay nhap so tien rut <= soduTK"<<endl;
	}
}

void CheckingAccount::Xuat(){
	cout<<"So du TK hien tai la:"<<soduTK<<endl;
}
