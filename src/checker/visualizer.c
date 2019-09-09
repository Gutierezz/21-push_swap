#include "push_swap.h"

void		draw_contour(t_graphics *graph)
{
	SDL_Rect rect;

	SDL_SetRenderDrawColor(graph->render, 0, 149, 148, 255);
	SDL_RenderClear(graph->render);
	SDL_SetRenderDrawColor(graph->render, 0, 195, 72, 255);
	set_rect_pos(&rect, BORDER, BORDER);
	set_rect_size(&rect, WIN_WID / 2 - BORDER * 2, WIN_HEIGHT - BORDER * 2);
	SDL_RenderFillRect(graph->render, &rect);
	set_rect_pos(&rect, WIN_WID / 2 + BORDER, BORDER);
	set_rect_size(&rect, WIN_WID / 2 - BORDER * 2, WIN_HEIGHT - BORDER * 2);
	SDL_RenderFillRect(graph->render, &rect);
}

void			draw_graphics(t_stack *a, t_stack *b, t_graphics *graph)
{
	SDL_RenderClear(graph->render);
	draw_contour(graph);
	draw_stack(a, graph, 0);
	draw_stack(b, graph, WIN_WID / 2);
	SDL_RenderPresent(graph->render);
}

void			draw_stack(t_stack *stack, t_graphics *graph, int start)
{
	t_node		*ptr;
	size_t		i;
	SDL_Rect	rect;

	i = 0;
	ptr = (stack->size > 0) ? stack->top->prev : NULL;
	while (i++ < stack->size)
	{
		if (ptr->data > 0)
			SDL_SetRenderDrawColor(graph->render, 180, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(graph->render, 129, 74, 255, 255);
		set_rect_size(&rect, ABS(ptr->data) * graph->width_mult, graph->height_mult);
		set_rect_pos(&rect, start + BORDER + 5, \
		WIN_HEIGHT - BORDER - i * graph->height_mult);
		SDL_RenderFillRect(graph->render, &rect);
		ptr = ptr->prev;
	}
}

t_graphics		*graph_init(t_stack *a, t_stack *b, int max_size, int *arr)
{
	t_graphics	*graph;
	int			min;
	int			max;

	min = quick_select(arr, 0, max_size - 1, 0);
	max = quick_select(arr, 0, max_size - 1, max_size - 1);
	graph = (t_graphics*)ft_memalloc(sizeof(t_graphics));
	SDL_Init(SDL_INIT_EVERYTHING);
	graph->window = SDL_CreateWindow("PUSH SWAP", SDL_WINDOWPOS_UNDEFINED, \
	SDL_WINDOWPOS_UNDEFINED, WIN_WID, WIN_HEIGHT, 0);
	graph->render = SDL_CreateRenderer(graph->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(graph->render, WIN_WID, WIN_HEIGHT);
	graph->is_running = true;
	graph->is_paused = false;
	graph->error = false;
	graph->a = a;
	graph->b = b;
	graph->max_size = max_size;
	graph->height_mult = (WIN_HEIGHT - BORDER * 2) / max_size;
	// printf("H_SIZE %d \n", graph->height_mult);
	graph->width_mult = ((WIN_WID / 2 - 2 * BORDER) / (ABS(max) + ABS(min)));
	return (graph);
}

void	set_rect_pos(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}

void	set_rect_size(SDL_Rect *rect, int w, int h)
{
	rect->w = w;
	rect->h = h;
}
