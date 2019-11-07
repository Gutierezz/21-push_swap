/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:03:54 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 16:07:30 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "SDL.h"
# include <stdbool.h>
# include "libft.h"
# include "ft_math.h"
# include "ft_printf.h"

# define WIN_WID 800
# define WIN_HEIGHT 600
# define BORDER 20

# define DATA(node) node->data
# define N_DATA(node) node->next->data
# define P_DATA(node) node->prev->data
# define SVAL(stack) stack->top->data
# define N_SVAL(stack) stack->top->next->data
# define NN_SVAL(stack) stack->top->next->next->data
# define P_SVAL(stack) stack->top->prev->data

typedef struct		s_node
{
	int				data;
	int				color;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef enum		e_enum
{
	rboth = 0,
	ar_brr = 1,
	arr_br = 2,
	rrboth = 3
}					t_enum;

typedef struct		s_stack
{
	t_node			*top;
	size_t			size;
}					t_stack;

typedef struct		s_rotation
{
	int				a_r;
	int				a_rr;
	int				b_r;
	int				b_rr;
	int				arr[4];
}					t_rotation;

typedef	struct		s_graphics
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Texture		*texture;
	SDL_Rect		rect;
	bool			is_running;
	bool			is_paused;
	bool			error;
	t_stack			*a;
	t_stack			*b;
	int				max_size;
	int				width_mult;
	int				height_mult;
}					t_graphics;

/*
** valudation  +
*/

int					clear_memory(t_stack *a, t_stack *b, int *arr);
int					is_digit_string(const char *str);
int					handle_multiarg(int *arr, char *arg);
int					fit_into_int(int ac, char **av, int **arr, int visual);
int					repeats(int *arr, int size);

/*
** checker -> execute_commands
*/

int					get_visual_mode(char *arg);
int					execute_command(t_stack *a, t_stack *b, char *command);
int					read_and_exec(t_stack *a, t_stack *b, int visual, int *arr);
char				**read_commands(int *error);
int					basic_mode(t_stack *a, t_stack *b);

/*
** checker -> graphics
*/

int					graphics_mode(t_stack *a, t_stack *b, int max_size, \
						int *arr);
int					graphics_loop(t_graphics *graph, char **cmmnds);
void				handle_event(SDL_Event *event, t_graphics *graph, \
						char **cmmnds, int *i);
void				draw_graphics(int a_mode, int b_mode, t_graphics *graph, \
						int repaint);
t_graphics			*graph_init(t_stack *a, t_stack *b, int max_size, int *arr);

/*
** checker -> graphics_helpers
*/

void				draw_contour(t_graphics *graph);
void				draw_stack(t_stack *stack, t_graphics *graph, int start);
void				color_mode(char *cmmnd, int *a_mode, int *b_mode);
void				paint_stack(t_stack *stack, int mode);
void				set_rect_pos(SDL_Rect *rect, int x, int y);
void				set_rect_size(SDL_Rect *rect, int w, int h);

/*
** checker -> console_visualizer
*/

void				draw_console(t_stack *a, t_stack *b, int max_size);
void				draw_level(int a_val, int b_val, int mode);
int					level_mode(int a_size, int b_size, int i, int max_size);
int					console_draw_mode(t_stack *a, t_stack *b, int max_size);

/*
** stack_funcs  +
*/

t_node				*new_node(int data);
t_stack				*new_stack(void);
void				clear_stack(t_stack *stack);
int					is_empty(t_stack *stack);
int					is_sorted(t_stack *stack, size_t len, int (*cmp)(int, int));

/*
** operations	+
*/

void				push(t_stack *stack, t_node *new_top);
t_node				*pop(t_stack *stack);
void				swap_top2(t_stack *stack, int both, char *command);
void				rotate(t_stack *stack, int both, char *command);
void				rev_rotate(t_stack *stack, int both, char *command);

/*
** more_operations	+
*/

void				exec_for_both(t_stack *a, t_stack *b, \
					void (*cmnd)(t_stack*, int, char*), char *command);
void				push_to_dst(t_stack *src, t_stack *dst, char *command);
int					asc(int a, int b);

/*
** stack_sort	+
*/

void				multi_rot_both(t_stack *a, t_stack *b, \
					t_rotation *rot, int rot_index);
void				rotate_stacks(t_stack *a, t_stack *b, t_rotation *rot);
void				push_all(t_stack *a, t_stack *b, int *max, int *arr);
t_rotation			*find_lowest_rot(t_stack *a, t_stack *b);
void				sort_stack(t_stack *a, t_stack *b, int *arr);

/*
**  sort_helpers	+
*/

int					*stack_to_arr(t_stack *stack);
t_rotation			*new_rotation(int a_r, int a_rr, int b_r, int b_rr);
void				mult_rot(t_stack *stack, int times, \
					void (*cmnd)(t_stack*, int, char*), char *command);
int					a_rot_count(t_stack *a, int input);
void				sort_three(t_stack *stack, int (*cmp)(int, int));

/*
**  rotation_helpers	+
*/

void				calc_rots(t_rotation *rot);
int					get_min_rot(t_rotation *rot);
int					get_min_rot_index(t_rotation *rot);

#endif
