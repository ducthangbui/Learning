#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
void input(char &c){
	cout<<"Nhap 1 ky tu: ";
	cin>>c;
}

void display(){
	int chon=1;
	char c;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(c);
		cout<<"So Integer tuong ung: "<<static_cast<int>(c)<<endl;
		cout<<"----------------"<<endl;
		cout<<"0. Dung		1. Tiep tuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
