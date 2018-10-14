#include "bai36e.h" // class's header file
#include <iostream>
#include <stack>
using namespace std;

stack <int> a;
void Bai36e::CoSo(){
	
	char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap n=";cin>>n;
	do
	{
		cout<<"Nhap (1<b<= 36) b=";cin>>b;
	}
	while(b<0||b>36);
	while(n!=0)
	{
		a.push(n%b);
		n/=b;
	}
	while(!a.empty())
	{
		cout<<x[a.top()];
		a.pop();
	}
}


