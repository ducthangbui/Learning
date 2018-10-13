#include<stdio.h>
#include<math.h>
main()
{
	int n,m,dem=0;
	printf("Nhap vao so m:");
	scanf("%d",&m);
	printf("Nhap vao so m:");
	scanf("%d",&n);
	for (int i=m;i<=n;i++)
	if ((int)sqrt(i)==sqrt(i)) dem++;
	//printf("%d\n",(int)sqrt(n));
	//printf("%f",sqrt(n));
	printf("Trong [m,n] co %d so chinh phuong",dem);
}
