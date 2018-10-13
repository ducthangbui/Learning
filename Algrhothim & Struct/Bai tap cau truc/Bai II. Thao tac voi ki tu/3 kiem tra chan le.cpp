#include <iostream>
#include <conio.h>
#include<string.h>
using namespace std;
int Testchanle(char t)
{
     int a[10],k=0,dem=0,x=int(t);
     while( x!=0)
     {
            k++; a[k]=x%2; x=x/2;
            }
     a[k+1]=0;
     for(int i=k+1;i>0;i--) dem+=a[i]; 
     if(dem%2==0)return 0;
     return 1;
}
main()
{
	char ch;
	cout<<"\nNhap vao 1 ki tu: ";
	cin>> ch;
    if(Testchanle(ch)==0)cout<<"\nKi tu  "<<ch<<" la Chan";
    else cout<<"\nKi tu  "<<ch<<"  la Le";
    
    // bi sao
}
