#include <stdio.h>
#define LEN 100

int strcat(char *s, char *t);

main()
{
	char x[LEN] = "This is a test.";
	char y[LEN] = "test.";

	printf("%d", strend(x, y));
}

int strend(char *s, char *t)
{
	char *u = t;
	
	while(*s++ != '\0')
		;
	while(*t++ != '\0')
		;
	while(*s-- == *t--)
		;
	if(t < u)
		return 1;
	else
		return 0;
}