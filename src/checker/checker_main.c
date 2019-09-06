/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:38:31 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/22 19:17:55 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		visual;

	if (argc == 1 || ((visual = get_visual_mode(argv[1])) && argc == 2))
		return (0);
	a = new_stack();
	b = new_stack();
	if ((i = fit_into_int(argc, argv, &arr, visual)) > 0 && !repeated_elems(arr, i))
	{
		while (--i >= 0)
			push(a, new_node(arr[i]));
		if (!read_and_exec(a, b, visual, arr))
		{
			ft_fprintf(2, "Error\n");
			return (clear_memory(a, b, arr));
		}
		(is_empty(b) && is_sorted(a, a->size, asc)) ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	else
		ft_fprintf(2, "Error\n");
	return (clear_memory(a, b, arr));
}
