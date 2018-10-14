#include<iostream>
#include<fstream>
#include <cstdlib>  // de dung exit
#include<iomanip>
#include<string>
using namespace std;
void Ghi()
{
	fstream NhanVien("NhanVien.txt",ios::out);
	 if ( !NhanVien) 
	 {
        cerr << "Khong mo duoc file" << endl;
        exit( 1 );//return 1;
    } // cua if
    int n;
	int dem=0;
    cout<<"Nhap vao so nhan vien:";
    cin>>n;
    fflush(stdin);
    cout << "Nhap ten, tuoi, ma nhan vien, luong." << endl<<"#";
    int age,salary;
    string name,id;

    // doc so tai khoan, ten, so tien va ghi vao file
    while(dem!=n)
	{
		getline(cin,name);
		cin>>age;
		getline(cin,id);
		cin>>salary;
        NhanVien <<name<<" " << age <<" " << id <<" "<<id << endl;
        cout << "# ";
        dem++;
    }
}
void Doc()
{
	// mo file
    fstream NhanVien( "NhanVien.txt", ios::in );
    // thoat khoi chuong trinh neu khong the mo file
    if ( !NhanVien ) 
	{
        cerr << "Khong mo duoc file" << endl;
        exit( 1 );    
    } // cua if
    int age,salary;
    string name,id;
    cout << left <<setw( 13 )<< "Ten" <<setw(10)<<"Tuoi"<<setw(10)<<"Ma NV"<<id <<setw(8)<< "Luong" << endl;
	while(!NhanVien.eof())
	{
		getline(NhanVien,name);
		NhanVien>>age;
		getline(NhanVien,id);
		NhanVien>>salary;
			cout << left << setw( 13 ) << name << setw( 10 ) << age
    	<< setw( 10 ) << id <<setw(8)<<right<< salary
   		<< endl;
	}
}
main()
{
	//Doc();
	Ghi();
}

