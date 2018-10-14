#include<iostream>
#include<windows.h>
using namespace std;
void input(int &a, int &b){
	cout<<"Nhap 2 so a, b: ";
	cin>>a>>b;
}
int UCLN(int a, int b){
	int r;
	if (b>a){
		swap(a,b);
	}
	while (b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int BCNN(int a, int b){
	return (a*b/UCLN(a,b));
}
void display(){
	int chon=1, a, b;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(a,b);
		cout<<"UCLN: "<<UCLN(a,b)<<endl;
		cout<<"BCNN: "<<BCNN(a,b)<<endl;
		cout<<"----------------"<<endl;
		cout<<"1.Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
