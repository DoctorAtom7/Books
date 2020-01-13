#include <stdio.h>

#define LEN 20

void squeeze(char s1[], char s2[]);
int match(char s[], int c);

main()
{
	char s1[LEN] = "Test this!";
	char s2[LEN] = "te";
	
	squeeze(s1, s2);
	printf(s1);
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	
	for(i = j = 0; s1[i] != '\0'; i++)
	{
		if(!match(s2, s1[i]))
		{
			s1[j++] = s1[i];
		}
	}
	
	s1[j] = '\0';
}

int match(char s[], int c)
{
	int i;
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == c)
		{
			return 1;
		}
	}
	
	return 0;
}