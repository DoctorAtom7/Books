#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

void itoa(int n, char s[]);

main()
{
	char s[MAXLINE];
	itoa(-123, s);
	printf(s);
}

void itoa(int n, char s[])
{
	static int i;
	
	if(n / 10)
	{
		itoa(n / 10, s);
	}
	else
	{
		i = 0;
		if(n < 0)
		{
			s[i++] = '-';
		}
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}