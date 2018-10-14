// Tao file va ghi du lieu
#include <iostream>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;

#include <fstream>

using std::ofstream;

#include <cstdlib>  // de dung exit

int main()
{
    // mo file de ghi
    ofstream outClientFile( "clients.txt", ios::out );
    
    // thoat khoi chuong trinh neu khong mo duoc
    if ( !outClientFile ) {
        cerr << "Khong mo duoc file" << endl;
        exit( 1 );//return 1;
    } // cua if
    
    cout << "Nhap so tai khoan, ten, so tien." << endl
    << "Nhan enter de ket thuc.\n? ";
    
    int account;
    char name[ 30 ];
    double balance;
    // doc so tai khoan, ten, so tien va ghi vao file
    while ( cin >> account >> name >> balance ) {
        outClientFile << account << ' ' << name << ' ' << balance
        << endl;
        cout << "? ";
    } // cua while
    
    return 0;
    
} // cua main
