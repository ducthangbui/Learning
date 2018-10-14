#include <iostream>

using namespace std;

int mtChiPhi[100][100];
int mini=10000;//chi phi nho nhat
bool chuaxet[100];
int n;//so thanh pho
int ketQua[100];
int thanhPho[100];

void Nhap()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"Nhap chi phi thanh pho thu ["<<i<<"]["<<j<<"]:";
			cin>>mtChiPhi[i][j];
		}
		thanhPho[i]=i;
		ketQua[i]=0;		
	}
	for(int i=1;i<=n;i++)
	chuaxet[i]=true;
}

void Update()
{
	int tong=0;
	for(int i=1;i<=n;i++)
		tong+=mtChiPhi[thanhPho[i]][thanhPho[i+1]];//Chi phi tu thanh pho i den thanh pho thu i+1
	tong+=mtChiPhi[thanhPho[n]][thanhPho[1]];//quay lai tu thanh pho n ve 1
	if(tong<mini)
	{
		mini=tong;
		for(int i=1;i<=n;i++)
		ketQua[i]=thanhPho[i];
	}
	
}

void BackTrack(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(chuaxet[j])
		{
			thanhPho[i]=j;
			chuaxet[j]=false;
			if(i==n) Update();
			else BackTrack(i+1);
			chuaxet[j]=true;
		}
	}
}

void Xuat()
{
	cout<<endl<<"Gia tien nho nhat:"<<mini;
	for(int i=1;i<=n;i++)
	cout<<endl<<"Hanh trinh:"<<ketQua[i];
}
main()
{
	cout<<"Nhap so thanh pho:";
	cin>>n;
	Nhap();
	BackTrack(1);
	Xuat();
}
