#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
	char s1[64] = "-a-x0-9lol";
	char s2[64];
	expand(s1, s2);
	printf("%s\n", s2);
}

void expand(char s1[], char s2[])
{
	int c1, c2, i, j;
	
	for(i = 0, j = 0; s1[i] != '\0'; i++)
	{
		if(s1[i+1] == '-')
		{
			for(c1 = s1[i], c2 = s1[i+2]; c1 < c2; c1++)
			{
				s2[j++] = c1;
			}
			i++;
		}
		else
		{
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}