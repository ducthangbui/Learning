#ifndef NGUOI_H
#define NGUOI_H
#include <string>

class Nguoi
{
	public:
		Nguoi();
		Nguoi(char* name, char *num, char *email); //Ham tao
		~Nguoi();
	private:

	protected:
		char HoTen[25];
		char Sdt[12];
		char Email[30];
};

#endif
