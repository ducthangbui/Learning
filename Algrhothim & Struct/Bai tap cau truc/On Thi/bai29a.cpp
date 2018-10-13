#include <iostream>

using namespace std;

void Nhap(int a[],int &n)
{
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu a["<<i<<"]:";
		cin>>a[i];
	}
}

void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

int TimKiemTuyenTinh(int a[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	if(x == a[i]) return i;
					return -1;
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<"Mang vua nhap la:"<<endl;
	Xuat(a,n);
	int x;
	cout<<endl<<"Nhap so can tim:";
	cin>>x;
	if(TimKiemTuyenTinh(a,n,x) != -1) cout<<"TIm thay "<<x<<" tai vi tri "<<TimKiemTuyenTinh(a,n,x);
}
