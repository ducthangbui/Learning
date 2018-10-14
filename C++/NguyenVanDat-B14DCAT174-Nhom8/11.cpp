#include<iostream>
#include<windows.h>
using namespace std;
void input(unsigned int &n){
	cout<<"Nhap 1 so nguyen: ";
	cin>>n;
}
void phantich(int n){
	int i=2;
	if (n<=1) {
		cout<<"Khong the phan tich."<<endl;
		return;
	}
	cout<<"Phan tich ra thua so nguyen to: "<<endl;
	while (i!=n){
		if(n%i==0){
			cout<<i<<" x ";
			n/=i;
		}
		else i++;
	}
	cout<<i<<endl;
}

void display(){
	int chon=1;
	unsigned int n;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(n);
		phantich(n);
		cout<<"----------------"<<endl;
		cout<<"1. Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
