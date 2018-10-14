#include<iostream>
#define Pi 3.14159;
using namespace std;

void input(int &r){
	cout<<"Nhap vao ban kinh hinh tron: ";
	cin>>r;
	while(r<0){
		cout<<"Nhap lai: ";
		cin>>r;
	}
};

int diameter(int r){
	return 2*r;
};

int area(int r){
	return r*r*Pi;
};

float circumference(int r){
	return 2*r*Pi;
};

void display(int r){
	cout<<"Duong kinh la: "<<diameter(r)<<endl;
	cout<<"Chu vi la: "<<circumference(r)<<endl;
	cout<<"Dien tich la: "<<area(r)<<endl;
};

main(){
	int r;
	input(r);
	display(r);
	return 0;
};

