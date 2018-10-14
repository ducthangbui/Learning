#include<iostream>
#include<windows.h>
using namespace std;
void input(unsigned int &n){
	cout<<"Nhap vao n>=0: ";
	cin>>n;
	while (n<0){
		cout<<"Nhap lai: ";
		cin>>n;
	}
}

int fibo(int n){
	if (n==0) return 0;
	int i=3, fn1=1, fn2=1, fn=1;
	while(i<=n){
		fn=fn1+fn2;
		fn1=fn2;
		fn2=fn;
		i++;
	}
	return fn;
}

void display(){
	unsigned int n, chon;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(n);
		cout<<"So fibinacci thu "<<n<<" la: "<<fibo(n)<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
