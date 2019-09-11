/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:07:39 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 15:07:41 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_rots(t_rotation *rot)
{
	rot->arr[rboth] = (rot->a_r > rot->b_r) ? rot->a_r : rot->b_r;
	rot->arr[rrboth] = (rot->a_rr > rot->b_rr) ? rot->a_rr : rot->b_rr;
	rot->arr[ar_brr] = rot->a_r + rot->b_rr;
	rot->arr[arr_br] = rot->a_rr + rot->b_r;
}

int		get_min_rot(t_rotation *rot)
{
	int	min;
	int	i;

	i = 0;
	min = rot->arr[i];
	while (++i < 4)
	{
		if (rot->arr[i] < min)
			min = rot->arr[i];
	}
	return (min);
}

int		get_min_rot_index(t_rotation *rot)
{
	int	min;
	int	i;

	i = 0;
	min = i;
	while (++i < 4)
	{
		if (rot->arr[i] < rot->arr[min])
			min = i;
	}
	return (min);
}
