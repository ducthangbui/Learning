#include "bai36_b.h" // class's header file
#define pi 3.14159
using namespace std;
int bai36_b::DuongKinh(int x)
{
	return x+x;
}
float bai36_b::ChuVi(int x)
{
	return 2*pi*x;
}
float bai36_b::DienTich(int x)
{
	return pi*x*x;
}
void bai36_b::Xuat()
{
	int x;
	cout<<"Duong kinh:"<<DuongKinh(x);
	cout<<endl<<"Chu Vi:"<<ChuVi(x);
	cout<<endl<<"Dien Tich:"<<DienTich(x);
}

