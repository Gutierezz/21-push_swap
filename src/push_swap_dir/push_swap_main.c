/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:19:49 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/22 19:48:03 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	arr = NULL;
	if (argc == 1)
		return (0);
	a = new_stack();
	b = new_stack();
	if ((i = fit_into_int(argc, argv, &arr, 0)) > 0 && !repeated_elems(arr, i))
	{
		while (--i >= 0)
			push(a, new_node(arr[i]));
		sort_stack(a, b, arr);
	}
	else
		ft_fprintf(2, "Error\n");
	return (clear_memory(a, b, arr));
}
