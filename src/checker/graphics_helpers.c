/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:04:56 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/11 15:31:52 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			draw_contour(t_graphics *graph)
{
	SDL_Rect	rect;

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

void			paint_stack(t_stack *stack, int mode)
{
	t_node		*ptr;
	size_t		i;

	i = 0;
	if (is_empty(stack))
		return ;
	ptr = stack->top;
	while (i < stack->size)
	{
		if ((mode == 1 || mode == 3) && i == 0)
			ptr->color = 1;
		else if ((mode == 2) && i == 1)
			ptr->color = 1;
		else if ((mode == 4) && i + 1 == stack->size)
			ptr->color = 1;
		else
			ptr->color = 0;
		ptr = ptr->next;
		i++;
	}
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
		if (ptr->color)
			SDL_SetRenderDrawColor(graph->render, 255, 0, 0, 255);
		else if (ptr->data > 0)
			SDL_SetRenderDrawColor(graph->render, 180, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(graph->render, 129, 74, 255, 255);
		set_rect_size(&rect, (ABS(ptr->data) ? \
		ABS(ptr->data) * graph->width_mult : 5), graph->height_mult);
		set_rect_pos(&rect, start + BORDER + 5, \
		WIN_HEIGHT - BORDER - i * graph->height_mult);
		SDL_RenderFillRect(graph->render, &rect);
		ptr = ptr->prev;
	}
}

void			set_rect_pos(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}

void			set_rect_size(SDL_Rect *rect, int w, int h)
{
	rect->w = w;
	rect->h = h;
}
