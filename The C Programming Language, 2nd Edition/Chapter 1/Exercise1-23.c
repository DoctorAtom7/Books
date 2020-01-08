#include <stdio.h>

main()
{
	int c, quote, comment;
	
	quote = 0;
	comment = 0;
	while ((c = getchar()) != EOF)
	{
		if(c == '\"' && quote == 0 && comment == 0)
		{
			putchar('\"');
			quote = 1;
		}
		else if(c == '\"' && quote == 1 && comment == 0)
		{
			putchar('\"');
			quote = 0;
		}
		else if(c == '/' && quote == 0)
		{
			c = getchar();
			if(c == '*')
			{
				comment = 1;
			}
			else
			{
				putchar('/');
				putchar(c);
			}
		}
		else if(c == '*' && quote == 0)
		{
			c = getchar();
			if(c == '/')
			{
				comment = 0;
			}
		}
		else if(comment == 0)
		{
			putchar(c);
		}
	}
}