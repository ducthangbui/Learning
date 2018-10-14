#include<iostream>
using namespace std;
void input(int &a, int &b, int &c){
	cin>>a>>b>>c;
}
int sum(int a, int b, int c){
	return a+b+c;
}
int multiply(int a, int b, int c){
	return a*b*c;
}
float average(int a, int b, int c){
	return float(a+b+c)/3;
}
int min(int a, int b, int c){
	int tmp=(a<b?a:b);
	return (tmp<c?tmp:c);
}
int max(int a, int b, int c){
	int tmp=(a>b?a:b);
	return (tmp>c?tmp:c);
}

void display(int a, int b, int c){
	cout<<"-------------------"<<endl;
	cout<<"Nhap vao 3 so nguyen: "; input(a,b,c);
	cout<<"Tong la "<<sum(a,b,c)<<endl;
	cout<<"Trung binh la "<<average(a,b,c)<<endl;
	cout<<"Tich la "<<multiply(a,b,c)<<endl;
	cout<<"Nho nhat la "<<min(a,b,c)<<endl;
	cout<<"Lon nhat la "<<max(a,b,c)<<endl;
	cout<<"-------------------"<<endl;
}
main(){
	int a, b, c;
	display(a,b,c);
	return 0;
}

