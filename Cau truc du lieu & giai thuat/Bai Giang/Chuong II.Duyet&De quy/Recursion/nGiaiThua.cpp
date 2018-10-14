/*Tin n!*/
#include <iostream>

using namespace std;

int GiaiThua(int n)
{
	if( n==0 || n==1) return 1;
	else
		return (n*GiaiThua(n-1));
}
int main()
{
	int n;
	cout<<"Nhap n:";
	cin>>n;
	cout<<n<<"!="<<GiaiThua(n);
}
