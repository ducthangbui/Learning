#include "D:\lap trinh\c++\function.cpp"
void Xuly()
{
	mo_fDoc("data.in");
	mo_fGhi("data_O.txt");
	char a[100];
	while(fi)
	{
		fi.getline(a,1000);
		if(!fi) break;
		for(int i=0;i<strlen(a);i++)
			fo<<chanhoa(a[i]);
		fo<<"\n";
		
		
	}
	
	
	
	
	
	dong_FGhi();
	dong_FDoc();
}
main()
{
	Xuly();
}