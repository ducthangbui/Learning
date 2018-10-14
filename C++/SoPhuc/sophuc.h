#ifndef SOPHUC_H
#define SOPHUC_H

/*
 * No description
 */
class sophuc
{
	// private section
	public:
		// class constructor
		sophuc(int x=1,int y=1);
		void setThuc(int x);
		void setAo(int y);
		int getThuc();
		int getAo();
		void Input();
		void Tong(sophuc,sophuc);
		void Display();
	private:
		int thuc;
		int ao;
};

#endif // SOPHUC_H

