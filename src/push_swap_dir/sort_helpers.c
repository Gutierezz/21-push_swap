#include "push_swap.h"

int		*stack_to_arr(t_stack *stack)
{
	int		*arr;
	t_node	*top;
	size_t	i;

	i = 0;
	top = stack->top;
	arr = (int*)ft_memalloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		arr[i++] = top->data;
		top = top->next;
	}
	return (arr);
}

t_rotation *new_rotation(int a_r, int a_rr, int b_r, int b_rr)
{
	t_rotation *new_rot;

	new_rot = (t_rotation*)ft_memalloc(sizeof(t_rotation));
	new_rot->a_r = a_r;
	new_rot->a_rr = a_rr;
	new_rot->b_r = b_r;
	new_rot->b_rr = b_rr;
	calc_rots(new_rot);
	return (new_rot);
}

void    mult_rot(t_stack *stack, int times, \
		void (*cmnd)(t_stack*, int, char*), char *command)
{
	while (times--)
		cmnd(stack, 0, command);
}

int     a_rot_count(t_stack *a, int input)
{
	t_node *tmp;
	int     rot;

	rot = 0;
	tmp = a->top;
	while (!(P_DATA(tmp) < input && DATA(tmp) >= input))
	{
		tmp = tmp->next;
		rot++;
	}
	return (rot);
}

void    sort_three(t_stack *stack, int (*cmp)(int, int))
{
	size_t len;

	len = stack->size;
	if (is_sorted(stack, len, cmp))
		return ;
	if (len == 2)
		swap_top2(stack, 0, "sa");
	if (len == 3)
	{
		if (!cmp(SVAL(stack), N_SVAL(stack)))
		{
			if (!cmp(SVAL(stack), P_SVAL(stack)))
				rotate(stack, 0, "ra");
			else
				swap_top2(stack, 0, "sa");
		}
		else
			rev_rotate(stack, 0, "rra");
		if (!cmp(SVAL(stack), N_SVAL(stack)))
			swap_top2(stack, 0, "sa");
	}
}
