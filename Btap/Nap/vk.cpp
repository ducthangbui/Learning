#include<iostream>
#include<iomanip>
using namespace std;
   void binhphuong (int n)
        {
         cout<<n*n<<" ";
        }
   void lapphuong (int n)
       {
    cout<<n*n*n<<endl;
    }     
   void hienthi (int i)
       {
    for( i=0;i<=10;i++)
     {  
     cout<<left <<setw(3)<<i<<"  "<< right;
     binhphuong(i);
        lapphuong(i); 
  }
    }    
   int main()
       {
         int n;
         hienthi(n);
         return 0;
       }
