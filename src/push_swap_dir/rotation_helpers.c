#include "push_swap.h"

void set_a_rot(t_rotation *rot, int a_r, int a_rr)
{
	rot->a_r = a_r;
	rot->a_rr = a_rr;
}

void set_b_rot(t_rotation *rot, int b_r, int b_rr)
{
	rot->b_r = b_r;
	rot->b_rr = b_rr;
}

void calc_rots(t_rotation *rot)
{
	rot->arr[rboth] = (rot->a_r > rot->b_r) ? rot->a_r : rot->b_r;
	rot->arr[rrboth] = (rot->a_rr > rot->b_rr) ? rot->a_rr : rot->b_rr;
	rot->arr[ar_brr] = rot->a_r + rot->b_rr;
	rot->arr[arr_br] =  rot->a_rr + rot->b_r;
}

int  get_min_rot(t_rotation *rot)
{
	int min;
	int i;

	i = 0;
	min = rot->arr[i];
	while (++i < 4)
	{
		if (rot->arr[i] < min)
			min = rot->arr[i];
	}
	return (min);
}

int get_min_rot_index(t_rotation *rot)
{
	int min;
	int i;

	i = 0;
	min = i;
	while (++i < 4)
	{
		if (rot->arr[i] < rot->arr[min])
			min = i;
	}
	return (min);
}


