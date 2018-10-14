#include "time.h" // class's header file
#include<iostream>
using namespace std;
// class constructor
Time::Time(int g,int p,int s)
{
	// insert your code here
	gio=g;
	phut=p;
	giay=s;
}
void Time::Nhap()
{
	cout<<"Nhap gio:";
	cin>>gio;
	cout<<"Nhap phut:";
	cin>>phut;
	cout<<"Nhap giay:";
	cin>>giay;
}
void Time::Xuat()
{
	if(gio<12)
	cout<< gio <<":" << phut << ":" <<giay <<" AM"<<endl;
	else 
	cout<<  gio <<":" << phut << ":" <<giay <<" PM"<<endl;
}
bool Time::Gio()
{
	if(gio>=13) return true;
			return false;
}
bool Time::Phut()
{
	if(phut>=60) return true;
			return false;
}
void Time::Tick()
{
	giay++;
	if(giay>=60)
	{
		giay=giay-60;
		phut++;
		if(Phut()==true)
		{
			phut=phut-60;
			gio++;
			if(Gio()==true){
				gio=gio-12;
			}
		}
	}
}


