#include "D:\lap trinh\c++\function.cpp"
void Xuly()
{
	mo_fDoc("data_O.txt");
	mo_fGhi("data6.in");
	char a[100];
	while(fi)
	{
		fi.getline(a,1000);
		if(!fi) break;
		for(int i=0;i<strlen(a);i++)
			fo<<giaimachan(a[i]);
		fo<<"\n";
		
		
	}
	
	
	
	
	
	dong_FGhi();
	dong_FDoc();
}
main()
{
	Xuly();
}