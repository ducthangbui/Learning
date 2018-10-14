#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
ofstream xuat("sinhvien.txt",ios::out);
struct SinhVien{
	string ten;
	float diem;
	string gioitinh;
};
void Nhap(SinhVien a[],int &n)
{
	cout <<" Nhap so sinh vien:";
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cout <<"Nhap ten:";
			fflush(stdin);
			getline(cin,a[i].ten);
			cout <<"Nhap gioi tinh:";
			cin>>a[i].gioitinh;
			cout<< "Nhap diem:";
			cin>>a[i].diem;
		}
}
void Xuat(SinhVien a[],int n)
{
	
	for(int i=0; i<n;i++)
	{
		xuat<<"Ten:" << a[i].ten <<endl 
			<<"Gioi tinh:" << a[i].gioitinh << endl
			<< "Diem:" << a[i].diem <<endl;
	}
}
void Them(SinhVien a[], SinhVien &them, int &n, int &vitri)
{
	cout << " Nhap vao vi tri can them:";
	cin>>vitri;
	fflush(stdin);
	cout<<"Nhap thong tin sinh vien can them:" <<endl;
	cout<<"Nhap ten sinh vien them:";
	getline(cin,them.ten);
	cout<<"Nhap gioi tinh sinh vien them:";
	cin>>them.gioitinh;
	cout<<"Nhap diem sinh vien them:";
	cin>>them.diem;
	for(int i=n; i>vitri; i--)
		a[i]=a[i-1];
		n++;
	a[vitri]=them;
}
void Xoa(SinhVien a[],int &n, int &vitri)
{
	cout<<"Nhap vi tri can xoa:";
	cin>>vitri;
	for(int i=vitri;i<n;i++)
	a[i]=a[i+1];
	n--;
}
void Swap(SinhVien &a,SinhVien &b)
{
	SinhVien tmp=a;
	a=b;
	b=tmp;
}
void SxGiam(SinhVien a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i].diem < a[j].diem) Swap(a[i],a[j]);
}
void Sua(SinhVien a[],int n, SinhVien &sua)
{
	fflush(stdin);
	cout << "Nhap ten sinh vien can sua:";
	getline(cin,sua.ten);
	cout<<"Nhap diem moi:";
	cin>>sua.diem;
	for(int i=0;i<n;i++)
	if(sua.ten==a[i].ten) a[i].diem=sua.diem;
}
void HienGioiTinh(SinhVien a[],int n,string &gioitinh)
{
	fflush(stdin);
	cout<<"Nhap gioi tinh can hien thi:";
	cin>>gioitinh;
	for(int i=0; i<n; i++)
	if(a[i].gioitinh==gioitinh) {
		xuat<< endl <<"Ho ten:" <<a[i].ten
		 	<< endl << "Gioi tinh:" << a[i].gioitinh
		 	<<endl <<"Diem:" <<a[i].diem;

	}
}
main()
{
	SinhVien a[100],b,sua;
	int n,vitri;
	string gioitinh;
	Nhap(a,n);
	xuat<<"Danh sach sinh vien vua nhap la:" << endl;
	Xuat(a,n);
	Them(a,b,n,vitri);
	xuat<<"Danh sach sinh vien sau khi them la:" << endl;
	Xuat(a,n);
	xuat<<"Danh sach sinh vien sau khi xoa la:" << endl;
	Xoa(a,n,vitri);
	Xuat(a,n);
	xuat<<"Danh sach sinh vien sap xep theo diem giam dan la:" << endl;
	SxGiam(a,n);
	Xuat(a,n);
	xuat <<"Danh sach sinh vien sau khi sua la:" << endl;
	Sua(a,n,sua);
	Xuat(a,n);
	xuat <<endl <<"Danh sach sinh vien hien thi theo gioi tinh la:" << endl;
	HienGioiTinh(a,n,gioitinh);
}

