#include <stdio.h>
#include<string.h>
void StrIns(char *s, char *sub)
{
	int  len = strlen(sub);
	memmove(s + len, s, strlen(s)+1);
	printf("%s\n",s);
	strncpy(s, sub, len);
}
int	main()
{
	char	s[]= "Thu chen";
	
	StrIns(s, "123");	   printf("%s\n", s);
	StrIns(s + 8, "45");   printf("%s\n", s);
	return 0;
}
