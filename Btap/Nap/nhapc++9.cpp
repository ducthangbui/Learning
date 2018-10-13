#include<iostream>
using namespace std;
int ucln (int a, int b)
{
	if(a==0&&b==0)  
	               return 0;
	while(b!=0)
         {
         	int x=b;
         	b=a%b;
         	a=x;
         }
      return a;    
}
int bcnn (int a , int b)
{   
     int x;
	if(a==0||b==0) 
	              return 0;
	  x=(a*b)/ucln(a,b);
	  return x;
	              
}
main()
{
	int a,b;
	cout<<"nhap a la:";
	cin>>a;
	cout<<"nhap b la:";
	cin>>b;
	
	cout<<"uoc chung lon nhat la :"<<ucln(a,b)<<endl;
	cout<<"boi chung nho nhat la:"<<bcnn(a,b);
}
