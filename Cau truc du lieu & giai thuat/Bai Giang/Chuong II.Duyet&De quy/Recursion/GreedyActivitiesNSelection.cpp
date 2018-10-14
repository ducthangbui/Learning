/*Cho tap gom n hanh dong, moi hanh dong duoc bieu dien nhu
bo doi thoi gian bat dau si va ket thuc la fi(i=1,2,..,n)
Bai toan dat ra la hay lua chon nhieu nhat cac hanh dong co the
thuc hien boi may hoac mot ca nhan khong xay ra tranh chap
Gia su moi hanh dong chi thuc hien don le tai mot thoi diem*/
#include <iostream>

using namespace std;

int n;//so hanh dong
int s[100];//thoi gian bat dau
int f[100];//thoi gian ket thuc
int OPT[100];//cac phuong an
int nOPT=1;//so thanh phan cua OPT

void NhapBatDau()
{

	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap s["<<i<<"]:";
		cin>>s[i];
	}
}

void NhapKetThuc()
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap f["<<i<<"]:";
		cin>>f[i];
	}
}

void GreedyActivitiesNSelection()
{
	int i=1;
	OPT[0]=1;
	for(int j=2;j<=n;j++)
	{
		if(s[j]>=f[i])
		{
			OPT[nOPT]=j;
			i=j;
			nOPT++;
			//n=n/i;			
		}
	}
}

void KetQua()
{
	for(int i=0;i<nOPT;i++)
	cout<<endl<<"OPT: "<<OPT[i];
}

main()
{
	cout<<"Nhap so nguoi n:";
	cin>>n;
	NhapBatDau();
	NhapKetThuc();
	GreedyActivitiesNSelection();
	KetQua();
}
