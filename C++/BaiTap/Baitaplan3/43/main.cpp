#include <cstdlib>
#include <iostream>
#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main(int argc, char *argv[])
{
	vector <Account*> p(3);
	int n;
 	size_t i=0;
 	double them,sotienrut;
 	int lai;
	int sotk,dem=0;
	cout<<"Co tat ca bnhiu tk ? :";
	cin>>sotk;
	while(dem < sotk)
	{
		 cout<<"1.Class CheckingAccount"<<endl
 			 <<"2.Class SavingsAccount"<<endl;
		 cout<<"Ban chon:";
 		 cin>>n;
			switch(n){
				case 1: {
					system("cls");
					cout<<"Class CheckingAccount"<<endl;
    				 	p[i]= new CheckingAccount;
    				 	p[i]->Nhap();
						 break;}
				case 2: {
					
					system("cls");
					cout<<"Class SavingsAccount"<<endl;
     				p[i]= new SavingsAccount;
     				p[i]->Nhap();
     				lai = p[i]->calculateInterest();
     				p[i]->Credit(lai);
     				break;
						}
					}
			
			cout<<"Nhap so tien can them:";
			cin>>them;
			p[i]->Credit(them);
			cout<<"Nhap so tien can rut:";
			cin>>sotienrut;
			p[i]->Debit(sotienrut);
			p[i]->Xuat();
		i++;
		dem++;
		
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
