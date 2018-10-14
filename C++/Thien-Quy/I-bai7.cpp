#include<iostream>
#include<cmath>
using namespace std;
int Ngto(int n)
{
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 1;
				return 0;
}
int TachSo(int n)
{
	int tong=0;
	while(n!=0)
	{
		tong=tong+n%10;
		n=n/10;
	}
	return tong;
}
void Ktra(int s,int n)
{
	for(int i=2;i<n;i++)
	if(Ngto(i)==0&&TachSo(i)==s) cout<<i<<"\t";
}
main()
{
	int n,s;
	cout<<"Nhap n:";
	cin>>n;
	cout<<"Nhap tong:";
	cin>>s;
	Ktra(s,n);
}
