#include "push_swap.h"

void	exec_for_both(t_stack *a, t_stack *b, \
		void (*cmnd)(t_stack*, int, char*), char *command)
{
	cmnd(a, 1, NULL);
	cmnd(b, 1, NULL);
	if (command)
		ft_printf("%s\n", command);
}

void	push_to_dst(t_stack *src, t_stack *dst, char *command)
{
	if (!is_empty(src))
	{
		push(dst, pop(src));
		if (command)
			ft_printf("%s\n", command);
	}
}

int asc(int a, int b)
{
	return (a <= b);
}
