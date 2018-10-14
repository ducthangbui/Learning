#include <iostream>
#include"sophuc.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	sophuc p1,p2,kqua;
	p1.Input();
	cout<<"So thuc vua nhap la:";
	p1.Display();
	cout<<endl;
	p2.Input();
	cout<<"So thuc vua nhap la:";
	p2.Display();
	cout<<endl<<"Tong cua 2 so thuc la:";
	kqua.Tong(p1,p2);
	//cout<<endl<<kqua.getAo();
	//kqua.Display();
	return 0;
}
