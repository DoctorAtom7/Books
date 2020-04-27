#include <stdio.h>
#define LEN 100

void strcat(char *s, char *t);

main()
{
	char x[LEN] = "This is a test.";
	char y[LEN] = "Another test.";
	
	strcat(x, y);

	printf("x = %s\n", x);
	printf("y = %s", y);
}

/* strcat: concatenate t to end of s; s must be big enough
void strcat(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while(s[i] != '\0')		/* find end of s 
		i++;
	while((s[i++] = t[j++]) != '\0')	/* copy t 
		;
} */

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t)
{
	while(*(++s) != '\0')
		;
	while(*s++ = *t++)
		;
}