#include <stdio.h>

main()
{
	int c, biggest, i, j;
	int letters[26];
	
	for(i = 0; i < 26; ++i)
		letters[i] = 0;
	
	while((c = getchar()) != EOF) {
		if(c >= 97) {
			c -= 97;
		}
		else {
			c -= 65;
		}
		
		if(c >= 0 && c <= 25) {
			++letters[c];
		}
	}
	
	biggest = 0;
	for(i = 0; i < 26; ++i) {
		if(letters[i] > biggest) {
			biggest = letters[i];
		}
	}
			
	
	for(i = biggest; i > 0; --i) {
		for(j = 0; j < 26; ++j) {
			if(letters[j] >= i) {
				putchar('*');
			}
			else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
	
	for(i = 65; i < 91; ++i)
		putchar(i);
}