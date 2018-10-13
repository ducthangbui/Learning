/*Tim tong cua n so tu nhien bang de quy*/
#include <iostream>

using namespace std;

int Tong(int a[],int n)
{
	if(--n < 0) return 0;
	return a[n]+Tong(a,n--);
}
main()
{
	int n=3;
	int a[]={1,2,3};
	//cout<<"Nhap n:";
	//cin>>n;
	cout<<"Tong:"<<Tong(a,n);
}
