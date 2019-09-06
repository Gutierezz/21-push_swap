#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*new_stack()
{
	t_stack	*stack;

	stack = (t_stack*)ft_memalloc(sizeof(t_stack));
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	t_node *tmp;

	tmp = NULL;
	if (stack->top != NULL)
	{
		while ((tmp = pop(stack)))
		{
			ft_memdel((void **)&tmp);
		}
	}
	ft_memdel((void **)&stack);
}

int     is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
