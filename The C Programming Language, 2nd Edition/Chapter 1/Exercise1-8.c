#include <stdio.h>

main()
{
	int c, bk, tb, nl;
	
	bk = 0;
	tb = 0;
	nl = 0;
	while((c = getchar()) != EOF)
		if (c == ' ')
			++bk;
		else if(c == '\t')
			++tb;
		else if(c == '\n')
			++nl;
	printf("%d Blanks, %d Tabs, %d Newlines\n", bk, tb, nl);
}