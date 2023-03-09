#include "../incl/push_swap.h"
#include "../bonus/GetNextLine/get_next_line.h"
// #include "../libft/libft.h"

// void	ft_exit(t_stack *stack)
// {
// 	free(stack->a);
// 	free(stack->b);
// 	exit(0);
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

// void	print_error(int *stack)
// {
// 	free(stack);
// 	ft_printf("ERROR\n");
// 	exit(0);
// }

// void	check_doubles(int *a, int dim)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	while (i < dim)
// 	{
// 		while (j < dim)
// 		{
// 			if (a[i] == a[j])
// 				print_error(a);
// 			j++;
// 		}
// 		i++;
// 		j = i + 1;
// 	}
// }

// int	ft_atoi(char *str, int *stack)
// {
// 	long int	r;
// 	int			s;
// 	int			i;

// 	r = 0;
// 	s = 1;
// 	i = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '+')
// 		i++;
// 	else if (str[i] == '-')
// 	{
// 		s = -1;
// 		i++;
// 	}
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			print_error(stack);
// 		r = r * 10 + str[i++] - '0';
// 	}
// 	if (r > 2147483647 || r < -2147483647)
// 		print_error(stack);
// 	return (r * s);
// }

// void	fill_stack(int ac, char **av, int i, t_stack *stack)
// {
// 	int j;
	
// 	stack->a = (int *)malloc(sizeof(int) * (ac - 1));
// 	stack->b = (int *)malloc(sizeof(int) * (ac - 1));
// 	j = 0;
// 	while (i < ac)
// 		stack->a[j++] = ft_atoi(av[i++], stack->a);
// 	check_doubles(stack->a, j);
// 	stack->len_A = j;
// 	stack->len_B = 0;
// 	stack->moves = 0;
// }

// t_stack	*init(int ac, char **av)
// {
// 	char	**tmp;
// 	int		len;
// 	t_stack *stack;

// 	tmp = NULL;
// 	len = 0;
// 	if (ac == 2)
// 	{
// 		tmp = ft_split(av[1], ' ');
// 		while (tmp[len] != NULL)
// 			len++;
// 		stack = malloc(len * sizeof(t_stack));
// 		fill_stack(len, tmp, 0, stack);
// 		free(tmp);
// 	}
// 	else if (ac >= 3)
// 	{
// 		stack = malloc((ac - 1) * sizeof(t_stack));
// 		fill_stack(ac, av, 1, stack);
// 	}
// 	else
// 		return (NULL);
// 	return (stack);
// }

int main(int ac, char **av)
{
    t_stack *stack;

    if (ac < 2)
        return (0);
    stack = init(ac, av);
    print_arraya(stack, stack->len_A);
    ft_exit(stack);
}