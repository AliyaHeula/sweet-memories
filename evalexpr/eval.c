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
	printf("g_nums_sum to see zero= %d\n", g_nums[i]);
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
	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] >= '0' && str[k] <= '9')
		{
			k += ft_evalatoi(&str[k], i);
			printf("k = %d\n", k);
//			printf("str[k]= %s\n", &str[k]);
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			if (str[k + 1] == '\0')
			{
				printf("%s\n", "here");
				calculator((i), (j - 1)); 
			}
			i++;
		}
		// WARNING!!! Dalshe mozhno slomat' glaza!
		// Indusskiy kod, Alilluya!
		if (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' || str[k] == '%'
			|| str[k] == '(' || str[k] == ')')
		{
			if (((str[k] == '+' || str[k] == '-') && (str[k - 1] != '+' && str[k - 1] !='-')) 
					||// ((str[k] == '%'|| str[k] == '*' || str[k] == '/') && (str[k - 1] == '+'
//				|| str[k - 1] == '-' || str[k - 1] == '(')) ||
			(str[k] == '(' || j == 0))
				g_ops[j] = str[k];
			//if (str[k] == ')')
			else
			{
				while (g_ops[j] != '(' || j != 0)
				{
					calculator ((i - 1), (j - 1));
					j--;
				}
			}
			j++;
			printf ("g_ops = %s\n", g_ops);
		}
		/*else
		{
			printf ("%s\n","simbols haven't been recognized");
			continue;
		}*/
	
		k++;
	}
}

int	ft_evalatoi(char *str, int i)
{// to implement negative numbers solution
	int k;
	int number;
	int power;

	k = 0;
	number = 0;
	power = 1;
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
	g_nums[i] = number;
	return (k - 1);

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
