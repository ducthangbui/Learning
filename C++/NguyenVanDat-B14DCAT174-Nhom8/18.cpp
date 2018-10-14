#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
void input(string &s){
	cout<<"Nhap 1 xau ky tu: ";
	getline(cin,s);
}
void findmaxword(string s, string &word, int &max, int &vt){
	int n=s.length(), count=0;
	max=0, vt=-1;
	word="";
	for (int i=0; i<n; i++){
		if (s[i]!=' ') count++;
		else{
			count=0;
		}
		if (count > max){
				max=count;
				vt=i;
			}
	}
	for (int i=vt-max+1; i<=vt; i++) word+=s[i];
}

void display(){
	int chon=1, max, vt;
	string s, w;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(s);
		findmaxword(s,w,max,vt);
		cout<<"Tu dai nhat trong xau la: "<<w<<endl;
		cout<<"Vi tri xuat hien: "<<vt-max+1<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
		cin.clear();
		cin.ignore();
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}
