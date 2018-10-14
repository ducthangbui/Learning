#ifndef BAI36I_H
#define BAI36I_H

/*
 * No description
 */
class Bai36i
{
	// private section
	public:
		void Nhap(int a[][100], int &n);
		void Xuat(int a[][100], int n);
		int Max(int a[], int n);
		void Xuat1(int a[],int n);
		void Tong(int a[][100], int n);
		void MTHoanVi(int a[][100], int &n);
		float Det(int a[][100], int n);
		void MTnghichdao(int a[][100], int n);
	protected:
		int n, a[100][100];
};

#endif // BAI36I_H

