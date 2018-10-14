// Fig. 14.8: fig14_08.cpp
// Credit inquiry program.
#include <iostream>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
using std::fixed;
using std::showpoint;
using std::left;
using std::right;

#include <fstream>

using std::ifstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>    
 
enum RequestType { ZERO_BALANCE = 1, CREDIT_BALANCE, 
   DEBIT_BALANCE, END };
int getRequest();
bool shouldDisplay( int, double );
void outputLine( int, const char * const, double );

int main()
{
   // mở file
   ifstream inClientFile( "clients.dat", ios::in );

   // thoát khỏi chương trình nếu ifstream không thể mở file
   if ( !inClientFile ) {
      cerr << "Khong mo duoc file" << endl;
      exit( 1 );

   } // cua if

   int request;
   int account;
   char name[ 30 ];
   double balance;

   // lay yeu cau của nguoi dung (0, tai khoan tin dung, tai khoan ghi no)
   request = getRequest();

   // xu ly yeu cau cua nguoi dung 
   while ( request != END ) {

      switch ( request ) {

         case ZERO_BALANCE:
            cout << "\nTai khoan voi so du = 0:\n";
            break;

         case CREDIT_BALANCE:
            cout << "\nTai khoan voi so du am:\n";
            break;

         case DEBIT_BALANCE:
            cout << "\Tai khoan voi so du am:\n";
            break;

      } // ket thuc switch

      // doc account, name va balance tu file
      inClientFile >> account >> name >> balance;

      // hien thi noi dung file (cho toi khi gap eof)
      while ( !inClientFile.eof() ) {

         // hien thi tung ban ghi
         if ( shouldDisplay( request, balance ) )
            outputLine( account, name, balance );

         // doc account, name va balance tu file
         inClientFile >> account >> name >> balance;

      } // ket thuc while ben trong
      
      inClientFile.clear();    // reset eof cho lan tiep theo
      inClientFile.seekg( 0 ); // chuyen ve dau file
      request = getRequest();  // lay them yeu cau tu nguoi dung

   } // ket thuc while ben ngoai

   cout << "Ket thuc." << endl;

   return 0; // ham huy cua ifstream se tu dong dong file 

} // end main

// Lay yeu cau tu nguoi dung
int getRequest()
{ 
   int request;

   // Hien thi menu
   cout << "\nNhap yeu cau" << endl
        << " 1 - Tai khoan = 0" << endl
        << " 2 - Tai khoan am" << endl
        << " 3 - Tai khoan duong" << endl
        << " 4 - Ket thuc" << fixed << showpoint;

   // Nhap yeu cau
   do {
      cout << "\n? ";
      cin >> request;

   } while ( request < ZERO_BALANCE && request > END );

   return request;

} // end function getRequest

// determine whether to display given record
bool shouldDisplay( int type, double balance )
{
   // truong hop hien thi tai khoan am
   if ( type == CREDIT_BALANCE && balance < 0 )
      return true;

   // truong hop hien thi tai khoan duong
   if ( type == DEBIT_BALANCE && balance > 0 )
      return true;

   // truong hop hien thi tai khoan = 0
   if ( type == ZERO_BALANCE && balance == 0 )
      return true;

   return false;

} // end function shouldDisplay

// hien thi tung ban ghi trong file
void outputLine( int account, const char * const name, 
   double balance )
{
   cout << left << setw( 10 ) << account << setw( 13 ) << name
        << setw( 7 ) << setprecision( 2 ) << right << balance
        << endl;

} // end function outputLine

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
