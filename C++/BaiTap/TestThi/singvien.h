#ifndef SINGVIEN_H
#define SINGVIEN_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <iosmanip>
#include <nguoi.h>
using namespace std;

/*
 * No description
 */
class SingVien:public Nguoi
{
	// private section
	public:
		// class constructor
		SingVien();
		friend istream & operator >> (istream &is,SingVien &sv)
		{
			Nguoi *a = reinterpret_cast <Nguoi*>  (&sv);
			is>> *a;
			cout<<"Nhap lop:";
			is.getline(sv.lop,30);
			sv.ma = ID++;
			return is;
		}
		friend ostream & operator << (ostream &os,SingVien sv)
		{
			Nguoi * a =reinterpret_cast <Nguoi*> (&sv);
			os<<left<<setw(7)<<sv.ma;
			os<<*a<<setw(10)<<sv.lop <<endl;
			return os;
		}
		// class destructor
		~SingVien();
	protected:
		static int ID;
		int ma;
		char lop[30];
};

#endif // SINGVIEN_H

