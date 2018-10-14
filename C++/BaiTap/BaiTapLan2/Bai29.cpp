#include<iostream>
#include<fstream>
using namespace std;
int DocFile()
{
	int dem=0,socauhoi	;
	string cauhoi,dapanhien,dapanchon,dapandung;
	ifstream fdoc("bcvt.txt",ios::in);
	fdoc >> socauhoi;
	for(int i=0;i<socauhoi;i++)
	{
		getline(fdoc,cauhoi);
		getline(fdoc,cauhoi);
		getline(fdoc,dapanhien);
		cout<<cauhoi<<endl<<dapanhien;
		fdoc>>dapandung;
		cout<<endl << "Nhap dap an:";
		cin>>dapanchon;
		if(dapanchon==dapandung) dem++;
	}
	return dem;
}
main()
{
	int x=DocFile();
	if(x>=5) cout<<"Rat tot !!!";
	else cout<<"Can tim hieu them !!!";
}
