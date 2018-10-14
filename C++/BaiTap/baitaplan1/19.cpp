// 19.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
void Nhap(int a[][100], int &n)
{
	cout << "Nhap vao cap cua ma tran:";
	cin >> n;
	for (int i = 0;i < n;i++)
	for(int j=0;j<n;j++)
	{
		cout << "Nhap vao phan tu thu a[" << i << "]"<<"["<<j<<"]:";
		cin >> a[i][j];
	}
}
void Xuat(int a[][100], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j]<<"	";
			cout << endl;
	}
}
int Max(int a[], int n)
{
	int max = a[0];
	for (int i = 0;i<n;i++)
		if (a[i]>max) max = a[i];
	return max;
}
void Xuat1(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<"	";
}
void Tong(int a[][100], int n)
{
	int b[100] = { 0 }, nb = 0;
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<n;j++)
			b[nb] = b[nb] + a[i][j];
		nb++;
	}
	//printf("\nTong cac hang cua Ma tran la:");
	cout << "\nTong cac hang cua Ma tran la:";
	Xuat1(b, nb);
	for (int i = 0;i<nb;i++)
		if (b[i] == Max(b, nb)) cout<<"\nChi so Hang Max cua ma tran la:"<<i<<endl;
}
void MTHoanVi(int a[][100], int &n)
{
	for (int j = 0;j<n;j++)
	{
		for (int i = 0;i<n;i++)
			cout<<a[i][j];
		cout << endl;
	}
}
float Det(int a[][100], int n)
{
	int det = 1, k, i, j;
	float b;
	for (int i = 0;i<(n - 1);i++)
	{
		if (a[i][i] == 0)
		{
			k = i + 1;
			while ((k<n) && (a[k][i] == 0))
				k++;
			if (k>(n - 1))
			{
				det = 0;
				break;
			}
			else
			{
				det = -det;
				for (j = i;j<n;j++)
				{
					int tmp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = tmp;
				}
			}
		}
		for (k = i + 1;k<n;k++)
		{
			b = -a[k][i] / a[i][i];
			for (j = i;j<n;j++)
				a[k][j] = a[k][j] + b*a[i][j];
		}
	}
	for (i = 0;i<n;i++)
		det = det*a[i][i];
	return det;
}
void MTnghichdao(int a[][100], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << (1 / Det(a, n))*a[i][j]<<"	";
		cout << endl;
	}
			
}
int main()
{
	int n, a[100][100];
	Nhap(a, n);
	cout << "Ma tran vua nhap la:" << endl;
	Xuat(a, n);
	cout << endl;
	Tong(a, n);
	MTHoanVi(a, n);
	cout << endl;
	cout << "\nDet=" << Det(a, n) << endl;
	MTnghichdao(a, n);
    return 0;
}


