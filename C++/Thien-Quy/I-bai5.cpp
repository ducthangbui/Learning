#include<iostream>
using namespace std;
int TongUoc(int n)
{
	int tong=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0) tong=tong+i;
	}
	return tong;
}
int SoHoanThien(int n)
{
	if(n==TongUoc(n)) return 1;
					return 0;
}
main()
{
	int n;
	cout<<"Nhap vao so can kiem tra:";
	cin>>n;
	if(SoHoanThien(n)) cout<<"So hoan thien!!!"<<endl;
	else cout<<"Khong phai la so hoan thien";
}
