#include "E:\lap trinh\c++\function.cpp"
main()
{
	int n,OK,x[MAX];
	Init_NB_(x,n,OK);
	while(OK)
	{
		Xuat(x,n);
		next_bit(x,n,OK);
	}
}