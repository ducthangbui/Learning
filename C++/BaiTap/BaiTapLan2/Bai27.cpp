#include<iostream>
#include<fstream>
using namespace std;
void File()
{
	ofstream dathuc("dathuc.dat",ios::out);
	ofstream kqdathuc("kqdathuc.dat",ios::out);
	int dathuc1[100]={0}, dathuc2[100]={0},thuong1[100]={1},thuong2[100]={1}, bac1, bac2;
	cout<<"Nhap bac cua da thuc thu 1:";
	cin>>bac1;
	cout<<"Nhap bac cua da thuc thu 2:";
	cin>>bac2;
	cout<< endl << "Nhap he so cua da thuc thu 1:" <<endl;
	dathuc << "Da thuc thu 1:"; 
	for(int i=0;i<bac1;i++)
	{
		cout<<"Nhap he so cua bac "<< i << " :";
		cin>>dathuc1[i];
		thuong1[i]=dathuc1[i];
		dathuc<<dathuc1[i]; 
	}
	cout<< endl << "Nhap he so cua da thuc thu 2:" <<endl;
	dathuc << endl <<"Da thuc thu 2:";
	for(int i=0;i<bac2;i++)
	{
		cout<<"Nhap he so cua bac "<< i << " :";
		cin>>dathuc2[i];
		thuong2[i]=dathuc2[i];
		dathuc<<dathuc2[i]; 
	}
	//Tong/////////////////////////////
	kqdathuc<<"Tong:";
	if(bac1>bac2)
	{
		for(int i=0;i<bac1;i++)
		{
			int tong=0;
			tong=dathuc1[i]+dathuc2[i];
			kqdathuc<<tong<<"\t";
		}
	}
	else
	{
		for(int i=0;i<bac2;i++)
		{
			int tong=0;
			tong=dathuc2[i]+dathuc1[i];
			kqdathuc<<tong<<"\t";
		}
	}
	///Hieu///////////////////////
	kqdathuc<<"Hieu:";
	if(bac1>bac2)
	{
		for(int i=0;i<bac1;i++)
		{
			int hieu=0;
			hieu=dathuc1[i]-dathuc2[i];
			kqdathuc<<hieu<<"\t";
		}
	}
	else
	{
		for(int i=0;i<bac2;i++)
		{
			int hieu=0;
			hieu=dathuc1[i]-dathuc2[i];
			kqdathuc<<hieu<<"\t";
		}
	}
	///////Tich///////////////////////////
	kqdathuc<<"Tich:";
	if(bac1>bac2)
	{
		for(int i=0;i<bac1;i++)
		{
			int tich=1;
			tich=dathuc1[i]*dathuc2[i];
			kqdathuc<<tich<<"\t";
		}
	}
	else
	{
		for(int i=0;i<bac2;i++)
		{
			int tich=1;
			tich=dathuc1[i]*dathuc2[i];
			kqdathuc<<tich<<"\t";
		}
	}
	///////Thuong///////////
	kqdathuc<<"Thuong:";
	if(bac1>bac2)
	{
		for(int i=0;i<bac1;i++)
		{
			int thuong=1;
			thuong=thuong1[i]/thuong2[i];
			kqdathuc<<thuong<<"\t";
		}
	}
	else
	{
		for(int i=0;i<bac2;i++)
		{
			int thuong=1;
			thuong=thuong1[i]/thuong2[i];
			kqdathuc<<thuong<<"\t";
		}
	}
}
main()
{
	File();
}
