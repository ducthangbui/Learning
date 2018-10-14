// doc file theo thu tu va in ra man hinh
#include <iostream>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ifstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib> // de dung cho exit

void outputLine( int, const char * const, double );

int main()
{
    // mo file
    ifstream inClientFile( "clients.txt", ios::in );
    
    // thoat khoi chuong trinh neu khong the mo file
    if ( !inClientFile ) {
        cerr << "Khong mo duoc file" << endl;
        exit( 1 );
        
    } // cua if
    
    int account;
    char name[ 30 ];
    double balance;
    
    cout << left << setw( 10 ) << "Tai khoan" << setw( 13 )
    << "Ten" << "So tien" << endl << fixed << showpoint;
    
    // hien thi tung ban ghi trong file
    while ( inClientFile >> account >> name >> balance )
        outputLine( account, name, balance );
    
    return 0;
    
}

// display single record from file
void outputLine( int account, const char * const name,
                double balance )
{
    cout << left << setw( 10 ) << account << setw( 13 ) << name
    << setw( 7 ) << setprecision( 2 ) << right << balance
    << endl;
    
}
