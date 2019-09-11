/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:32:13 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 15:12:45 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack *stack, t_node *new_top)
{
	if (is_empty(stack))
	{
		stack->top = new_top;
		new_top->prev = new_top;
		new_top->next = new_top;
	}
	else
	{
		new_top->prev = stack->top->prev;
		new_top->prev->next = new_top;
		new_top->next = stack->top;
		stack->top->prev = new_top;
		stack->top = new_top;
	}
	stack->size++;
}

t_node		*pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp == NULL)
		return (tmp);
	stack->size--;
	if (stack->size == 0)
	{
		tmp = new_node(stack->top->data);
		ft_memdel((void**)&(stack->top));
		return (tmp);
	}
	stack->top = tmp->next;
	stack->top->prev = tmp->prev;
	tmp->prev->next = stack->top;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void		swap_top2(t_stack *stack, int both, char *command)
{
	int		tmp;

	if (stack->top && stack->size > 1)
	{
		tmp = stack->top->next->data;
		stack->top->next->data = stack->top->data;
		stack->top->data = tmp;
		if (!both && command)
			ft_printf("%s\n", command);
	}
}

void		rotate(t_stack *stack, int both, char *command)
{
	if (stack->top && stack->size > 1)
	{
		stack->top = stack->top->next;
		if (!both && command)
			ft_printf("%s\n", command);
	}
}

void		rev_rotate(t_stack *stack, int both, char *command)
{
	if (stack->top && stack->size > 1)
	{
		stack->top = stack->top->prev;
		if (!both && command)
			ft_printf("%s\n", command);
	}
}
