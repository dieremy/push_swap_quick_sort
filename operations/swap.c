#include "../incl/push_swap.h"

/*swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.*/
int	sa(t_stack *stack, int f)
{
	int		tmp;
	
    if(!stack->a[0] || !stack->a[1])
        return (0);
    tmp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = tmp;
	if (f == 1)
	{
		stack->moves++;
		ft_printf("sa\n");
	}
	return (1);
}

/*swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.*/
int	sb(t_stack *stack, int f)
{
	int		tmp;
	
	if (!stack->b[0] || !stack->b[1])
		return (0);
	tmp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = tmp;
	if (f == 1)
	{
		stack->moves++;
		ft_printf("sb\n");
	}
	return (1);
}

/*sa and sb at the same time.*/
int	ss(t_stack *stack, int f)
{
    int tmp;
    
	if(!stack->a[0] || !stack->a[1] || !stack->b[0] || !stack->b[1])
        return (0);
    tmp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = tmp;
    tmp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = tmp;
	if (f == 1)
	{
		stack->moves++;
		ft_printf("ss\n");
	}
	return (1);
}