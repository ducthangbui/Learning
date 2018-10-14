/*Tim tong cua n so tu nhien bang de quy*/
#include <iostream>

using namespace std;

int Tong(int n)
{
	if(n==1) return 1;
	else
		return (n+Tong(n-1));
}
main()
{
	int n;
	cout<<"Nhap n:";
	cin>>n;
	cout<<"Tong:"<<Tong(n);
}
