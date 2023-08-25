/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:00 by mvalerio          #+#    #+#             */
/*   Updated: 2023/08/11 19:03:53 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_biggest(size_t args, ...)
{
	va_list	list;
	size_t	biggest;
	size_t	compare;

	va_start (list, args);
	biggest = va_arg(list, size_t);
	while (--args > 0)
	{
		compare = va_arg(list, size_t);
		if (compare > biggest)
			biggest = compare;
	}
	return (biggest);
}

size_t	ft_smallest(size_t args, ...)
{
	va_list	list;
	size_t	smallest;
	size_t	compare;

	va_start (list, args);
	smallest = va_arg(list, size_t);
	while (--args > 0)
	{
		compare = va_arg(list, size_t);
		if (compare < smallest)
			smallest = compare;
	}
	return (smallest);
}

void	ft_total_cost(t_list *head_b)
{
	size_t	up;
	size_t	down;
	size_t	updown;
	size_t	downup;

	while (head_b)
	{
		up = ft_biggest(2, head_b->up_cost, head_b->tar->up_cost);
		down = ft_biggest(2, head_b->down_cost, head_b->tar->down_cost);
		updown = head_b->tar->up_cost + head_b->down_cost;
		downup = head_b->tar->down_cost + head_b->up_cost;
		head_b->total_cost = ft_smallest(4, up, down, updown, downup);
		if (head_b->total_cost == up)
			head_b->action = UPUP;
		else if (head_b->total_cost == down)
			head_b->action = DOWNDOWN;
		else if (head_b->total_cost == updown)
			head_b->action = UPDOWN;
		else if (head_b->total_cost == downup)
			head_b->action = DOWNUP;
		head_b = head_b->next;
	}
}

void	ft_smallest_bigger(t_list *i_a, t_list *head_b)
{
	while (i_a)
	{
		if (*(int *)(i_a->content) < *(int *)(head_b->tar->content) && \
			*(int *)(i_a->content) > *(int *)(head_b->content))
			head_b->tar = i_a;
		i_a = i_a->next;
	}
}

void	ft_set_targets(t_list *head_a, t_list *head_b)
{
	t_list	*i_a;

	while (head_b)
	{
		i_a = head_a;
		head_b->tar = ft_lst_smallest(head_a);
		if (*(int *)(head_b->tar->content) > (*(int *)(head_b->content)))
		{
			head_b = head_b->next;
			continue ;
		}
		while (i_a)
		{
			if (*(int *)(i_a->content) < *(int *)(head_b->content))
				i_a = i_a->next;
			else
			{
				head_b->tar = i_a;
				i_a = i_a->next;
				ft_smallest_bigger(i_a, head_b);
				break ;
			}
		}
		head_b = head_b->next;
	}
}
