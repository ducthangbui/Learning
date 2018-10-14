#include "bandoc.h" // class's header file

// class constructor
BanDoc::BanDoc()
{
	// insert your code here
}
int BanDoc::ma = 10000;
void BanDoc::Nhap()
{
	cin.ignore();
	Nguoi::Nhap();
	maBanDoc = ma++;
	do{
		cout<<endl<<"Nhap loai ban doc:"<<endl
			<<"1.Sinh Vien"<<endl
			<<"2.Hoc vien Cao hoc"<<endl
			<<"3.Giao Vien"<<endl;
		cin>>loaiBanDoc;
	}while(loaiBanDoc < 1 || loaiBanDoc >3);
}

void BanDoc::Xuat()
{
	cout<<"Ma Ban Doc:"<<maBanDoc<<endl;
	Nguoi::Xuat();
	cout<<"Loai Ban doc:";
	if(loaiBanDoc == 1) cout<<"Sinh Vien"<<endl;
	else if(loaiBanDoc == 2) cout<<"Hoc vien Cao hoc"<<endl;
	else if(loaiBanDoc == 3) cout<<"Giao Vien"<<endl;
	
}
