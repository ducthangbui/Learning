#include "nguoi.h"

Nguoi::Nguoi()
{
	strcpy(HoTen,"null");
	strcpy(Sdt,"null");
	strcpy(Email,"null");
}

Nguoi::Nguoi(char *name, char *num, char *email) //Ham tao
{
	strcpy(HoTen,name);
	strcpy(Sdt,num);
	strcpy(Email,email);
}

Nguoi::~Nguoi()
{
}
