#include "evalexpr.h"
#include <stdio.h>
#include <stdlib.h>

int	eval_expr(char *str)
{
	stacks_creation(str);
	return (7);
}

void	stacks_creation (char *str)
{
	int n;
	int c;
	int i;
	int *nums;
	char *ops;
	

	n = 0;
	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n++;
		if (str[i] >= '%' && str[i] <= '/')
			c++;
		i++;
	}
	printf("n = %d\nc = %d\n", n, c);
	nums = (int *)malloc(sizof(int) * n);
	ops = (char *)malloc(sizof(char) * c);
	
}
