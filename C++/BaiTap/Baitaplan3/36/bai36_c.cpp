#include "bai36_c.h" // class's header file

void bai36_c::BMI(float weight,float height)
{
	float BMI=weight/(height*height);
	if(BMI<18.5) cout<<"Thieu can"<<endl;
	else if(BMI>=18.5&&BMI<25) cout<<"Trung binh"<<endl;
	else if(BMI>=25&&BMI<30) cout<<"Thua can"<<endl;
	else cout<<"Beo Phi"<<endl;
}

