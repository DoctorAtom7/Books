#include <stdio.h>

enum states { END, CONTINUE }

main()
{
	int loop = CONTINUE;
	int lim = 40;
	char s[lim];
	while(loop)
	{
		if(c == EOF)
		{
			loop = END;
		}
		else if(c == '\n')
		{
			loop = END;
		}
		else if(i < lim - 1)
		{
			s[i] = c;
			++i;
		}
		else
		{
			loop = END;
		}
	}
}