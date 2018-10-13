#include<stdio.h>
#include<string.h>
void ChuanHoa(char s[])
{
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==s[i+1]&&s[i]==' ')
		{
			for(int j=i+1;j<=strlen(s);j++)
			s[j-1]=s[j];
			i--;
		}
	}
		if (s[0]>='a'&&s[0]<='z') s[0]=s[0]-32;
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]==' '&&s[i+1]>='a'&&s[i+1]<='z') s[i+1]=s[i+1]-32;
		}
	printf("Sau khi chuan hoa la:%s",s);
}
main()
{
	char s[100];
	printf("Nhap xau can chuan hoa:");
	gets(s);
	ChuanHoa(s);
}
