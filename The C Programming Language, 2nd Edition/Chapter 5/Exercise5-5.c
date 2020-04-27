#include <stdio.h>
#define LEN 100

void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

main()
{
	char a[LEN] = "This is a test.", b[LEN] = "This is a test.", c[LEN] = "This is a test.";
	char x[LEN] = "This";

	strncpy(a, x, 3);
	printf("%s\n", a);
	strncat(b, x, 3);
	printf("%s\n", b);
	printf("%d", strncmp(c, x, 3));
}

void strncpy(char *s, char *t, int n)
{
	while(n-- != 0 && (*s++ = *t++))
		;
}

void strncat(char *s, char *t, int n)
{
	while(*(++s) != '\0')
		;
	while(n-- != 0 && (*s++ = *t++))
		;
	*s++ = '\0';
}

int strncmp(char *s, char *t, int n)
{
	for( ; n != 0 && *s == *t; s++, t++, n--)
		if(n == 0)
			return 0;
	return *s - *t;
}