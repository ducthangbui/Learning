#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>
using namespace std;
/*
 * No description
 */
class Nguoi
{
	// private section
	public:
		Nguoi();
		~Nguoi();
		friend istream & operator >> (istream &is,Nguoi &ng)
		{
			//Nguoi *a= reinterpret_cast <Nguoi> (&sv);
			//is >> *a;
			cout<<"Nhap ho ten:";
			is>>ng.hoten;
			cout<<"Nhap dia chi:";
			is>>ng.diachi;
			cout<<"Nhap sdt:";
			is>>ng.sdt;
			return is;
		}
	protected:
		friend ostream & operator << (ostream &os,Nguoi ng)
		{
			os<<endl<<"Ho ten:"<<ng.hoten<<endl
				<<"Dia chi:"<<ng.diachi<<endl
				<<"SDT:"<<ng.sdt<<endl;
			return os;
		} 
		char hoten[30];
		char diachi[30];
		int sdt;
};

#endif // NGUOI_H

