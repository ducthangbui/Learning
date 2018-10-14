#include "ps2.h" // class's header file
#include "ps1.h"
#include<iostream>
using namespace std;
PS2::PS2(int x,int y)
{

	tu=x;
	mau=y;
}
PS2 PS2::operator + (PS2 ps)
{
	PS2 tong;
	tong.tu = (ps.tu*this->mau) + (ps.mau*this->tu);
	tong.mau=(ps.mau) * (this->mau);
	return (tong);
}
PS2 PS2::operator - (PS2 p1)
{
	PS2 hieu;
	hieu.tu=0;
	hieu.tu=(p1.mau*this->tu) - (p1.tu*this->mau) ;
	hieu.mau=(p1.mau) * (this->mau);
	return (hieu);
}
PS2 PS2::operator * (PS2 p1)
{
	PS2 tich;
	tich.tu= (p1.tu) * (this->tu);
	tich.mau= (p1.mau) * (this-> mau);
	return tich;
}
PS2 PS2::operator / (PS2 p1)
{
	PS2 thuong;
	thuong.tu=p1.mau*this->tu;
	thuong.mau=p1.tu*this->mau;
	return thuong;
}
PS2 PS2::operator ++ (int)//PS2++
{
	PS2 tang;
	tang.tu=(this->tu + this->mau);
	tang.mau=this->mau;
	return tang;
}
PS2 PS2::operator ++ ()//++PS2
{
	PS2 tang;
	tang.tu=(this->tu + this->mau);
	tang.mau=this->mau;
	return tang;
}

PS2 PS2::operator -- (int)//PS2--
{
	PS2 giam;
	giam.tu=(this->tu - this->mau);
	giam.mau=this->mau;
	return giam;
}
PS2 PS2::operator -- ()//--PS2
{
	PS2 giam;
	giam.tu=(this->tu - this->mau);
	giam.mau=this->mau;
	return giam;
}
bool PS2::operator < (const PS2 &p)
{
	if((this->tu * p.mau) < (p.tu * this->mau)) return true;
	return false;
}
bool PS2::operator <= (const PS2 &p)
{
	if((this->tu * p.mau) < (p.tu * this->mau)) return true;
	return false;
}
bool PS2::operator > (const PS2 &p)
{
	if((this->tu * p.mau) > (p.tu * this->mau)) return true;
	return false;
}
bool PS2::operator >= (const PS2 &p)
{
	if((this->tu * p.mau) >= (p.tu * this->mau)) return true;
	return false;
}
bool PS2::operator == (const PS2 &p)
{
	if((this->tu * p.mau) == (p.tu * this->mau)) return true;
	return false;
}
bool PS2::operator != (const PS2 &p)
{
	if((this->tu * p.mau) != (p.tu * this->mau)) return true;
	return false;
}
