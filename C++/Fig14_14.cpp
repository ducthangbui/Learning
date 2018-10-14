// Fig. 14.14: fig14_14.cpp
// Doc file ngau nhien
#include <iostream>

using std::cout;
using std::endl;
using std::ios;
using std::cerr;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <iomanip>

using std::setprecision;
using std::setw;

#include <fstream>

using std::ifstream;
using std::ostream;

#include <cstdlib>
struct ClientData{
    int accountNumber;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};
void outputLine( ostream&, const ClientData & );

int main()
{
    ifstream inCredit( "credit.txt", ios::in );
    
    // thoat neu ifstream khong the mo file
    if ( !inCredit ) {
        cerr << "Khong mo duoc file." << endl;
        exit( 1 );
        
    } // cua if
    
    cout << left << setw( 10 ) << "So Tai khoan" << setw( 16 )
    << "Ho" << setw( 11 ) << "Ten" << left
    << setw( 10 ) << right << "Tai khoan" << endl;
    
    ClientData client; // tao ban ghi
    
    // doc ban ghi dau tien tu file
    inCredit.read( reinterpret_cast< char * >( &client ),
                  sizeof( ClientData ) );
    
    // doc tat ca cac ban ghi con lai tu file
    while ( inCredit && !inCredit.eof() ) {
        
        // hien thi ban ghi
        if ( client.accountNumber != 0 )
            outputLine( cout, client );
        
        // doc ban ghi tiep
        inCredit.read( reinterpret_cast< char * >( &client ),
                      sizeof( ClientData ) );
        100*sizeof(ClientData)
        
    } // cua while
    
    return 0;
    
} // cua main

// hien thi 1 ban ghi
void outputLine( ostream &output, const ClientData &record )
{
    output << left << setw( 10 ) << record.accountNumber
    << setw( 16 ) << record.lastName
    << setw( 11 ) << record.firstName
    << setw( 10 ) << setprecision( 2 ) << right << fixed
    << showpoint << record.balance << endl;
    
} // cua outputLine

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
