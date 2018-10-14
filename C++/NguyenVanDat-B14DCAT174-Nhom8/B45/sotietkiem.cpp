#include "sotietkiem.h"

SoTietKiem::SoTietKiem()
{
	MaSTK=0;
	MaKH=0;
	strcpy(LoaiLS,"null");
	Sotiengui=0;
	Sothanggui=0;
}

SoTietKiem::SoTietKiem(int id, char* type, double st, int sth)
{
	MaSTK=++genMaSTK;
	MaKH=id;
	strcpy(LoaiLS,type);
	Sotiengui=st;
	Sothanggui=sth;
}

SoTietKiem::~SoTietKiem()
{
}

// returns the value of MaSTK
int SoTietKiem::GetMaSTK()
{
	return MaSTK;
}

int SoTietKiem::GetSotiengui(){
	return Sotiengui;
}

int SoTietKiem::genMaSTK=0;
