#include<iostream>
using namespace std;
int TongUoc(int n)
{
	int tong=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0) tong=tong+i;
	}
	return tong;
}
int SoHuuNghi(int a,int b)
{
	while(a!=0)
	{
		int tmp=a%10;
		if(tmp==TongUoc(b)) return 1;
		else return 0;
		a=a/10;
	}
}
main()
{
	int a,b;
	cout<<"Nhap vao so can kiem tra:";
	cin>>a>>b;
	if(SoHuuNghi(a,b)) cout<<"Day la so huu nghi";
}
