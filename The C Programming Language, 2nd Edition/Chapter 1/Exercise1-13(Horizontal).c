#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, w, state, i, j;
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
	
	for(i = 0; i < 10; ++i) {
		if(wl[i] != 0) {
			for(j = 0; j < wl[i]; ++j) {
				putchar('*');
			}
			putchar('\n');
		}
	}
}