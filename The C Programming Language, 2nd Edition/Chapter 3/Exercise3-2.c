#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main()
{
	int c, i;
	char t[100], s[100];
	
	for(i = 0; (c=getchar()) != EOF; ++i)
	{
		t[i] = c;
	}
	t[i] = '\0';
	
	escape(s, t);
	printf("%s\n", s);
	unescape(s, t);
	printf("%s", s);
}

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	
	for(i = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	
	for(i = 0; t[i] != '\0'; i++) {
		if(t[i] == '\\') {
			switch(t[i++]) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				default:
					s[j++] = '\\';
					s[j++] = t[i];
					break;
			}
		}
		else {
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
}