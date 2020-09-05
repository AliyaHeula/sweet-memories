#include "evalexpr.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	eval_expr(char *str)
{
	int i;

	i = 0;	
	stacks_creation(str);
	read_write(str);
	printf("%s\n", g_ops);
	while (g_nums[i])
		printf("%d\n", g_nums[i++]);
	return (7);
}

void stacks_creation (char *str)
{
	int n;
	int c;
	int i;

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
	g_nums = (int *)malloc(sizeof(int) * n);
	g_ops = (char *)malloc(sizeof(char) * c + 1);
}

void	read_write(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = -1;
	while (str[++k] != '\0')
	{
		if (str[k] >= '0' && str[k] <= '9')
			g_nums[i++] = str[k] - '0';
		if (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' || str[k] == '%'
			|| str[k] == '(' || str[k] == ')')
			g_ops[j++] = str[k];
	}
}
