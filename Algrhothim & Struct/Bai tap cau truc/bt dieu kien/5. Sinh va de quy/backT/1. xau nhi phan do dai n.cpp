#include "D:\lap trinh\c++\function.cpp"
int x[MAX],n;
void Init()
{
	cout<<"Nhap n=";cin>>n;
}
void BackT_BIT(int i=1)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) Xuat(x,n);
		else BackT_BIT(i+1);
	}
}
main()
{
	Init();
	BackT_BIT();
}