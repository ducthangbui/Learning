#include "D:\lap trinh\c++\function.cpp"

int demdong()
{
	int dem=-1;
	char a[1000];
	mo_fDoc("demdong.txt");
	while(fi) {fi.getline(a,1000);dem++;}
	dong_FDoc();
	return dem;
}
main()
{
	cout<<demdong();
}