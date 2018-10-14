#include <iostream>
#include<stdlib.h>
#include<ctime>
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

void RandomArr(int a[],int n)
{
	srand((int)(time (0)));
	for(int i=0;i<n;i++)
	a[i]=rand()%n;
}

void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

int fib[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,98,1597,2584,4181,6765};
int FiboSearch(int a[],int n,int x)//x la gia tri can tim
{
	//B1:Tim vi tri k la vi tri cuoi cung de fib[k] > n
	int inf=0,pos,k;
	if(n != -1){
		k=0;
		while(fib[k] < n) k++;//xac dinh vi tri so Fibo nho hon n
	}
	else k=-1;//k=-1 thi khong phai lam gi nua
	//B2: Tim vi tri cua x trong a dua vao buoc nhay cua Fibo
	while(k>0)//lap den khi k>0
	{
		pos=inf+fib[--k];//cong thuc tinh pos
		if((pos >= n) || (x < a[pos]));//khong phai lam gi ca
		else if(x > a[pos])//neu x lon hon a[pos]
		{
			inf=pos+1;//tinh lai inf
			k++;//giam k di 1 don vi
		}
		else return pos;//day la vi tri can tim 
	}
	return -1;//khong tim thay thi tra ve gia tri -1
}

main()
{
	int a[100],n;
//	Nhap(a,n);
	cout<<"Nhap n:";
	cin>>n;
	RandomArr(a,n);
	cout<<"Day vua nhap la:";
	Xuat(a,n);
	int x;
	cout<<endl<<"Nhap gia tri can tim:";
	cin>>x;
	if(FiboSearch(a,n,x) != -1) cout<<endl<<"Tim thay "<<x<<" tai vi tri "<<FiboSearch(a,n,x);
}
