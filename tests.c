/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 02:33:42 by maggie            #+#    #+#             */
/*   Updated: 2023/08/12 02:34:46 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lists(t_list *head_a, t_list *head_b)
{
	ft_printf("\nStack a:\n\n");
	while (head_a)
	{
		ft_printf("%d\n", *(int *)(head_a->content));
		head_a = head_a->next;
	}
	ft_printf("\nStack b:\n\n");
	while (head_b)
	{
		ft_printf("%d\n", *(int *)(head_b->content));
		head_b = head_b->next;
	}
}

void	ft_costs_and_positions(t_list *head_a, t_list *head_b)
{
	ft_printf("\nList A\n");
	while (head_a)
	{
		ft_printf("Node: %d\t\tPosition: %d\t\tUp Cost: %d\t\tDown Cost: \
		%d\t\tTotal cost: %d\n\t\tSection: %d\n", *(int *)(head_a->content), \
		head_a->position, head_a->up_cost, head_a->down_cost, \
		head_a->total_cost, head_a->section);
		head_a = head_a->next;
	}
	ft_printf("\nList B\n");
	while (head_b)
	{
		ft_printf("Node: %d\t\tPosition: %d\t\tUp Cost: %d\t\tDown Cost: \
		%d\t\tTotal cost: %d\t\tTarget: %d\t\tTarget position: %d\n\t\tSection: \
		%d\n", *(int *)(head_b->content), head_b->position, \
		head_b->up_cost, head_b->down_cost, head_b->total_cost, \
		*(int *)head_b->tar->content, head_b->tar->position, head_b->section);
		head_b = head_b->next;
	}
}
