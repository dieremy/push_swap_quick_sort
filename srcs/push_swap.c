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
#include <time.h>

void	print_arraya(t_stack *stack, int len)
{
	int	i;

	i = -1;
	ft_printf("\n\t\tSTACK A\n\n");
	while (++i < len)
		ft_printf("%d.\t\t%d\n", i, stack->a[i]);
}

void	print_arrayb(t_stack *stack, int len)
{
	int	i;

	i = 0;
	ft_printf("\n\t\tSTACK B\n\n");
	while (i < len)
		ft_printf("\t\t%d\n", stack->b[i++]);
}

int main(int ac, char **av)
{
	t_stack	*stack;
	
	if (ac < 2)
		return (0);
	stack = init(ac, av);
	// print_arraya(stack, stack->len_A);
	// print_arrayb(stack, stack->len_B);
	// (void)ac;
	// (void)av;
	// stack = malloc(sizeof(t_stack));
	// stack->a = malloc(sizeof(int) * 500);
	// stack->b = malloc(sizeof(int) * 500);
	// int i = 0;
	// while (i < 500)
	// {
	// 	stack->a[i] = (rand() % (3000 + i));
	// 	ft_printf("(%d) %d ", i, stack->a[i]);
	// 	i++;
	// }
	// stack->len_A = i;
	// stack->len_B = 0;
	// stack->moves = 0;
	sort(stack);
	// ft_printf("\n\n=========================================\n\n");
	print_arraya(stack, stack->len_A);
	// print_arrayb(stack, stack->len_B);
	// ft_printf("\n\nmoves--> %d\n\n", stack->moves);
	ft_exit(stack);
	return (0);
}
