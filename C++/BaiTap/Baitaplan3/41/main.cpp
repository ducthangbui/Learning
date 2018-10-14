#include <iostream>
#include "account.h"
#include"checkingaccount.h"
#include"savingsaccount.h"
using namespace std;
/* He thong tai khoan*/

int main(int argc, char *argv[]) {
	Account a(100000);
	SavingsAccount s;
	CheckingAccount c;
	double x,y,lai, nap,rut;
	cout<<"Nhap so tien nap:";
	cin>>x;
	cout<<"so du TK sau khi nap la:" << a.Credit(x) <<endl;
	//cout<<" Nhap so tien can rut:";
	//cin>>y;
	cout<<" So du Tk sau khi rut la:" << a.Debit(y) << endl;
	s.Nhap();
	cout<< "So du Tk la:" << s.calculateInterest() <<endl;
	
	cout<<endl<<"so du TK hien tai la:"<<a.getBalance()<<endl;
	c.Nhap();
	cout<<"Nhap so tien nap:";
	cin>>nap;
	cout<<"So du TK sau khi nap la:"<<c.Credit(a,nap);
	
	cout<<endl<<"so du TK hien tai la:"<<a.getBalance()<<endl;
	cout<<endl<<"Nhap so tien rut:";
	cin>>rut;
	cout<< "So du TK sau khi rut tien la:" << c.Debit(a,rut); 
	return 0;
}
