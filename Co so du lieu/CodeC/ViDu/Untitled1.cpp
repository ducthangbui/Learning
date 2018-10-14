#include <conio.h>
#include <stdio.h>

float tong(float a)
{ 
float i;
float tong=1, dau=(-1);
for (i=1; i<=a; i++)
{ 
tong=tong+dau*1/(2*i+1);
dau=dau*(-1);
}
return tong; 
}
main()
{ 
float c;
float n=0, pi;
printf(" Nhap vao so c la: "); 
scanf("%f", &c); 
while (1>((2*n+1)*c))
{ 
n++;
}
pi=4*tong(n);
printf(" Gia tri so pi la: %f\n",pi);
getch();
}
