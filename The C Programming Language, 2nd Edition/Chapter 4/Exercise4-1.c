#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "test";	/* pattern to search for */

/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	
	while (getline(line, MAXLINE) > 0)
		printf("%d\n", strindex(line, pattern));
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k, p;
	
	p = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			p = i;
	}
	return p;
}