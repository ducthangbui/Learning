#include <vector>
#include<iostream>
using namespace std;

int main()
{
   vector<int> values;

   //Thêm d? li?u vào vector values.
   values.push_back(1);
   values.push_back(2);
   values.push_back(3);
   cout << "The size of values is " << values.size() << endl;
   
   //Xoá là ðây!!.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   
   // Xoá ti?p.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   
   //Xoá n?a, xoá cho h?t th? thôi ^^.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   return 0;
} 


