#include "E:\lap trinh\c++\function.cpp"
int x[MAX],n,OK,p,q;
bool test()
{
	int d1=0,s1=0,d0=0,s0=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1) {d1++;d0=0;}
		else {d1=0;d0++;}
		if(d0>=q) s0++;
		if(d1>=p) s1++;
	}
	if(s0==1&&s1==1) return true;
	return 0;
}
main()
{
	Init_NB_(x,n,OK);
	cout<<"Nhap P= ";cin>>p;
	cout<<"Nhap Q= ";cin>>q;
	while(OK)
	{
		if(test()) Xuat(x,n);
		next_bit(x,n,OK);
	}
}
