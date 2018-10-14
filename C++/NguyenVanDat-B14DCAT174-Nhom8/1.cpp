#include<iostream>
using namespace std;
void input(float &a,float &b){
	cout<<"a= ";
	cin>>a;
	cout<<"b= ";
	cin>>b;
}
void sum(float a, float b){
	cout<<"a+b= "<<a+b<<endl;
}
void multiply(float a,float b){
	cout<<"a*b= "<<a*b<<endl;
}
void div(float a,float b){
	cout<<"a/b= "<<int(a/b)<<endl;
}
void mod(float a,float b){
	cout<<"a%b= "<<(int)a%(int)b<<endl;
}
main(){
	float a,b;
	input(a,b);
	sum(a,b);
	multiply(a,b);
	div(a,b);
	mod(a,b);
	return 0;
}

