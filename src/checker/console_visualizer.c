#include "push_swap.h"

void	draw_console(t_stack *a, t_stack *b, int max_size)
{
	int		i;
	t_node	*a_p;
	t_node	*b_p;
	int		mode;

	a_p = (a->top != NULL) ? a->top : NULL;
	b_p = (b->top != NULL) ? b->top : NULL;
	i = 0;
	ft_printf("\n");
	while (i < max_size)
	{
		mode = level_mode((int)a->size, (int)b->size, i, (int)max_size);
		draw_level((a_p ? a_p->data : 0), (b_p ? b_p->data : 0), mode);
		a_p = (mode == 1 || mode == 3) ? a_p->next : a_p;
		b_p = (mode == 2 || mode == 3) ? b_p->next : b_p;
		i++;
	}
	ft_printf("||===============|*|===============||\n");
	ft_printf("||       A       |*|       B       ||\n");
	ft_printf("||===============|*|===============||\n");
	ft_printf("\n");
}

void	draw_level(int a_val, int b_val, int mode)
{
	if (mode == 3)
		ft_printf("||  %11d  |*|  %11d  ||\n", a_val, b_val);
	else if (mode == 1)
		ft_printf("||  %11d  |*|  %11c  ||\n", a_val, ' ');
	else if (mode == 2)
		ft_printf("||  %11c  |*|  %11d  ||\n", ' ', b_val);
	else
		ft_printf("||  %11c  |*|  %11c  ||\n", ' ',  ' ');
}

int	level_mode(int a_size, int b_size, int i, int max_size)
{
	if ((max_size - i <= a_size && max_size - i <= b_size))
		return (3);
	else if (max_size - i <= a_size && a_size > 0)
		return (1);
	else if (max_size - i <=  b_size && b_size > 0)
		return (2);
	else
		return (0);
}

int			console_draw_mode(t_stack *a, t_stack *b, int max_size)
 {
	char	*command;
	int		brd;

	brd = 0;
	command = NULL;
	while ((brd = get_next_line(0, &command)) > 0)
	{
		if (!execute_command(a, b, command))
		{
			ft_strdel(&command);
			return (0);
		}
		ft_strdel(&command);
		draw_console(a, b, max_size);
	}
	return (1);
 }
