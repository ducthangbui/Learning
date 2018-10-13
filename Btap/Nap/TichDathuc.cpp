#include<iostream>
using namespace std;
struct Dathuc
{
	int bac;
	float *heso;
};
void Tich(Dathuc dathuc1,Dathuc dathuc2)
{
	cout<<"Nhap vao bac cua da thuc thu 1:";
	cin>>dathuc1.bac;
	cout<<"Nhap vao bac cua da thuc thu 2:";
	cin>>dathuc2.bac;
	float dathuc1.heso= new float[dathuc1.bac];
	dathuc1.heso=0;
	cout<<endl<<"Nhap vao he so cua da thuc thu 1: "<<endl;
	for(int i=0;i<=dathuc1.bac;i++)
	{
		cout<<"Nhap vao he so cua bac "<<i<<":"<<;
		cin>>dathuc1->heso; 
	}
	float dathuc2.heso= new float[dathuc2.bac];
	cout<<endl<<"Nhap vao he so cua da thuc thu 2: "<<endl;
	for(int i=0;i<=dathuc2.bac;i++)
	{
		cout<<"Nhap vao he so cua bac "<<i<<":"<<;
		cin>>dathuc2.heso; 
	}
	//for()
}
main()
{
	Dathuc dathuc1,dathuc2;
	Tich(dathuc1,dathuc2);
}
