/*Doi in hoa ra in thuong*/
//////////////////////////////////

#include<stdio.h>
#include<string.h>
/////////////////////////////////////////
/*Khong su dung ham strupr()*/

void DoiChuHoa(char *a)
{
	for (int i=0;i<strlen(a);i++)
	if(a[i]>=97 &&a[i]<=122)a[i]=a[i]+32;
	printf("Xau can chuyen la:%s",a);
}

main()
{
	char a[100];
	printf("Nhap vao xau can chuyen:");
	gets(a);
	printf("Xau can chuyen sang in hoa la:%s\n",strupr(a));/*Su dung ham strupr()*/
	DoiChuHoa(a);
}

