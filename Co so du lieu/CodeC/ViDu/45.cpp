#include <stdio.h>
#include<string.h>
void StrDel(char *s, int n)
{
	printf("%s\n",s+n);
	printf("%d\n",strlen(s));
	printf("%d\n",strlen(s+n)+1);
	memmove(s, s + n, strlen(s+n)+1);
	printf("%s\n",s);
	//printf("%s\n",s+n);
	//printf("%s\n",s+4);
}
int	main()
{
	char	s[]= "Thu xoa 12345";
	printf("\n%s\n",s+4);
	StrDel(s, 4);	 	printf("%s\n", s);
	StrDel(s + 4, 3);	printf("%s\n", s);
	return 0;
}
