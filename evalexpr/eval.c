#include "evalexpr.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	eval_expr(char *str)
{
	int result;

	stacks_creation(str);
	read_write(str);
	result = g_nums[0];
	free(g_nums);
	free(g_ops);
	return (result);
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
	g_nums = (int *)malloc(sizeof(int) * n);
	g_ops = (char *)malloc(sizeof(char) * c + 1);
}

void	read_write(char *str)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = 0;
	while (str[k] != '\0')
	{
		// WARNING!!! Dalshe mozhno slomat' glaza!
		// Indusskiy kod, Alilluya!
		if ((str[k] == '-' && k == 0) || (str[k] == '-' && str[k - 1] == '(') ||
		(str[k] >= '0' && str[k] <= '9'))
			k += ft_evalatoi(&str[k], ++i);
		while (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' ||
		str[k] == '%' || str[k] == '(' || str[k] == ')')
		{
			if ((str[k] == '(' || str[k - 1] == '(' || j == -1) ||
			((str[k] == '+' || str[k] == '-') && (g_ops[j] == '(')) || 
			((str[k] == '%'|| str[k] == '*' || str[k] == '/') && (g_ops[j] == '+'
				|| g_ops[j] == '-' || g_ops[j] == '(')))
			{
				g_ops[++j] = str[k++];
			}
			else
			{
				if ((str[k] == ')' && g_ops[j] != '(') || j >= 0)
					calculator ((i--), (j--));
				if (g_ops[j] == '(' && str[k] == ')')
				{
					j--;
					k++;
				}
			}
			if (str[k] == '-' && str[k - 1] == '(')
			{	j--;
				break;
			}	
		}
		if (str[k] == ' ')
			k++;
		if (str[k] == '\0')
		{
			calculator((i), (j)); 
			continue;
		}
	}
}

int	ft_evalatoi(char *str, int i)
{
	int k;
	int number;
	int power;
	int minus;

	k = 0;
	number = 0;
	power = 1;
	minus = 1;
	if (str[k] == '-')
	{
		k++;
		minus = -1;
	}
	while (str[k] >= '0' && str[k] <= '9')
		k++;
	while (k-- > 1)
		power *= 10;
	while (str[k] >= '0' && str[k] <= '9')
	{
		number += (str[k] - '0') * power;
		k++;
		power /= 10;
	}
	g_nums[i] = number * minus;
	return (k);

}

void	calculator (int i, int j)
{
	if (g_ops[j] == '+')
		g_nums[i - 1] = g_nums[i - 1] + g_nums[i];
	if (g_ops[j] == '-')
		g_nums[i - 1] = g_nums[i - 1] - g_nums[i];
	if (g_ops[j] == '*')
		g_nums[i - 1] = g_nums[i - 1] * g_nums[i];
	if (g_ops[j] == '/')
		g_nums[i - 1] = g_nums[i - 1] / g_nums[i];
	if (g_ops[j] == '%')	
		g_nums[i - 1] = g_nums[i - 1] % g_nums[i];
}
