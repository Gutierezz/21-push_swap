/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:09:27 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:10:17 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_round(double x)
{
	double	y;
	double	r;

	y = ft_floor(x);
	r = x - y;
	if (r > 0.5f)
		y += 1.0f;
	if (r == 0.5f)
	{
		r = y - 2.0f * ft_floor(0.5f * y);
		if (r == 1.0f)
			y += 1.0f;
	}
	return ((long long)y);
}
