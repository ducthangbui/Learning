#include <iostream>
#include"ps1.h"
#include"ps2.h"
using namespace std;


int main(int argc, char *argv[]) {
	PS2 p1,p2,tong, hieu, tich, thuong, tang, tang2,giam, giam2 ;
	p1.Nhap();
	p2.Nhap();
	cout<<"Phan so vua nhap la:";
	p1.Xuat();
	cout << "\t";
	p2.Xuat();
	tong=p1+p2;
	cout<<endl<<" Tong 2 phan so vua nhap la:";
	//result.Cong(p1,p2);
	tong.RutGon();
	tong.Xuat();
	hieu=p1-p2;
	cout<<endl<<" Hieu 2 phan so vua nhap la:";
	hieu.RutGon();
	hieu.Xuat();
	tich=p1*p2;
	cout<<endl<<" Tich 2 phan so vua nhap la:";
	tich.RutGon();
	tich.Xuat();
	thuong=p1/p2;
	cout<<endl<<" Thuong 2 phan so vua nhap la:";
	thuong.RutGon();
	thuong.Xuat();
	cout<< endl <<" p1++ = ";//su dung toan tu ++ sau khi da nang hoa(nap chong - overloading)
	tang=p1++;
	tang.RutGon();
	tang.Xuat();
	cout<< endl <<" ++p2 = ";//su dung toan tu ++ sau khi da nang hoa(nap chong - overloading)
	tang2= ++p2;
	tang2.RutGon();
	tang2.Xuat();
	cout<< endl <<" p1-- = ";//su dung toan tu -- sau khi da nang hoa(nap chong - overloading)
	giam=p1--;
	giam.RutGon();
	giam.Xuat();
	cout<< endl <<" --p2 = ";//su dung toan tu -- sau khi da nang hoa(nap chong - overloading)
	giam2=--p2;
	giam2.RutGon();
	giam2.Xuat();
	/*PS2 nhap;
	cin>>nhap;*/
	if(p1 <p2) cout << endl <<"p1< p2";
	else if(p1 > p2) cout<<endl<<p1.Xuat()<<">"<<p2.Xuat();
	cout<<endl;
	PS2 nhap;
	cin>>nhap;
	cout<<nhap;
	return 0;
}
