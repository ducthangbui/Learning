#ifndef PS2_H
#define PS2_H
#include"ps1.h"
#include<iostream>
using namespace std;
/*
 * No description
 */
class PS2: public PS1
{
	// private section
	public:
		PS2(int x=1,int y=1);
		PS2 operator + (PS2);
	    PS2 operator - (PS2);
		PS2 operator * (PS2);
		PS2 operator / (PS2);
		PS2 operator ++ (int);
		PS2 operator ++ ();
		PS2 operator -- (int);
		PS2 operator -- ();
		 friend ostream &operator <<(ostream &output, const PS2 &p){
			if(p.maup!=1)
			output << p.tup <<"/"<<p.maup;
			else 	output <<p.tup;
			return output;
		}
   		friend istream &operator >>(istream &input, PS2 &p){
        		cout<<"Nhap tu:";
				input>>p.tup;
				do{
					cout<<"Nhap mau:";
					input>>p.maup;
				}while(p.maup==0);
				return input;
        }
        bool operator < (const PS2 &p);
        bool operator > (const PS2 &p);
        bool operator <= (const PS2 &p);
        bool operator >= (const PS2 &p);
        bool operator == (const PS2 &p);
        bool operator != (const PS2 &p);
	private:
		int tup;
		int maup;
};

#endif // PS2_H

