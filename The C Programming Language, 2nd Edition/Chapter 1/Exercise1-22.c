#include <stdio.h>

#define TABINC 8
#define MAXLINE 20

char line[MAXLINE];

void printl(int pos);

main()
{
	int c, pos, i, temp, ns;

	pos = 0;
	while ((c = getchar()) != EOF)
	{
		line[pos] = c;
		if (c == '\t')
		{
			ns = (TABINC - (pos - 1) % TABINC);
			for (i = 0; i < ns; ++i)
			{
				if (pos == MAXLINE - 1)
				{
					printl(pos);
					pos = 0;
				}

				line[pos] = ' ';
				++pos;
			}
		}
		else if (c == '\n')
		{
			printl(pos);
			pos = 0;
		}
		else if (pos == MAXLINE - 1)
		{
			if (c == ' ')
			{
				printl(pos);
				pos = 0;
			}
			else
			{
				while (line[pos] != ' ' && pos > 0)
				{
					--pos;
				}
				
				if(pos == 0)
				{
					printl(MAXLINE);
				}
				else
				{
					printl(pos);
					temp = 0;
					for (i = 0; i < MAXLINE - pos; ++i)
					{
						if(line[pos + i] != ' ')
						{
							line[temp] = line[pos + i];
							++temp;
						}
					}
					pos = temp;
				}
			}
		}
		else
		{
			++pos;
		}
	}
}

void printl(int pos)
{
	int i;
	for (i = 0; i < pos; ++i)
	{
		putchar(line[i]);
	}
	if (pos > 0)
	{
		putchar('\n');
	}
}