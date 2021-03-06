#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	int i = INT_MIN;
	char s[128];
	
	itoa(i, s);
	printf("%s\n", s);
}

void itoa(int n, char s[])
{
	int i, sign;
	
	sign = n;
	i = 0;
	do {
		if(sign < 0)
		{
			s[i++] = -(n % 10) + '0';
		}
		else
		{
			s[i++] = n % 10 + '0';
		}
	} while((n /= 10) != 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;
	
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}