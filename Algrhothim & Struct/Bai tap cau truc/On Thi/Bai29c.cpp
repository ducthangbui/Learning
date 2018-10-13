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

//Tim kiem Noi suy - Interpolation Search
int InterpolationSearch(int a[],int n,int key)//key la gia tri can tim
{
	int low=0, high=n-1,mid;
	while(a[low] <= key && a[high] >= key)
	{
		if(a[high]-a[low] == 0) return (low+high)/2;
		mid=low+((key+a[low])*(high-low))/(a[high]-a[low]);
		if(a[mid] < key) low=mid+1;
		else if(a[mid] > key) high=mid-1;
		else return mid;
	}
	if(a[low] == key) return low;
	return -1;
}

main()
{
	int a[100],n,key;
	Nhap(a,n);
	cout<<"Mang cua nhap la:";
	Xuat(a,n);
	cout<<endl<<"Nhap so can tim:";
	cin>>key;
	if(InterpolationSearch(a,n,key) != -1) cout<<"Tim thay "<<key<<" tai vi tri "<<InterpolationSearch(a,n,key);
	else cout<<"Khong ton tai "<<key<<" trong day vua nhap";
}
