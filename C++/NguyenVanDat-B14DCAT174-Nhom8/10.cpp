#include<iostream>
#include<string>
//#include<iomanip>
#include<windows.h>
#define MAX 100
using namespace std;
void input(unsigned int &n, unsigned int &b){
	cout<<"Nhap 1 so tu nhien: ";
	cin>>n;
	cout<<"Nhap he co so: ";
	cin>>b;
	while(b>36||b<1){
		cout<<"Nhap lai he co so: ";
		cin>>b;
	}
}

string convertto(int n, int b){
	string a="";
	while(n!=0){
		int c=n%b;
		if (c<10) a.insert(a.begin(),c+'0');
		else a.insert(a.begin(),c-10+'A');
		n/=b;
	}
	return a;
}

void display(){
	int chon=1;
	unsigned int n, b;
	char *s;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(n,b);
		cout<<"Chuyen sang he co so "<<b<<": "<<convertto(n,b)<<endl;
		//cout<<"Cach 2: "<<setbase(b)<<n<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
