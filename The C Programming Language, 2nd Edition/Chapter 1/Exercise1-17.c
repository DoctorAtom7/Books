#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int getline(char line[], int maxline);

/* print longest input line */
main()
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONGLINE)
			printf("%s", line);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;
	
	j=0;
	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
		if(i < lim-2) {
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