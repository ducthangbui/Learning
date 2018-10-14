#ifndef BAI36_C_H
#define BAI36_C_H
#include<iostream>
using namespace std;
/*
 * No description
 */
class bai36_c
{
	// private section
	public:
		void Nhap()
		{
			cout<<"Nhap chieu cao:";
			cin>>weight;
			cout<<"Nhap can nang:";
			cin>>height;
		}
		void BMI(float weight,float height);
		void Xuat(){
			bai36_c::BMI(weight,height);
		}
	private:
		float weight;
		float height;
};

#endif // BAI36_C_H

