#include<stdio.h>
#include<stdlib.h>
main()
{
	int *mang;
	int n, i=0, t;
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	mang=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i);
		scanf("%d",mang+i);
	}
	i=0;
	do
		{
			t=*(mang+i);
			if(t%2==0) 
			{
				int j;
				for (j=i; j<n-1;j++)
				{
					*(mang+j)=*(mang+(j+1));
				}
				free(mang+j);
				n--;
			}
			else i++;
		}
	while(i<n);
	for(int i=0;i<n;i++)
	printf("%d ",*(mang+i));
}
