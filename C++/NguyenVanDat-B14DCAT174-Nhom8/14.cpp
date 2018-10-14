#include<iostream>
#include<windows.h>
using namespace std;
void input(double &c){
	cout<<"Nhap vao c (rat nho) >0: ";
	cin>>c;
	while (c<0){
		cout<<"Nhap lai: ";
		cin>>c;
	}
}

double calPi(double c){
	int n=0, a=1;
	double pi=0, s=0;
	do{
		s=double(1)/(2*n+1);
		pi+=a*s;
		a*=-1;
		n++;
	}while (s>c);
	pi*=4;
	return pi;
}

void display(){
	double c;
	input(c);
	cout<<"So Pi = "<<calPi(c);
}

int main(){
	display();
	return 0;
}
