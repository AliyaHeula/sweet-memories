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
//	printf("%s\n", g_ops);
	printf("RESULT = %d\n", g_nums[i]);
//	while (g_nums[i])
//		printf("%d\n", g_nums[i++]);LL
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

	i = -1;
	j = -1;
	k = 0;
	while (str[k] != '\0')
	{
			printf("kkkk = %d\n", k);
		// WARNING!!! Dalshe mozhno slomat' glaza!
		// Indusskiy kod, Alilluya!
		while (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' || str[k] == '%'
			|| str[k] == '(' || str[k] == ')')
		{
			if ((str[k] == '(' || str[k - 1] == '(' || j == -1) ||
			((str[k] == '+' || str[k] == '-') && (g_ops[j] == '(')) || 
			((str[k] == '%'|| str[k] == '*' || str[k] == '/') && (g_ops[j] == '+'
				|| g_ops[j] == '-' || g_ops[j] == '(')))
		
			{
				j++;
				g_ops[j] = str[k];
				printf("write.g_ops[%d] calc = %s\n", j, &g_ops[j]);
				k++;
			}
			//if (str[k] == ')')
			else
			{
				if ((str[k] == ')' && g_ops[j] != '(') || j >= 0)
				{
					printf(".k = %d\n", k);
					printf("1.g_nums[%d] calc = %d\n",i, g_nums[i]);
					printf("2.g_nums[%d] calc = %d\n",(i - 1), g_nums[i - 1]);
					printf("3.g_ops[%d] calc = %s\n", j, &g_ops[j]);
					calculator ((i), (j));
					j--;
					i--;
				//	printf("%s\n", "calculation");
				}
				if (g_ops[j] == '(' && str[k] == ')')
				{
					j--;
					k++;
				}
			}

		}
		if (str[k] >= '0' && str[k] <= '9')
		{
			i++;
			k += ft_evalatoi(&str[k], i);
//			printf("k = %d\n", k);
//			printf("str[k]= %s\n", &str[k]);
//			printf("i = %d\n", i);
//			printf("j = %d\n", j);
			printf("write.g_nums[%d] calc = %d\n",i, g_nums[i]);
		}
		if (str[k] == ' ')
		{
			k++;
//			printf("else = (");
		}
		if (str[k] == '\0')
		{
//			printf("%s\n", "here");
			calculator((i), (j)); 
//			printf("g_nums = %d\n", g_nums[i]);
//			printf("g_ops = %s\n", &g_ops[j]);
			continue;
		}
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
