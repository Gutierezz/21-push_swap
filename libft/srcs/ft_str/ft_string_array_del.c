#include "libft.h"

void    ft_string_array_del(char **arr)
{
	int     i;

	i = 0;
	while (arr[i])
		i++;
	while(i >= 0)
		ft_strdel(&arr[i--]);
}

