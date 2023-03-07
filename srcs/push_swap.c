/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:07 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/02 23:03:51 by parrot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	print_arraya(t_stack *stack, int len)
{
	int	i;

	i = 0;
	ft_printf("\n\t\tSTACK A\n\n");
	while (i < len)
		ft_printf("\t\t%d\n", stack->a[i++]);
}

void	print_arrayb(t_stack *stack, int len)
{
	int	i;

	i = 0;
	ft_printf("\n\t\tSTACK B\n\n");
	while (i < len)
		ft_printf("\t\t%d\n", stack->b[i++]);
}

void	fill_stack(int ac, char **av, int i, t_stack *stack)
{
	int j;
	
	stack->a = (int *)malloc(sizeof(int) * (ac - 1));
	stack->b = (int *)malloc(sizeof(int) * (ac - 1));
	j = 0;
	while (i < ac)
		stack->a[j++] = ft_atoi(av[i++], stack->a);
	check_doubles(stack->a, j);
	stack->len_A = j;
	stack->len_B = 0;
	stack->moves = 0;
}

t_stack	*init(int ac, char **av)
{
	char	**tmp;
	int		len;
	t_stack *stack;

	tmp = NULL;
	len = 0;
	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		while (tmp[len] != NULL)
			len++;
		stack = malloc(len * sizeof(t_stack));
		fill_stack(len, tmp, 0, stack);
		free(tmp);
	}
	else if (ac >= 3)
	{
		stack = malloc((ac - 1) * sizeof(t_stack));
		fill_stack(ac, av, 1, stack);
	}
	else
		return (NULL);
	return (stack);
}

void	lil_sort(t_stack *stack)
{
	if ((stack->a[0] < stack->a[1]) && (stack->a[0] < stack->a[2]) &&
	 (stack->a[1] > stack->a[2]))
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2]) &&
	 (stack->a[1] > stack->a[2]))
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if ((stack->a[0] < stack->a[1]) && (stack->a[0] > stack->a[2]) &&
	 (stack->a[1] > stack->a[2]))
		rra(stack, 1);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2]) &&
	 (stack->a[1] < stack->a[2]))
		ra(stack, 1);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] < stack->a[2]) &&
	 (stack->a[1] < stack->a[2]))
		sa(stack, 1);
}

int	sort(t_stack *stack)
{
	if (check_sorted_asc(stack->a, stack->len_A) == 0)
	{
		if (stack->len_A == 2)
			sa(stack, 1);
		else if (stack->len_A == 3)
			lil_sort(stack);
		else
			quick_sort_a(stack, stack->len_A, 0);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_stack	*stack;
	
	if (ac <= 2)
		return (0);
	stack = init(ac, av);
	print_arraya(stack, stack->len_A);
	print_arrayb(stack, stack->len_B);
	sort(stack);
	ft_printf("\n\n=========================================\n\n");
	print_arraya(stack, stack->len_A);
	print_arrayb(stack, stack->len_B);
	ft_printf("\n\nmoves--> %d\n\n", stack->moves);
	ft_exit(stack);
}

// void	quick_sort_3_a_b(t_stack *stack, int dim)
// {
// 	if (dim == 3 && stack->len_A == 3)
// 		lil_sort(stack);
// 	else if (dim == 2)
// 	{
// 		if (stack->a[0] > stack->a[1])
// 			sa(stack, 1);
// 	}
// 	else if (dim == 3)
// 	{
// 		while (dim != 3 || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
// 		{
// 			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
// 				sa(stack, 1);
// 			else if (dim == 3 && !(stack->a[2] > stack->a[0] && stack->a[2] > stack->a[1]))
// 			{
// 				pb(stack, 1);
// 				dim--; // verify this make peace w stack->len; pb already reloads
// 			}
// 			else if (stack->a[0] > stack->a[1])
// 				sa(stack, 1);
// 			else if (dim++)
// 				pa(stack, 1);
// 		}
// 	}
// }

// void	tmp_sort(int *tmp_stk, int dim)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 0;
// 	while (i < dim)
// 	{
// 		j = i + 1;
// 		while (j < dim)
// 		{
// 			if (tmp_stk[i] > tmp_stk[j])
// 			{
// 				tmp = tmp_stk[i];
// 				tmp_stk[i] = tmp_stk[j];
// 				tmp_stk[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	median_of_numbers(int *pivot, int *stack, int dim)
// {
// 	int *tmp;
// 	int	i;
// 	int	j;

// 	tmp = (int *)malloc(sizeof(int) * dim);
// 	if (!tmp)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	while (i < dim)
// 		tmp[j++] = stack[i++];
// 	tmp_sort(tmp, dim);
// 	*pivot = tmp[dim / 2];
// 	free(tmp);
// 	return (1);
// }

// int	sort_3_b(t_stack *stack, int dim)
// {
// 	if (dim == 1)
// 		pa(stack, 1);
// 	else if (dim == 2)
// 	{
// 		if (stack->b[0] < stack->b[1])
// 			sb(stack, 1);
// 		while (dim--)
// 			pa(stack, 1);
// 	}
// 	else if (dim == 3)
// 	{
// 		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
// 		{
// 			if (dim == 1 && stack->a[0] > stack->a[1])
// 				sa(stack, 1);
// 			else if (dim == 1 || (dim >= 2 && stack->b[0] > stack->b[1]) || (dim == 3 && stack->b[0] > stack->b[2]))
// 			{
// 				pa(stack, 1);
// 				dim--;
// 			}
// 			else
// 				sb(stack, 1);
// 		}
// 	}
// 	return (0);
// }

// int	quick_sort_b(t_stack *stack, int dim, int count_r)
// {
// 	int	pivot;
// 	int	numbers;

// 	if (check_sorted_desc(stack->b, dim) == 1)
// 		while (dim--)
// 			pa(stack, 1);
// 	if (dim <= 3)
// 	{
// 		sort_3_b(stack, dim);
// 		return (1);
// 	}
// 	numbers = dim;
// 	if (!median_of_numbers(&pivot, stack->b, dim))
// 		return (0);
// 	while (dim != numbers / 2)
// 	{
// 		if (stack->b[0] >= pivot && dim--)
// 			pa(stack, 1);
// 		else if (++count_r)
// 			rb(stack, 1);
// 	}
// 	while (numbers / 2 != stack->len_B && count_r--)
// 		rrb(stack, 1);
// 	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0) && quick_sort_b(stack, numbers / 2, 0));
// }

// int	quick_sort_a(t_stack *stack, int dim, int count_r)
// {
// 	int	pivot;
// 	int	numbers;

// 	if (check_sorted_asc(stack->a, dim) == 1)
// 		return (1);
// 	numbers = dim;
// 	if (dim == 3) //check cause on recursion this should be the exit
// 	{
// 		quick_sort_3_a_b(stack, dim);
// 		return (1);
// 	}
// 	if (!count_r && !median_of_numbers(&pivot, stack->a, dim))//maybe median is partition()?
// 		return (0);
// 	while (dim != numbers / 2 + numbers % 2)
// 	{
// 		if (stack->a[0] < pivot && (dim--))
// 			pb(stack, 1);
// 		else if (++count_r)
// 			ra(stack, 1);
// 	}
// 	while (numbers / 2 + numbers % 2 != stack->len_A && count_r--)
// 		rra(stack, 1);
// 	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0) && quick_sort_b(stack, numbers / 2, 0));
// 	return (1);
// }

// int	check_sorted_desc(int *stack, int dim)
// {
// 	int	i;

// 	i = 1;
// 	while (i < dim)
// 	{
// 		if (stack[i - 1] < stack[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_sorted_asc(int *stack, int dim)
// {
// 	int i;

// 	i = 1;
// 	while (i < dim)
// 	{
// 		if (stack[i - 1] > stack[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

