#include<iostream>
using namespace std;
 int duongkinh (int n)
     {
	    return 2*n;
     }
 float chuvi (int n)
     {
     	return 2*3.14159*n;
     }
 float dientich (int n)
     {
     	return 2*3.14159*n*n;
     }    
main()
{
	int r;
	cout<<"nhap r la:"<<endl;
	cin>>r;
	cout<<"duong kinh la: "<<duongkinh(r)<<endl;
	cout<<"chu vi la: "<<chuvi(r)<<endl;
	cout<<"dien tich la:"<<dientich(r);
}

