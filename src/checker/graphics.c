#include "push_swap.h"

int graphics_mode(t_stack *a, t_stack *b, int max_size, int *arr)
 {
	t_graphics	*graph;
	char		**cmmnds;
	int			ret;
	int			error;

	error = 0;
	ret = 0;
	graph = NULL;
	if ((cmmnds = read_commands(&error)))
	{
		graph = graph_init(a, b, max_size, arr);
		ret = graphics_loop(graph, cmmnds);
		SDL_DestroyWindow(graph->window);
		SDL_Quit();
		ft_memdel((void**)&graph);
		ft_string_array_del(cmmnds);
		free(cmmnds);
	}
	return (ret);
 }

int		graphics_loop(t_graphics *graph, char **cmmnds)
{
	SDL_Event	event;
	int			i;

	i = 0;
	while (graph->is_running)
	{
		if (!graph->is_paused)
		{
			event.type = SDL_KEYDOWN;
    		event.key.keysym.sym = SDLK_RIGHT;
			SDL_PushEvent(&event);
		}
		while (SDL_PollEvent(&event))
				handle_event(&event, graph, cmmnds, &i);
		if (graph->error)
			return (0);
		draw_graphics(0, 0, graph, 1);
		if (!graph->is_paused)
	 		SDL_Delay(200);
	}
	return (1);
}

void 	handle_event(SDL_Event *event, t_graphics *graph, char **cmmnds, int *i)
{
	int	a_mode;
	int	b_mode;

	if (event->type == SDL_QUIT)
		graph->is_running = false;
	else if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			graph->is_running = false;
		else if (event->key.keysym.sym == SDLK_SPACE)
			graph->is_paused = (graph->is_paused ? false : true);
		else if (event->key.keysym.sym == SDLK_RIGHT && cmmnds[*i])
		{
			color_mode(cmmnds[*i], &a_mode, &b_mode);
			draw_graphics(a_mode, b_mode, graph, 1);
			if (!execute_command(graph->a, graph->b, cmmnds[*i]))
				graph->error = true;
			draw_graphics(a_mode, b_mode, graph, 0);
			(*i)++;
		}
	}
}

void	draw_graphics(int a_mode, int b_mode, t_graphics *graph, int repaint)
{
	if (repaint)
	{
		paint_stack(graph->a, a_mode);
		paint_stack(graph->b, b_mode);
	}
	SDL_RenderClear(graph->render);
	draw_contour(graph);
	draw_stack(graph->a, graph, 0);
	draw_stack(graph->b, graph, WIN_WID / 2);
	SDL_RenderPresent(graph->render);
	SDL_Delay(200);
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
