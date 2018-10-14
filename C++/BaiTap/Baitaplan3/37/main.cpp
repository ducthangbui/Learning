#include <iostream>
#include"rational.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Rational p1,p2,result ;
	p1.Nhap();
	p2.Nhap();
	cout<<"Phan so vua nhap la:";
	p1.Xuat();
	cout << "\t";
	p2.Xuat();
	cout<<endl<<" Tong 2 phan so vua nhap la:";
	result.Cong(p1,p2);
	result.RutGon();
	result.Xuat();
	cout << endl << "Hieu 2 phan so vua nhap la:";
	result.Tru(p1,p2);
	result.RutGon();
	result.Xuat();
	return 0;
}
