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

int BinarySearch(int a[],int n,int x)//x la gia tri can tim
{
	int low=0;//can duoi
	int high=n-1;//can tren
	int mid=(low+high)/2;//vi tri giua
	while(low <= high)
	{
		if(x > a[mid])//neu x > phan tu o giua 
			low=mid+1;//thi gan can duoi = mid+1
		else if(x < a[mid])//neu x < phan tu o giua
				high=mid-1;//thi gan can tren = mid -1
		else return mid;//mid chinh la vi tri cua x
		mid=(low+high)/2;//dat lai vi tri giua
	}
	return -1;//neu k tim thay x thi tra ve gia tri -1
}

main()
{
	int a[100],n,x;
	Nhap(a,n);
	cout<<"Day vua nhap la:";
	Xuat(a,n);
	cout<<endl<<"Nhap gia tri can tim:";
	cin>>x;
	if(BinarySearch(a,n,x) != -1) cout<<"Tim thay "<<x<<" tai vi tri "<<BinarySearch(a,n,x);
	else cout<<"Khong tim thay "<<x;
}
