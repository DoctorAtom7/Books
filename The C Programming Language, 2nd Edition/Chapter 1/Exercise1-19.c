#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
main()
{
	char line[MAXLINE];		/* current input line */
	
	while (getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;
	
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < lim - 2) {
			s[j] = c;
			++j;
		}
		s[i] = c;
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}

void reverse(char s[])
{
	int i, j;
	char temp;
	
	i = 0;
	while(s[i] != '\n')
		++i;
	--i;
	j = 0;
	while(j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}