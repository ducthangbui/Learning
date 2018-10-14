#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "memmove can be very useful......";
  memmove (str+4,str,11);
  puts (str);
  return 0;
}
