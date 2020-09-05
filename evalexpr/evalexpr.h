
#ifndef EVALEXPR_H
# define EVALEXPR_H

int	*g_nums;
char	*g_ops;



int	eval_expr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	stacks_creation(char *str);
void	read_write(char *str);

#endif
