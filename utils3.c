/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:26:22 by maggie            #+#    #+#             */
/*   Updated: 2023/08/12 02:39:53 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_top(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	if (cheapest->action == UPUP)
		ft_rtop(head_a, head_b, cheapest);
	else if (cheapest->action == DOWNDOWN)
		ft_rrtop(head_a, head_b, cheapest);
	else if (cheapest->action == UPDOWN)
		ft_updown(head_a, head_b, cheapest);
	else
		ft_downup(head_a, head_b, cheapest);
}

void	ft_downup(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	size_t	downcost_a;
	size_t	upcost_b;

	downcost_a = cheapest->tar->down_cost;
	upcost_b = cheapest->up_cost;
	while (downcost_a-- > 0)
		ft_rra(head_a);
	while (upcost_b-- > 0)
		ft_rb(head_b);
}

/* 	if ((ch->section == TOP && ch->tar->section == TOP) || \
	(ch->section == TOP && ch->tar->section == MIDDLE) || \
	(ch->tar->section == TOP && ch->section == MIDDLE) || \
	(ch->section == MIDDLE && ch->tar->section == MIDDLE))
		ft_rtop(h_a, h_b, ch);
	else if ((ch->section == BOTTOM && ch->tar->section == BOTTOM) || \
	(ch->section == MIDDLE && ch->tar->section == BOTTOM) || \
	(ch->section == BOTTOM && ch->tar->section == MIDDLE))
		ft_rrtop(h_a, h_b, ch);
	else if ((ch->tar->cost + ch->cost > ch->reverse_cost && \
	ch->section == TOP))
		ft_rrtop(h_a, h_b, ch);
	else if (ch->tar->cost + ch->cost > ch->tar->reverse_cost && \
	ch->section == BOTTOM)
		ft_rrtop(h_a, h_b, ch);
	else if (ch->tar->cost + ch->cost > ch->tar->reverse_cost && \
	ch->section == TOP)
		ft_rtop(h_a, h_b, ch);
	else if (ch->tar->cost + ch->cost > ch->reverse_cost && \
	ch->section == BOTTOM)
		ft_rtop(h_a, h_b, ch);
	else
		ft_dif(h_a, h_b, ch); */
