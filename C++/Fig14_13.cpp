// Fig. 14.13: fig14_13.cpp
// Ghi file ngau nhien
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::ios;

#include <iomanip>

using std::setw;

#include <fstream>

using std::ofstream;

#include <cstdlib>
struct ClientData{
    int accountNumber;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;
};
int main()
{
   int accountNumber;
   char lastName[ 15 ];
   char firstName[ 10 ];
   double balance;

   ofstream outCredit( "credit.txt", ios::binary );

   // thoat neu ofstream khong mo duoc file
   if ( !outCredit ) {
      cerr << "Khong mo duoc file." << endl;
      exit( 1 );

   } // cua if

   cout << "Nhap so tai khoan "
        << "(tu 1 toi 100, 0 de ket thuc)\n? ";

   // yeu cau nguoi dung nhap so tai khoan
   ClientData client;
    cin >> client.accountNumber;
    // nguoi dung nhap thong tin, se duoc ghi vao file
    while ( client.accountNumber > 0 &&
           client.accountNumber <= 100 ) {
        
        // Nguoi dung nhap ho, ten va tai khoan
        cout << "Nhap ho, ten, va tai khoan\n? ";
        cin >> setw( 15 ) >> client.lastName;
        cin >> setw( 10 ) >> client.firstName;
        cin >> client.balance;
        
        
        // chuyen toi vi tri ban ghi cuoi 
        outCredit.seekp( ( client.accountNumber - 1 ) *
                        sizeof( ClientData ) );
        
        // ghi thong tin vao file
        outCredit.write(
                        reinterpret_cast< const char * >( &client ),
                        sizeof( ClientData ) );
        
        // cho phep nguoi dung nhap ban ghi khac
        cout << "Nhap so tai khoan\n? ";
        cin >> client.accountNumber;
        
        
    } // cua while
    
    return 0;
    
} // cua main

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