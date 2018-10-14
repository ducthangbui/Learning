#include <stdio.h>
char * fgets(char *buf, int bsize, FILE *fp)
{
int i;
int c;
int done = 0;
if (buf == 0 || bsize <= 0 || fp == 0)
	return 0;
for (i = 0; !done && i < bsize - 1; i++) 
{
	c = fgetc(fp);
	if (c == EOF) 
	{
	done = 1;
	i--;
	} else {
	buf[i] = c;
	//if (c == '\n') done = 1;
	}
}
buf[i] = '\0';
if (i == 0)
	return 0;
else
	return buf;
}
