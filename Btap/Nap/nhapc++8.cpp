#include<iostream>
using namespace std;
main()
{
	int m;
	float n,BMI;
	cout<<"chieu cao la:";
	cin>>n;
	cout<<"can nang la:";
	cin>>m;
        BMI=m/n*n;
    if(BMI<18.5)  
	             cout<<"thieu can ";
	             else
    if(BMI>=18.5&&BMI<=24.9)
	             cout<<"trung binh";
	             else
    if(BMI>=25&&BMI<=29.9)  
	             cout<<"thua can";
				 else 
    if(BMI>=30) cout<<"beo phi";
}
