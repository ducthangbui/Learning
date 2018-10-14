#include "loailaisuat.h"

LoaiLaiSuat::LoaiLaiSuat()
{
	strcpy(LoaiLS,"null");
	Laisuat=0;
	strcpy(Mota,"null");
}

LoaiLaiSuat::LoaiLaiSuat(char* type, float ls, char* mota)
{
	strcpy(LoaiLS,type);
	Laisuat=ls;
	strcpy(Mota,mota);
}

LoaiLaiSuat::~LoaiLaiSuat()
{
}

// returns the value of LoaiLS
char* LoaiLaiSuat::GetLoaiLS()
{
	return LoaiLS;
}
