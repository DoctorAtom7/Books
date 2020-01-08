#include <stdio.h>

main()
{
	int c, single_quote, double_quote, braces, brackets, parentheses, comment;
	single_quote = double_quote = braces = brackets = parentheses = comment = 0;
	
	while((c = getchar()) != EOF)
	{
		if(comment = 1)
		{
			if(c == '\\')
			{
				c = getchar();
			}
			else if(c == '\'')
			{
				++single_quote;
			}
			else if(c == '\"')
			{
				++double_quote;
			}
			else if(c == '[')
			{
				++brackets;
			}
			else if(c == ']')
			{
				--brackets;
			}
			else if(c == '{')
			{
				++braces;
			}
			else if(c == '}')
			{
				--braces;
			}
			else if(c == '(')
			{
				++parentheses;
			}
			else if(c == ')')
			{
				--parentheses;
			}
			else if(c == '/')
			{
				
			}
		}
		else
		{
			if(c == '*')
			{
				c = getchar();
				if(c == '/')
				{
					comment = 0;
				}
			}
		}
	}
	
	printf("%d %d %d %d %d %d\n", single_quote, double_quote, braces, brackets, parentheses, comment);
}