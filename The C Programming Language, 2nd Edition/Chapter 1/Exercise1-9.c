#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, blank;
	
	blank = IN;
	while((c = getchar()) != EOF) {
		if(c == ' ') {
			if(blank == IN) {
				putchar(' ');
				blank = OUT;
			}
		}
		else {
			putchar(c);
			blank = IN;
		}
	}
}