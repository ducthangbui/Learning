#include "D:\lap trinh\c++\function.cpp"
int x[MAX],n,k,m;
void Init()
{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap K= ";cin>>k;
	cout<<"Nhap M= ";cin>>m;
}
bool test()
{
	int dem1=0,soday=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1) dem1++;
		else dem1=0;
		if(dem1>=m) soday++;
	}
	if(soday==k) return true;
	return 0;
}
void BackT_BIT(int i=1)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) 
		{
			if(test()) Xuat(x,n);
		}
		else BackT_BIT(i+1);
	}
}
main()
{
	Init();
	BackT_BIT();
}