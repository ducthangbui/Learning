#include <iostream>

using namespace std;

void Nhap(int a[],int &n)
{
	cout<<"Nhap phan tu cua mang:";
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

void Merge(int a[],int l,int m,int r)
{
	int i,j,k,n1=m-l+1,n2=r-m;
	int left[n1],right[n2];//Tao lap 2 mang phu
	//Coppy du lieu vao left[n1] va right[n2]
	for(i=0;i<n1;i++)
		left[i]=a[l+i];
	for(j=0;j<n2;j++)
	right[j]=a[m+j+1];
	//hop nhat cac mang phu va tra lai vao mang a[]
	i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i] <= right[j]){
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=left[i];
		i++; k++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		j++; k++;
	}
}

void MergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r-1)/2;//Chia mang a[] thanh 2 nua
		MergeSort(a,l,m);//tri nua thu 1
		MergeSort(a,m+1,r);//tri nua thu 2
		Merge(a,l,m,r);//hop nhat thanh 2 nua sap xep
	}
}

main()
{
	int a[100],n;
	int l,r;
	Nhap(a,n);
	cout<<"Mang vua nhap la:";
	Xuat(a,n);
/*	cout<<endl<<"Nhap can tren:";
	cin>>r;
	cout<<endl<<"Nhap can duoi:";
	cin>>l;*/
	MergeSort(a,0,n);
	cout<<endl<<"Mang da sap xep la:";
	Xuat(a,n);
}
