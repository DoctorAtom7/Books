#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, d, sign;
	while(isspace(c = getch()))	/* skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-') {
		d = c;
		if(!isdigit(c = getch())) {
			if(c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
	int c, sign;
	float i;
	while(isspace(c = getch()))	/* skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if(c == '.')
		for(i = 10.0; isdigit(c = getch()); i *= 10.0) {
			printf("%f %f\n", *pn, ((c - '0') / i));
			*pn = *pn + ((c - '0') / i);
		}
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

main()
{
	float x;
	float *pn;
	pn = &x;
	
	getfloat(pn);
	printf("%f\n", *pn);
}


#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void) /*get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}