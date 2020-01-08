#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, w, state, i, j, biggest;
	int wl[10];
	
	for(i = 0; i < 10; ++i)
		wl[i] = 0;
	
	state = OUT;
	w = 0;
	while((c = getchar()) != EOF) {
		if((c == ' ' || c == '\n' || c == '\t') && state == IN) {
			state = OUT;
			++w;
		}
		else if(state == OUT) {
			state = IN;
			++wl[w];
		}
		else if(state == IN) {
			++wl[w];
		}
	}
	
	biggest = 0;
	for(i = 0; i < 10; ++i) {
		if(wl[i] > biggest) {
			biggest = wl[i];
		}
	}
			
	
	for(i = biggest; i > 0; --i) {
		for(j = 0; j < 10; ++j) {
			if(wl[j] >= i) {
				putchar('*');
			}
			else {
				putchar(' ');
			}
		}
		if(i != 1)
		{
			putchar('\n');
		}
	}
}