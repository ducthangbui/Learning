// Fig. 14.12: fig14_12.cpp
// Creating a randomly accessed file.
#include <iostream>

using std::cerr;
using std::endl;
using std::ios;

#include <fstream>

using std::ofstream;

#include <cstdlib>

struct ClientData{
    int accountNumber;
    char lastName[ 15 ];
    char firstName[ 10 ];
    double balance;};
int main()
{
   ofstream outCredit( "credit.txt", ios::binary );

   // thoat neu ofstream khong mo duoc file 
   if ( !outCredit ) {
      cerr << "Khong mo duoc file." << endl;
      exit( 1 );

   } // cua if

   // tao bien kieu ClientData voi du lieu trong
   ClientData blankClient;
    //ClientData blankClient;
    blankClient.accountNumber=10;
    strncpy( blankClient.lastName, "", 1 );
    
    strncpy( blankClient.firstName, "", 1 );
    blankClient.balance=90;
   // ghi  100 ban ghi trong
   for ( int i = 0; i < 100; i++ )
      outCredit.write( 
         reinterpret_cast< const char * >( &blankClient ), 
         sizeof( ClientData ) );

   return 0;

} // end main

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