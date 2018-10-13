#include "E:\lap trinh\c++\function.cpp"
main()
{
	int x[MAX],n,OK;
	Init_NP_(x,n,OK);
	while(OK)
	{
		Xuat(x,n);
		next_per(x,n,OK);
	}
}
