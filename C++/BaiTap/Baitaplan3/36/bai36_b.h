#ifndef BAI36_B_H
#define BAI36_B_H

#include<iostream>
using namespace std;
// Y b bai 36
// Bui DUc Thang
class bai36_b
{
	// private section
	public:
		void setR(int x)
		{
			r=x;
		}
		void Nhap()
		{
			int x;
			cout<<"Nhap ban kinh:";
			cin>>x;
			setR(x);
		}
		int DuongKinh(int);
		float ChuVi(int);
		float DienTich(int);
		void Xuat();
		
	private:
		int r;//ban kinh
		
};

#endif // BAI36_B_H

