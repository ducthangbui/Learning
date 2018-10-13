#include<conio.h>
#include<stdio.h>
int fibonacci(int n)
{
   int i, fibo,fibo1=0,fibo2=1;
   for(i=0;i<n;i++)
   {
    
    fibo=fibo1+fibo2;
    fibo1=fibo2;
    fibo2=fibo;
    
    }
    return fibo;
}
main()
{
 int n;
 printf("nhap n:\n");
 scanf("%d",&n);
 printf("so fibonacci %d là %d\n",n,fibonacci(n));
 getch();
 
}
