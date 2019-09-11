/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:11:56 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 15:12:07 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color_mode(char *cmmnd, int *a_mode, int *b_mode)
{
	*a_mode = 0;
	*b_mode = 0;
	if (ft_strequ(cmmnd, "pa"))
		*b_mode = 1;
	if (ft_strequ(cmmnd, "pb"))
		*a_mode = 1;
	if (ft_strequ(cmmnd, "sa") || ft_strequ(cmmnd, "ss"))
		*a_mode = 2;
	if (ft_strequ(cmmnd, "sb") || ft_strequ(cmmnd, "ss"))
		*b_mode = 2;
	if (ft_strequ(cmmnd, "ra") || ft_strequ(cmmnd, "rr"))
		*a_mode = 3;
	if (ft_strequ(cmmnd, "rb") || ft_strequ(cmmnd, "rr"))
		*b_mode = 3;
	if (ft_strequ(cmmnd, "rra") || ft_strequ(cmmnd, "rrr"))
		*a_mode = 4;
	if (ft_strequ(cmmnd, "rrb") || ft_strequ(cmmnd, "rrr"))
		*b_mode = 4;
}

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

int		asc(int a, int b)
{
	return (a <= b);
}
