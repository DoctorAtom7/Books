#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int bitlength(void);

main()
{

}

unsigned rightrot(unsigned x, int n)
{
	int r;
	
	while(n-- > 0)
	{
		r = (x & 1) << (bitlength() - 1);
		x = x >> 1
		x = x | r;
	}
	return x;
}

int bitlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	
	for(i = 0;(v = v >> 1) > 0; i++)
	{
	}
	
	return i;
}