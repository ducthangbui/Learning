#ifndef LOAILAISUAT_H
#define LOAILAISUAT_H
#include <string>

class LoaiLaiSuat
{
	friend class QuanLy;
	public:
		LoaiLaiSuat();
		LoaiLaiSuat(char* type, float ls, char* mota="Khong co mo ta");
		~LoaiLaiSuat();
		char* GetLoaiLS(); // returns the value of LoaiLS
	private:
		char LoaiLS[30];
		float Laisuat;
		char Mota[50];
	protected:
};

#endif
