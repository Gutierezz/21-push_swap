#include "push_swap.h"

void	draw_console(t_stack *a, t_stack *b, int max_size)
{
	int		i;
	t_node	*a_p;
	t_node	*b_p;

	a_p = a->top;
	b_p = b->top;
	i = 0;
	ft_printf("\n");
	while (i < max_size)
	{
		if ((max_size - (int)a->size <= i) && (max_size - (int)b->size <= i) && (a_p && b_p))
		{
			ft_printf("||  %11d  |*|", a_p->data);
			ft_printf("  %11d  ||\n", b_p->data);
			a_p = a_p->next;
			b_p = b_p->next;
		}
		else if (max_size - (int)a->size <= i && a_p)
		{
			ft_printf("||  %11d  |*|", a_p->data);
			ft_printf("  %11c  ||\n", ' ');
			a_p = a_p->next;
		}
		else if (max_size - (int)b->size <= i && b_p)
		{
			ft_printf("||  %11c  |*|", ' ');
			ft_printf("  %11d  ||\n", b_p->data);
			b_p = b_p->next;
		}
		else
			ft_printf("||  %11c  |*|  %11c  ||\n", ' ',  ' ');
		i++;
	}
	ft_printf("||===============|*|===============||\n");
	ft_printf("||       A       |*|       B       ||\n");
	ft_printf("||===============|*|===============||\n");
	ft_printf("\n");
}
