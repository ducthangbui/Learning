#include<iostream> 
#include<conio.h> 
using namespace std; 
void nhap(int a[],int n) 
{ 
     for (int i=0;i<n;i++) 
     { 
         cout<<"a["<<i<<"]="; 
         cin>>a[i]; 
     } 
} 
int kiemtra(int a[],int n,int i) 
{ 
    int t=a[i]; 
    for (int j=0;j<i;j++) 
        if (t==a[j])return 0; 
    return 1; 
} 
int dem (int a[],int n,int i) 
{ 
    int t=a[i],j=0; 
    for (;i<n;i++) 
    { 
        if (t==a[i]) j++; 
    } 
    return (j); 
} 
int main () 
{ 
    int a[100],n; 
    cout<<"nhap mang a, co ptu n=:"; 
    cin>>n; 
    nhap(a,n); 
    cout<<a[0]<<" co "<<dem(a,n,0)<<" ptu\n"; 
    for (int i=1;i<n;i++) 
    { 
        if (kiemtra(a,n,i)) cout<<a[i]<<" co "<<dem(a,n,i)<<" ptu\n"; 
    } 
    getch(); 
    return 0; 
} 
