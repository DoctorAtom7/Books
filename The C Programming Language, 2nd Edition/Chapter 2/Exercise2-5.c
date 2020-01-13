#include <stdio.h>

#define LEN 20

int any(char s1[], char s2[]);

main()
{
	char s1[LEN] = "Test this!";
	char s2[LEN] = "te";
	
	printf("%d", any(s1, s2));
}

int any(char s1[], char s2[])
{
	int i, j;
	
	for(i = 0; s1[i] != '\0'; i++)
	{
		for(j = 0; s2[j] != '\0'; j++)
		{
			if(s1[i] == s2[j])
			{
				return i;
			}
		}
	}
	
	return -1;
}