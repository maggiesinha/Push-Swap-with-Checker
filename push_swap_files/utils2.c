/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:37:02 by mvalerio          #+#    #+#             */
/*   Updated: 2023/09/04 05:15:02 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lst_smallest(t_list *lst)
{
	t_list	*smallest;

	smallest = lst;
	while (lst && lst->next)
	{
		if (*(int *)(lst->next->content) < *(int *)(smallest->content))
			smallest = lst->next;
		lst = lst->next;
	}
	return (smallest);
}

t_list	*ft_cheapest(t_list *head_b)
{
	t_list	*cheapest;

	cheapest = head_b;
	while (head_b)
	{
		if (head_b->total_cost < cheapest->total_cost)
			cheapest = head_b;
		head_b = head_b->next;
	}
	return (cheapest);
}

void	ft_rtop(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	size_t	cost_tar;
	size_t	cost_b;

	cost_tar = cheapest->tar->up_cost;
	cost_b = cheapest->up_cost;
	while (cost_tar != 0 && cost_b != 0)
	{
		ft_rr(head_a, head_b);
		cost_tar--;
		cost_b--;
	}
	while (cost_tar-- > 0)
		ft_ra(head_a);
	while (cost_b-- > 0)
		ft_rb(head_b);
}

void	ft_rrtop(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	size_t	cost_tar;
	size_t	cost_b;

	cost_tar = cheapest->tar->down_cost;
	cost_b = cheapest->down_cost;
	while (cost_tar != 0 && cost_b != 0)
	{
		ft_rrr(head_a, head_b);
		cost_tar--;
		cost_b--;
	}
	while (cost_tar-- != 0)
		ft_rra(head_a);
	while (cost_b-- != 0)
		ft_rrb(head_b);
}

void	ft_updown(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	size_t	upcost_a;
	size_t	downcost_b;

	upcost_a = cheapest->tar->up_cost;
	downcost_b = cheapest->down_cost;
	while (upcost_a-- > 0)
		ft_ra(head_a);
	while (downcost_b-- > 0)
		ft_rrb(head_b);
}
