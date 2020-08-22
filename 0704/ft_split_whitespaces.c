#include <stdlib.h>
#include <stdio.h>

char	**ft_split_whitespaces(char *str)
{
	char **strchar;
	int len;
	int i;
	int k;

	i = 0;
	len = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			if((i - 1) == -1 || str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n') 
				len++;
		i++;
	}
	strchar = (char**)malloc(sizeof(char*) * len);
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			if((i - 1) == -1 || str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n') 
			{
				strchar[k++] = &str[i];
//для проверки адресов				
//				printf ("%p\n", &str[i]);
//				printf ("%s\n", &str[i]);
			}

		i++;
	}
	strchar[k] = "0";
	return (strchar);
}
