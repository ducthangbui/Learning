#include<stdio.h>
main()
{
	FILE *f1,*f2;
	int n;
	scanf("%d",&n);
	f1=fopen("Dem1.txt","w+b");
	fprintf(f1,"%d",n);
	fclose(f1);
	f2=fopen("Dem1.txt","r+b");
	fscanf(f2,"%d",&n);
	printf("\n%d",n);
	fclose(f2);
}
