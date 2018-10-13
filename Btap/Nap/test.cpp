#include<iostream>
using namespace std;
main()
{
 int a,b,c;
  cout<<"nhap 3 so nguyen la:";
     cin>>a;
     cin>>b;
     cin>>c;
  cout<<endl;
  cout<<"tong la:"<<a+b+c<<endl;
  cout<<"trung binh la:"<<(float)(a+b+c)/3<<endl;
  cout<<"tich la:"<<a*b*c<<endl;
   int min=a;
	if(min>b) min=b;
		 if(min>c) min=c;
  cout<<"nho nhat la:"<<min<<endl;
     int max=a;
	if(max<b) max =b;
	if(max<c) max=c;
  cout<<"lon nhat la:"<<max;          
}
