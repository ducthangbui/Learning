#include<iostream>
using namespace std;
void BMI(float weight,float height)
{
	float BMI=weight/(height*height);
	if(BMI<18.5) cout<<"Thieu can"<<endl;
	else if(BMI>=18.5&&BMI<25) cout<<"Trung binh"<<endl;
	else if(BMI>=25&&BMI<30) cout<<"Thua can"<<endl;
	else cout<<"Beo Phi"<<endl;
}
main()
{
	float weight,height;
	cout<<"Nhap can nang(kg):";
	cin>>weight;
	cout<<"Nhap chieu cao(m):";
	cin>>height;
	BMI(weight,height);
}
