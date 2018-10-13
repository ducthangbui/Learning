#include "D:\lap trinh\c++\function.cpp"
int x[MAX],n,k;
void Init()
{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap k= ";cin>>k;
	x[0]=0;
}
void BackT_COM(int i=1)
{
	for(int j=x[i-1]+1;j<=n-k+i;j++)
	{
		x[i]=j;
		if(i==k) Xuat(x,k);
		else BackT_COM(i+1);
	}
}
main()
{
	Init();
	BackT_COM();
}