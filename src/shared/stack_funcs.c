#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new->data = data;
	new->color = 0;
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

int		is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

int		is_sorted(t_stack *stack, size_t len, int (*cmp)(int, int))
{
	size_t	i;
	t_node	*ptr;

	i = 0;
	ptr = stack->top;
	if (stack->size > 1 && stack->top)
	{
		while (i < (len - 1))
		{
			if (!cmp(ptr->data, ptr->next->data))
				return (0);
			ptr = ptr->next;
			i++;
		}
	}
	return (1);
}
