#include <vector>
#include<iostream>
using namespace std;

int main()
{
   vector<int> values;

   //Th�m d? li?u v�o vector values.
   values.push_back(1);
   values.push_back(2);
   values.push_back(3);
   cout << "The size of values is " << values.size() << endl;
   
   //Xo� l� ��y!!.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   
   // Xo� ti?p.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   
   //Xo� n?a, xo� cho h?t th? th�i ^^.
   cout << "Popping a value from the vector...\n";
   values.pop_back();
   cout << "The size of values is now " << values.size() << endl;
   return 0;
} 


