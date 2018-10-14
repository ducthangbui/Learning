#include "overnightpackage.h"
#include "packages.h" 
#include "twodaypackages.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	vector <Packages *> p(2); 
	 int n;
 	size_t i=0;
 	int tong=0;
 	int ni;
 	cout<<"Nhap so Packages:";
	cin>>ni;
	do{
		 cout<<"1.Class OvernightPackage"<<endl
 			 <<"2.Class TwoDayPackages"<<endl;
		 cout<<"Ban chon:";
 		 cin>>n;
			switch(n){
				case 1: {
					system("cls");
					cout<<"Class OvernightPackage"<<endl;
    				 	p[i]= new OvernightPackage;
						 break;}
				case 2: {
					system("cls");
					cout<<"Class TwoDayPackages"<<endl;
     				p[i]= new TwoDayPackages;
     				break;
						}
					}
			p[i]->Nhap();
			p[i]->calculateCost();
			p[i]->Xuat();
			cout<<endl<<"Dia chi nguoi gui:"<<p[i]->getAddGui()
				<<endl<<"Dia chi nguoi nhan:"<<p[i]->getAddNhan()<<endl;
				tong += p[i]->calculateCost();
			cout<<"Tong calculateCost:"<<tong<<endl;
			i++;
	}while(i<ni);
	return 0;
}
