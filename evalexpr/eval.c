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
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
		str[i] == '/' || str[i] == '%' || str[i] == '(' ||
		str[i] == ')' || str[i] == ' ')
			c++;
		i++;
	}
	if ((g_nums = (int *)malloc(sizeof(int) * n)) == NULL ||
	(g_ops = (char *)malloc(sizeof(char) * c + 1)) == NULL)
		write(1, "Memory error\n", 13);
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
		if (str[k] == ' ')
			k++;
	//	printf("____________________k = %d\n", k);
	//	printf("START str[%d] %s\n", k, &str[k]); 
	//	printf("START g_nums[%d] %d\n", i, g_nums[i]); 
	//	printf("START g_ops[%d] %s\n", j, &g_ops[j]); 
	// WARNING!!! Dalshe mozhno slomat' glaza!
	// Indusskiy kod, Alilluya!
	// "86-47*(-26-75/(47-98/23)+17/(-86+44*38))"
	//"3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1"
		if ((str[k] == '-' && k == 0) || (str[k] == '-' &&
		str[k - 1] == '(') || (str[k] >= '0' && str[k] <= '9'))
		{
			k += ft_evalatoi(&str[k], ++i);
		//	printf("write g_nums[%d] %d\n", i, g_nums[i]);
		//	printf("k = %d\n", k);
			if (str[k] != '\0')
				continue;	
		}
		if ((str[k] == '(' || str[k - 1] == '(' || j == -1) ||
		((str[k] == '+' || str[k] == '-') && (g_ops[j] == '(')) || 
		((str[k] == '%'|| str[k] == '*' || str[k] == '/') &&
		(g_ops[j] == '+' || g_ops[j] == '-' || g_ops[j] == '(')))
		{
			g_ops[++j] = str[k++];
	//		printf("write g_ops[%d] %s\n", j, &g_ops[j]); 
		}
		else
		{
		// while((str[k] == ')' && g_ops[j] != '(') || j >= 0)
			while (g_ops[j] != '(' && j >= 0)
			{
			//	printf("calc g_nums[%d] %d\n", i, g_nums[i]); 
			//	printf("calc g_nums[%d] %d\n", (i - 1), g_nums[i - 1]); 
			//	printf("calc g_ops[%d] %s\n", j, &g_ops[j]); 
				calculator ((i--), (j--));
			//	printf("%s\n", &str[0]);
			}
			if (g_ops[j] == '(' && str[k] == ')')
			{
				j--;
				k++;
			//	printf("here\n");
			}
		}
			if (str[k] == '\0')
	//		{
	//			printf("check\n");
				while (i > 0)
					calculator((i--), (j--)); 
	//		}
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
	while ((--k >= 1 && minus == 1) || (k >= 2 && minus == -1))
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
