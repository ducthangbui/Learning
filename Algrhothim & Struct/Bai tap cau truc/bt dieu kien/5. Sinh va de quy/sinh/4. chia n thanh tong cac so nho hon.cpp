#include "E:\lap trinh\c++\function.cpp"
main()
{
	int n,x[MAX],k,OK;
	Init_ND_(x,n,k,OK);
	while(OK)
	{
		Xuat(x,k);
		next_div(x,k,OK);
	}
}
