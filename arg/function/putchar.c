#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}
int maim(void)
{
	putchar('a');
	return 0;
}

