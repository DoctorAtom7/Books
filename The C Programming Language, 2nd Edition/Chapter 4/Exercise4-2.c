#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

double atof(char s[]);

main()
{
	char s[MAXLINE] = "123.45e6";
	printf("%F", atof(s));
}

double atof(char s[])
{
	double val, power;
	int i, exp, sign;
	
	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	if(s[i] == 'e')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	for(; exp > 0; exp--)
		val = sign == 1 ? val * 10.0 : val / 10.0;
	return val;
}