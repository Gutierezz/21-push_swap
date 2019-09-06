
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "libft.h"
#include "ft_math.h"
#include "ft_printf.h"

# define WIN_WID 1080
# define WIN_HEIGHT 640
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

typedef	struct s_graphics
{
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Texture *texture;
	//  SDL_Surface	*screen;
	//  SDL_Surface *buffer;
	SDL_Rect	rect;
	bool		is_running;
	bool		is_paused;
	bool		error;
	t_stack		*a;
	t_stack		*b;
	int			max_size;
	int		width_mult;
	int		height_mult;
}				t_graphics;

/*
** valudation
*/

int			clear_memory(t_stack *a, t_stack *b, int *arr);
int			asc(int a, int b);
int			is_digit_string(const char *str);
int			handle_multiarg(int *arr, char *arg);
int			fit_into_int(int ac, char **av, int **arr, int visual);
int			repeated_elems(int *arr, int size);

/*
** checker -> execute_commands
*/

int			get_visual_mode(char *arg);
int			execute_command(t_stack *a, t_stack *b, char *command);
int			read_and_exec(t_stack *a, t_stack *b, int visual, int *arr);
int			handle_console(t_stack *a, t_stack *b, int max_size, int visual);
int			handle_graphics(t_stack *a, t_stack *b, int max_size, int *arr);
void		handle_event(SDL_Event *event, t_graphics *graph);

/*
** checker -> visualizer
*/

void		draw_console(t_stack *a, t_stack *b, int max_size);
void		draw_contour(t_graphics *graph);
void		draw_graphics(t_stack *a, t_stack *b, t_graphics *graph);
void		draw_stack(t_stack *stack, t_graphics *graph, int start);
t_graphics	*graph_init(t_stack *a, t_stack *b, int max_size, int *arr);
void		set_rect_pos(SDL_Rect *rect, int x, int y);
void		set_rect_size(SDL_Rect *rect, int w, int h);


/*
** stack_funcs
*/


t_node		*new_node(int data);
t_stack		*new_stack();
void		clear_stack(t_stack *stack);  // FIX BUGS
int			is_empty(t_stack *stack);

/*
** operations
*/

int			is_sorted(t_stack *stack, size_t len, int (*cmp)(int, int));
void		push(t_stack *stack, t_node *new_top);
t_node		*pop(t_stack *stack);
void		swap_top2(t_stack *stack, int both, char *command);
void		exec_for_both(t_stack *a, t_stack *b, \
			void (*cmnd)(t_stack*, int, char*), char *command);
void		rotate(t_stack *stack, int both, char *command);
void		rev_rotate(t_stack *stack, int both, char *command);
void		push_to_dst(t_stack *src, t_stack *dst, char *command);

/*
** stack_sort
*/
void		multi_rot_both(t_stack *a, t_stack *b, \
				t_rotation *rot, int rot_index);
void		rotate_stacks(t_stack *a, t_stack *b, t_rotation *rot);
void		push_all(t_stack *a, t_stack *b, int *max, int *arr);
t_rotation	*find_lowest_rot(t_stack *a, t_stack *b);
void		sort_stack(t_stack *a, t_stack *b, int *arr);

/*
**  sort_helpers
*/

int			*stack_to_arr(t_stack *stack);
t_rotation	*new_rotation(int a_r, int a_rr, int b_r, int b_rr);
void		mult_rot(t_stack *stack, int times, \
			void (*cmnd)(t_stack*, int, char*), char *command);
int			a_rot_count(t_stack *a, int input);
void		sort_three(t_stack *stack, int (*cmp)(int, int));

/*
**  rotation_helpers
*/

void		set_a_rot(t_rotation *rot, int a_r, int a_rr);
void		set_b_rot(t_rotation *rot, int b_r, int b_rr);
void		calc_rots(t_rotation *rot);
int			get_min_rot(t_rotation *rot);
int			get_min_rot_index(t_rotation *rot);

#endif //PUSH_SWAP_H
