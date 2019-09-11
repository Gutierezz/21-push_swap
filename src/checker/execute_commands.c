/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:34:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 15:15:28 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_visual_mode(char *arg)
{
	if (ft_strequ(arg, "-v"))
		return (1);
	else if (ft_strequ(arg, "-gv"))
		return (2);
	return (0);
}

int			execute_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		swap_top2(a, 0, NULL);
	else if (!ft_strcmp(command, "sb"))
		swap_top2(b, 0, NULL);
	else if (!ft_strcmp(command, "ss"))
		exec_for_both(a, b, swap_top2, NULL);
	else if (!ft_strcmp(command, "ra"))
		rotate(a, 0, NULL);
	else if (!ft_strcmp(command, "rb"))
		rotate(b, 0, NULL);
	else if (!ft_strcmp(command, "rr"))
		exec_for_both(a, b, rotate, NULL);
	else if (!ft_strcmp(command, "rra"))
		rev_rotate(a, 0, NULL);
	else if (!ft_strcmp(command, "rrb"))
		rev_rotate(b, 0, NULL);
	else if (!ft_strcmp(command, "rrr"))
		exec_for_both(a, b, rev_rotate, NULL);
	else if (!ft_strcmp(command, "pa"))
		push_to_dst(b, a, NULL);
	else if (!ft_strcmp(command, "pb"))
		push_to_dst(a, b, NULL);
	else
		return (0);
	return (1);
}

int			read_and_exec(t_stack *a, t_stack *b, int visual, int *arr)
{
	int		max_size;

	max_size = (int)a->size;
	if (visual == 1)
		return (console_draw_mode(a, b, max_size));
	if (visual == 2)
		return (graphics_mode(a, b, max_size, arr));
	else
		return (basic_mode(a, b));
}

char		**read_commands(int *error)
{
	char	*line;
	char	*cmmnds_string;
	char	**cmmnds;
	int		brd;
	int		i;

	i = 0;
	line = NULL;
	cmmnds_string = NULL;
	while ((brd = get_next_line(0, &line)) > 0)
	{
		if (ft_strlen(line) == 0)
			*error = 1;
		cmmnds_string = ft_str_gapjoin_free(&cmmnds_string, &line, '\n');
		i++;
	}
	if (i > 0)
		cmmnds = ft_strsplit(cmmnds_string, '\n');
	ft_strdel(&cmmnds_string);
	return ((i > 0 && !(*error)) ? cmmnds : NULL);
}

int			basic_mode(t_stack *a, t_stack *b)
{
	int		i;
	char	**cmmnds;
	int		error;

	error = 0;
	i = -1;
	if ((cmmnds = read_commands(&error)))
	{
		while (cmmnds[++i])
		{
			if (!execute_command(a, b, cmmnds[i]))
			{
				ft_string_array_del(cmmnds);
				free(cmmnds);
				return (0);
			}
		}
		ft_string_array_del(cmmnds);
		free(cmmnds);
		return (1);
	}
	return (0);
}
