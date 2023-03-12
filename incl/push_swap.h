/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:46:15 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:41:22 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	moves;
}				t_stack;

t_stack	*init(int ac, char **av);
void	fill_stack(int ac, char **av, int i, t_stack *stack);
void	print_arraya(t_stack *stack, int len);
void	tmp_sort(int *tmp_stk, int dim);
void	check_doubles(int *a, int dim);
void	lil_sort(t_stack *stack);
void	ft_exit(t_stack *stack);
void	print_error(int *stack);
int		quick_sort_a(t_stack *stack, int dim, int count_r);
int		quick_sort_b(t_stack *stack, int dim, int count_r);
int		when_push(t_stack *stack, int dim, int f);
int		check_sorted_desc(int *stack, int dim);
int		check_sorted_asc(int *stack, int dim);
int		ft_atoi(char *str, int *stack);
int		rrr(t_stack *stack, int f);
int		rrb(t_stack *stack, int f);
int		rra(t_stack *stack, int f);
int		sa(t_stack *stack, int f);
int		sb(t_stack *stack, int f);
int		ss(t_stack *stack, int f);
int		pb(t_stack *stack, int f);
int		pa(t_stack *stack, int f);
int		ra(t_stack *stack, int f);
int		rb(t_stack *stack, int f);
int		rr(t_stack *stack, int f);
int		sort(t_stack *stack);

#endif
