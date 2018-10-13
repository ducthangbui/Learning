#include "E:\lap trinh\c++\function.cpp"
int x[MAX],n,OK,k,m;
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
main()
{
	Init_NB_(x,n,OK);
	cout<<"Nhap K= ";cin>>k;
	cout<<"Nhap M= ";cin>>m;
	while(OK)
	{
		if(test()) Xuat(x,n);
		next_bit(x,n,OK);
	}
	
}
