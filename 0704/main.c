#include <stdio.h>

char	**ft_split_whitespaces(char *str);
void	ft_putstr(char *str);

int	main()
{
//	int i;
	char str[] = "fajkl sdkchskdh kdchsh dfhiwehbc	fsdkbfS";
	char **res;

//	i = 0;
	res = ft_split_whitespaces(str);
	printf("%s\n", *res);
//	while (res[i])
//		printf ("%p\n", res[i++]);
	return(0);

}
