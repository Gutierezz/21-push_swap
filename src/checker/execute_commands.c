/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:34:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/12 18:47:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_visual_mode(char *arg)
{
	if (ft_strequ(arg, "-v"))
		return (1);
	else if (ft_strequ(arg, "-gv"))
		return (2);
	return (0);
}

int		execute_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		swap_top2(a, 0, NULL);
	else if (!ft_strcmp(command, "sb"))
		swap_top2(b, 0, NULL);
	else if (!ft_strcmp(command, "ss"))
		exec_for_both(a, b, swap_top2, NULL);
	else if (!ft_strcmp(command, "ra"))
		rotate(a, 0, NULL);
	else if (!ft_strcmp(command, "rb"))
		rotate(b, 0, NULL);
	else if (!ft_strcmp(command, "rr"))
		exec_for_both(a, b, rotate, NULL);
	else if (!ft_strcmp(command, "rra"))
		rev_rotate(a, 0, NULL);
	else if (!ft_strcmp(command, "rrb"))
		rev_rotate(b, 0, NULL);
	else if (!ft_strcmp(command, "rrr"))
		exec_for_both(a, b, rev_rotate, NULL);
	else if (!ft_strcmp(command, "pa"))
		push_to_dst(b, a, NULL);
	else if (!ft_strcmp(command, "pb"))
		push_to_dst(a, b, NULL);
	else
		return (0);
	return (1);
}

int		read_and_exec(t_stack *a, t_stack *b, int visual, int *arr)
{
	int		max_size;

	max_size = (int)a->size;
	if (visual == 2)
		return (handle_graphics(a, b, max_size, arr));
	else
		return (handle_console(a, b, max_size, visual));
}

int handle_console(t_stack *a, t_stack *b, int max_size, int visual)
{
	char	*command;
	int		brd;

	brd = 0;
	command = NULL;
	while ((brd = get_next_line(0, &command)) > 0)
	{
		if (execute_command(a, b, command))
		{
			if (visual == 1)
				draw_console(a, b, max_size);
			ft_strdel(&command);
		}
		else
		{
			ft_strdel(&command);
			return (0);
		}
	}
	return (1);
}

 int handle_graphics(t_stack *a, t_stack *b, int max_size, int *arr)
 {
	t_graphics	*graph;
	SDL_Event	event;
	char	*command;
	int		brd;

	brd = 0;
	command = NULL;
	graph = graph_init(a, b, max_size, arr);
	while (graph->is_running)
	{
		if (!graph->is_paused)
		{
			if ((brd = get_next_line(0, &command)) > 0)
			{
				if (!execute_command(a, b, command))
				{
					graph->is_running = false;
					graph->error = true;
				}
			}
			else
				graph->is_running = false;
		}
		while (SDL_PollEvent(&event))
			handle_event(&event, graph);
		draw_graphics(a, b, graph);
		ft_strdel(&command);
		if (!graph->is_paused)
	 		SDL_Delay(75);
	}
	SDL_DestroyWindow(graph->window);
	SDL_Quit();
	return (graph->error ? 0 : 1);
 }

void 	handle_event(SDL_Event *event, t_graphics *graph)
{
	if (event->type == SDL_QUIT)
	{
		graph->is_running = false;
	}
	else if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			graph->is_running = false;
		else if (event->key.keysym.sym == SDLK_SPACE)
			graph->is_paused = (graph->is_paused ? false : true);
	}
}
