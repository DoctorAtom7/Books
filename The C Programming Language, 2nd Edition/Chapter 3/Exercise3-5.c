#include <stdio.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
	int i = 44;
	char s[128];
	
	itob(i, s, 2);
	printf(s);
}

void itob(int n, char s[], int b)
{
	int i, x, sign;
	
	sign = n;
	i = 0;
	do {
		if(sign < 0)
		{
			x = -(n % b);
			if(x > 9)
			{
				s[i++] = x + 7 + '0';
			}
			else
			{
				s[i++] = x + '0';
			}
		}
		else
		{
			x = n % b;
			if(x > 9)
			{
				s[i++] = x + 7 + '0';
			}
			else
			{
				s[i++] = x + '0';
			}
		}
	} while((n /= b) != 0);
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