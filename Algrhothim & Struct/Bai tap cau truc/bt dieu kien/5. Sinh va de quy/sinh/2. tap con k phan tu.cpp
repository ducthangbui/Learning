#include "E:\lap trinh\c++\function.cpp"
main()
{
	int x[MAX],n,OK,k;
	Init_NC_(x,n,k,OK);
	while(OK)
	{
		Xuat(x,k);
		next_com(x,n,k,OK);
	}
}
