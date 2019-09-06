#include "push_swap.h"

void	multi_rot_both(t_stack *a, t_stack *b, t_rotation *rot, int rot_index)
{
	int i;

	i = -1;
	if (rot_index == rboth)
	{
		while (++i < rot->a_r && i < rot->b_r)
			exec_for_both(a, b, rotate, "rr");
		(rot->a_r > rot->b_r) ? mult_rot(a, rot->a_r - i, rotate, "ra") : \
								mult_rot(b, rot->b_r - i, rotate, "rb");
	}
	if (rot_index == rrboth)
	{
		while (++i < rot->a_rr && i < rot->b_rr)
			exec_for_both(a, b, rev_rotate, "rrr");
		(rot->a_rr > rot->b_rr) ? mult_rot(a, rot->a_rr - i, rev_rotate, "rra") : \
								  mult_rot(b, rot->b_rr - i, rev_rotate, "rrb");
	}
}

void    rotate_stacks(t_stack *a, t_stack *b, t_rotation *rot)
{
	int rot_index;

	rot_index = get_min_rot_index(rot);
	if (rot_index == rboth || rot_index == rrboth)
		multi_rot_both(a, b, rot, rot_index);
	if (rot_index == ar_brr)
	{
		mult_rot(a, rot->a_r, rotate, "ra");
		mult_rot(b, rot->b_rr, rev_rotate, "rrb");
	}
	if (rot_index == arr_br)
	{
		mult_rot(a, rot->a_rr, rev_rotate, "rra");
		mult_rot(b, rot->b_r, rotate, "rb");
	}
}

void    push_all(t_stack *a, t_stack *b, int *max, int *arr)
{
	int min;

	min = quick_select(arr, 0, a->size - 1, 0);
	*max = quick_select(arr, 0, a->size - 1, a->size - 1);
	while (a->size > 3)
	{
		if (is_sorted(a, a->size, asc))
			break ;
		if (SVAL(a) == *max || SVAL(a) == min)
			rotate(a, 0, "ra");
		else
			push_to_dst(a, b, "pb");
	}
}

t_rotation *find_lowest_rot(t_stack *a, t_stack *b)
{
	t_node *ptr;
	t_rotation *lowest_rot;
	t_rotation tmp;
	size_t i;
	int a_r;

	i = 0;
	ptr = b->top;
	a_r = a_rot_count(a, DATA(ptr));
	lowest_rot = new_rotation(a_r, a->size - a_r, i, b->size - i);
	while (++i < b->size)
	{
		ptr = ptr->next;
		a_r = a_rot_count(a, DATA(ptr));
		set_a_rot(&tmp, a_r, a->size - a_r);
		set_b_rot(&tmp, i, b->size - i);
		calc_rots(&tmp);
		if (get_min_rot(&tmp) < get_min_rot(lowest_rot))
		{
			set_a_rot(lowest_rot, tmp.a_r, tmp.a_rr);
			set_b_rot(lowest_rot, tmp.b_r, tmp.b_rr);
			calc_rots(lowest_rot);
		}
	}
	return (lowest_rot);
}

void    sort_stack(t_stack *a, t_stack *b, int *arr)
{
	t_rotation *rot;
	int max;
	int end_rot;

	if (is_sorted(a, a->size, asc))
		return ;
	push_all(a, b, &max, arr);
	if (a->size < 4)
		sort_three(a, asc);
	while (!is_empty(b))
	{
		rot = find_lowest_rot(a, b);
		rotate_stacks(a, b, rot);
		push_to_dst(b, a, "pa");
		ft_memdel((void**)&rot);
	}
	end_rot = a_rot_count(a, max) + 1;
	if ((int)a->size - end_rot < end_rot)
	{
		end_rot = (int)(a->size - end_rot);
		mult_rot(a, end_rot, rev_rotate, "rra");
	}
	else
		mult_rot(a, end_rot, rotate, "ra");
}
