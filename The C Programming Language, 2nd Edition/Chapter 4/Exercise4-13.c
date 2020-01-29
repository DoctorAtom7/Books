#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char s[]);

main()
{
	char s[MAXLINE] = "test";
	reverse(s);
	printf(s);
}

void reverse(char s[])
{
	int c;
	static int i = 0;
	int j = (strlen(s) - 1) - i;
	
	if(i < j)
	{
		c = s[i];
		s[i++] = s[j];
		s[j] = c;
		reverse(s);
	}
}