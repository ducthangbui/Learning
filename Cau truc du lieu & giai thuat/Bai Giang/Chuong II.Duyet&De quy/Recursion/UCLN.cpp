#include <iostream>

using namespace std;

int UCLN(int a,int b)
{
	if(a==b) return a;
	else 
	{
		if(a>b) return UCLN(a-b,b);
		else return UCLN(a,b-a);
	}
}
main()
{
	int a,b;
	cout<<"Nhap a,b:";
	cin>>a>>b;
	cout<<"UCLN("<<a<<","<<b<<"):"<<UCLN(a,b);
}
