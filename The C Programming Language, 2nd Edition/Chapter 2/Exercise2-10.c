#include <stdio.h>

int lower(int c);

main()
{
	putchar(lower('A'));
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}