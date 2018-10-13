/*Sequential Search bang de quy*/
#include <iostream>

using namespace std;

void Nhap(int a[],int &n)
{
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]:";
		cin>>a[i];
	}
}

void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

int SequentialSearch(int a[],int n,int x,int i)
{
	if(x == a[i] || i >= n) return i;
	SequentialSearch(a,n,x,i+1);
	return -1;
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<endl<<"Day vua nhap la:";
	Xuat(a,n);
	
	int x;
	cout<<endl<<"Nhap so can tim:";
	cin>>x;
	if(SequentialSearch(a,n,x,0) != -1) cout<<"Tim thay "<<x<<" tai vi tri "
											<<SequentialSearch(a,n,x,0);
	else cout<<"Khong tim thay";
}
