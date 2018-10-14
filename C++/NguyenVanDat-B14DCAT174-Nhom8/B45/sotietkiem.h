#ifndef SOTIETKIEM_H
#define SOTIETKIEM_H
#include <string>

class SoTietKiem
{
	friend class QuanLy;
	public:
		SoTietKiem();
		SoTietKiem(int id, char* type, double st, int sth);
		~SoTietKiem();
		int GetMaSTK(); // returns the value of MaSTK
		int GetSotiengui();
		void static SetgenMaSTK(int x){
			genMaSTK=x;
		}
	private:
		static int genMaSTK;
		int MaSTK;
		int MaKH;
		char LoaiLS[30];
		int Sothanggui;
		double Sotiengui;
	protected:
};

#endif
