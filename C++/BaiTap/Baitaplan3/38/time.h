#ifndef TIME_H
#define TIME_H

/*
 * No description
 */
class Time
{
	// private section
	public:
		// class constructor
		Time(int g=0,int p=0,int s=0);
		void Nhap();
		void Xuat();
		void Tick();
		bool Gio();
		bool Phut();
	private:
		int gio;
		int phut;
		int giay;
};

#endif // TIME_H

