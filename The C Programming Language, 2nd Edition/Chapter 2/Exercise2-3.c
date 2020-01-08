#include <stdio.h>

main()
{
	printf("HEX\tDEC\n");
	printf("0x7F\t%d\n", htoi("0x7F"));
	printf("7F\t%d\n", htoi("7F"));
	printf("junk\t%d\n", htoi("junk"));
}

int htoi(const char s[])
{
	int i = 0;
	int n = 0;
	
	if(s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
	{
		i = 2;
	}
	
	while(s[i] != '\0')
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			n = 16 * n + (s[i] - '0');
			++i;
		}
		else if('a' <= s[i] && s[i] <= 'f')
		{
			n = 16 * n + (s[i] - 'a' + 10);
			++i;
		}
		else if('A' <= s[i] && s[i] <= 'F')
		{
			n = 16 * n + (s[i] - 'A' + 10);
			++i;
		}
		else
		{
			break;
		}
	}
	
	if(s[i] != '\0')
	{
		return 0;
	}
	else
	{
		return n;
	}
}