#include<stdio.h>
#include<conio.h>
int kiemtratang(int a[],int n)
{
    int i,dem=0;
    for(i=0;i<n-1;i++)
    {
                 if(a[i]<=a[i+1])
                 dem++;
    }
                    if(dem==(n-1))
                    return 1;
                    return 0;
}
int kiemtragiam(int a[],int n)
{
    int i,dem=0;
    for(i=0;i<n-1;i++)
    {
                    if(a[i]>=a[i+1])
                    dem++;
    }
                    if(dem==(n-1))
                    return 1;
                    return 0;
}
                   
 
int main()
{
    int i=0,n;
    int a[10];
    do
    {
        printf("\n Nhap 1 so n= ");
        scanf("%d",&n);
    }while(n<0||n>99999);
    while(n>0)
    {
      a[i]=n%10;
      n/=10;
      i++;
    }
    if(kiemtratang(a,i)==1||kiemtragiam(a,i)==1)
    printf("\n Co thu tu ");
    else
    printf("\n Khong co thu tu ");
    getch();
    return 0;
}
