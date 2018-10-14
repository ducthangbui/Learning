#include <iostream>
#include"time.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Time t;
	t.Nhap();
	cout<<"Gio vua nhap la:";
	t.Xuat();
	cout<< endl << "Gio sau khi tang len 1s la:";
	t.Tick();
	t.Xuat();
	return 0;
}
