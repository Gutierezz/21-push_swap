/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:32:41 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 17:02:28 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			clear_memory(t_stack *a, t_stack *b, int *arr)
{
	clear_stack(a);
	clear_stack(b);
	ft_memdel((void**)&arr);
	return (0);
}

int			is_digit_string(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			handle_multiarg(int *arr, char *arg)
{
	int			i;
	int			arg_count;
	char		**split;
	long long	tmp;

	i = -1;
	arg_count = ft_countwords(arg, ' ');
	split = ft_strsplit(arg, ' ');
	while (++i < arg_count)
	{
		if (!is_digit_string(split[i]) || (ft_strlen(split[i]) > 11))
			break ;
		if ((tmp = ft_atoll(split[i])) < INT_MIN || tmp > INT_MAX)
			break ;
		*(arr + i) = (int)tmp;
	}
	ft_string_array_del(split);
	free(split);
	return (i < arg_count ? -1 : arg_count);
}

int			fit_into_int(int ac, char **av, int **arr, int visual)
{
	int			ret;
	int			i;
	int			ptr_offs;
	int			size;

	ret = 0;
	ptr_offs = 0;
	size = 0;
	i = 1 + (visual > 0 ? 1 : 0);
	while (i < ac)
		size += ft_countwords(av[i++], ' ');
	*arr = (int*)ft_memalloc(sizeof(int) * size);
	i = 1 + (visual > 0 ? 1 : 0);
	while (i < ac)
	{
		ret = handle_multiarg((*arr + ptr_offs), av[i++]);
		if (ret <= 0)
			return (-1);
		ptr_offs += ret;
	}
	return (size);
}

int			repeats(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i + 1 < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[j] == arr[i])
				return (1);
		}
		i++;
	}
	return (0);
}
