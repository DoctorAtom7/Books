#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION '1'

int getop(char []);
void push(double);
double pop(void);
void mathfunc(char s[]);

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	double variables[26];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case FUNCTION:
			mathfunc(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			
		case '^':
			op2 = pop();
			push(pow(pop(),op2));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'p':
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'd':
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':
			op1 = pop();
			op2 = pop();
			push(op2);
			push(op1);
			break;
		case 'c':
			clear();
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("errorL unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void mathfunc(char s[])
{
	if(strcmp(s, "sin"))
		push(sin(pop()));
	else if(strcmp(s, "cos"))
		push(cos(pop()));
	else if(strcmp(s, "tan"))
		push(tan(pop()));
	else if(strcmp(s, "ln"))
		push(log(pop()));
	else if(strcmp(s, "log"))
		push(log10(pop()));
	else
		printf("error: %s not supported\n", s);
}

#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(islower(c))
	{
		while(islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		if(strlen(s) > 1)
			return FUNCTION;
		else
			return c;
	}
	else if(!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */
	else if(c == '-') {
		c = getch();
		if(!isdigit(c) && c != '.') {
			ungetch(c);
			return '-';
		}
		else
			ungetch(c);
	}
	i = 0;
	if(isdigit(c) || c == '-')	/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	/* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
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