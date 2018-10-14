#ifndef BAI36D_H
#define BAI36D_H
#include <iostream>

using namespace std;
/*
 * No description
 */
class Bai36d
{
	// private section
	public:
		int UCLN(int a,int b);
		int BCNN(int a,int b);
		void Nhap(){
			cout<<"Nhap x:";
			cin>>x;
			cout<<"Nhap y:";
			cin>>y;
		}
		void Xuat();
	protected:
		int x,y;
};

#endif // BAI36D_H

