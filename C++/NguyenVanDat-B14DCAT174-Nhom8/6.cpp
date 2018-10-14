#include<iostream>
#include<windows.h>
using namespace std;
void input(int &n){
	cout<<"Nhap 1 so co 5 chu so: ";
	cin>>n;
	while(n>100000||n<10000){
		cout<<"Nhap lai:";
		cin>>n;
	}
}
int tachso(int &n, int &cs){
	int m=n/cs;
	n%=cs;
	cs/=10;
	return m;
}

void display(){
	int chon=1, n, cs=10000;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(n);
		while (cs!=0){
			cout<<tachso(n,cs)<<"   ";
		}
		cout<<endl;
		cout<<"----------------"<<endl;
		cout<<"0. Dung		1. Tiep tuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
