/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:49:10 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:28:48 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ra(t_stack *stack, int f)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->len_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	if (f == 1)
		ft_printf("ra\n");
	stack->moves++;
	return (1);
}

int	rb(t_stack *stack, int f)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->len_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	if (f == 1)
		ft_printf("rb\n");
	stack->moves++;
	return (1);
}

/*ra and rb at the same time.*/
int	rr(t_stack *stack, int f)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->len_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	i = -1;
	tmp = stack->b[0];
	while (++i < stack->len_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	if (f == 1)
		ft_printf("rr\n");
	stack->moves++;
	return (1);
}
