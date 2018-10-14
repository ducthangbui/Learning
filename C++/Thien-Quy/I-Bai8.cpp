#include<iostream>
#include<cmath>
using namespace std;
int ThuanNghich(int n)
{
	int tmp;
	while(n!=0)
	{
		tmp=tmp*10+n%10;
		n=n/10;
	}
	if(tmp==n) return 1;
				return 0;
}
int TongChuSo(int n)
{
	int tong=0;
	while(n!=0)
	{
		tong=tong+n%10;
		n=n/10;
	}
	return tong;
}
void Program(int chuso,int s)
{
	for(int i=pow(i,chuso-1);i<=pow(i,chuso)-1;i++)
	if(ThuanNghich(i)==1&&TongChuSo(i)==s) cout<<i<<"\t";
}
main()
{
		int chuso,s;
		cout<<"Nhap chu so:";
		cin>>chuso;
		cout<<"nhap tong:";
		cin>>s;
		Program(chuso,s);
}
