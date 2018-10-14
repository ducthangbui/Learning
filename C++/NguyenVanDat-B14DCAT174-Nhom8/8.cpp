#include<iostream>
#include<windows.h>
using namespace std;
void input(float &w, float &h){
	cout<<"Nhap vao can nang (kg):	";
	cin>>w;
	cout<<"Nhap vao chieu cao (m):	";
	cin>>h;
}

float BMI(float w, float h){
	return w/(h*h);
}

void display(){
	int chon=1;
	float w=0, h=0;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(w, h);
		cout<<"----------------"<<endl;
		cout<<"Chi so BMI cua ban:	"<<BMI(w,h)<<endl;
		cout<<"----------------"<<endl;
		cout<<"Thieu can: nho hon 18.5"<<endl;
		cout<<"Trung binh: giua 18.5 va 24.9"<<endl;
		cout<<"Thua can: giua 25 va 29.9"<<endl;
		cout<<"Beo phi: 30 hoac lon hon"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. Tinh lai		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
