#include<stdio.h>
#include<string.h>
#include<conio.h>
struct SV{
	int ma;
	char ten[30];
	char ns[20];
	float d1,d2,d3,tong;
};
main(){
SV a[100],tg;
FILE *f1 = fopen("input4.10.txt","r");
FILE *f2 = fopen("output4.10.txt","w");
int t,i,j;
fscanf(f1,"%d",&t);
char c[100];
fgets(c,100,f1);
for (i=0;i<t;i++){
	a[i].ma = i+1;
	fgets(a[i].ten,100,f1);
	a[i].ten[strlen(a[i].ten)-1] ='\0';
	fgets(a[i].ns,100,f1);
	a[i].ns[strlen(a[i].ns)-1] ='\0';
	fscanf(f1,"%f%f%f",&a[i].d1,&a[i].d2,&a[i].d3);
    a[i].tong = a[i].d1 + a[i].d2+a[i].d3; 
    fgets(c,100,f1);
 }
for (i=0;i<t-1;i++)
  for (j=i+1;j<t;j++)
    if (a[i].tong < a[j].tong) {
    	tg = a[i];
    	a[i]= a[j];
    	a[j]= tg;
    }
for (i=0;i<t;i++)
  printf("\n%d %-20s %-20s %2.2f",a[i].ma,a[i].ten,a[i].ns,a[i].tong);
}
