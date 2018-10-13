#include "D:\lap trinh\c++\function.cpp"
int x[MAX],a[MAX],c[MAX],n,b,kq[MAX],OK,maxi=0;
// c la mang chua gia tri su dung
// a la mang chua trong luong cac do
// b la khoi luong toi da dc mang theo
// kq la mang luu ket qua toi uu
void Init()
{
	mo_fDoc("cai tui.txt");
	fi>>n>>b;
	for(int i=1;i<=n;i++) fi>>c[i];
	for(int i=1;i<=n;i++) {fi>>a[i];kq[i]=x[i]=0;}
	OK=1;
	dong_FDoc();
}
void Update()
{
	int tonga=0,tongc=0;
	for(int i=1;i<=n;i++)
	{
		tongc+=c[i]*x[i];
		tonga+=a[i]*x[i];
	}
	if(tonga>b) return ;
	if(tongc>maxi)
	{
		maxi=tongc;
		for(int i=1;i<=n;i++)
			kq[i]=x[i];
	}
}
main()
{
	Init();
	while(OK)
	{
		Update();
		next_bit(x,n,OK);
	}
	//Xuat(x,n);
	Xuat(kq,n);
}
