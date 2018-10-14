#include<iostream>
using namespace std;

int x[100];//mang nhi phan 0 1
int khoiLuong[100],giaTri[100];
int n;//so luong tui
int khoiLuongToiDa;
int maxi=0;
int ketQua[100];

void Nhap()
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap khoi luong cua tui thu "<<i<<":";
		cin>>khoiLuong[i];
		cout<<"Nhap gia tri cua tui thu "<<i<<":";
		cin>>giaTri[i];
	}
}

void KetQua()
{
	for(int i=1;i<=n;i++)
	cout<<ketQua[i]<<" ";
}

void Update()
{
	int tongKhoiLuong=0, tongGiaTri=0;
	for(int i=1;i<=n;i++)
	{
		tongKhoiLuong+=khoiLuong[i]*x[i];
		tongGiaTri+=giaTri[i]*x[i];
	}
	if(tongKhoiLuong>khoiLuongToiDa) return;
	if(tongGiaTri>maxi)
	{
		maxi=tongGiaTri;
		for(int i=1;i<=n;i++)
		ketQua[i]=x[i];
	}
}

void BackTrack(int i)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) Update();
		else BackTrack(i+1);
	}
}

main()
{
	cout<<"Nhap so luong tui n:";
	cin>>n;
	cout<<"Nhap khoi luong toi da:";
	cin>>khoiLuongToiDa;
	Nhap();
	BackTrack(1);
	KetQua();
}
