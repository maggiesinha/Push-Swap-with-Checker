/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:15:24 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 05:14:56 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sa(t_list **head_a)
{
	if (*head_a && (*head_a)->next)
	{
		if (!ft_switch(head_a))
			return (0);
		ft_printf("sa\n");
	}
	return (1);
}

int	ft_sb(t_list **head_b)
{
	if (*head_b && (*head_b)->next)
	{
		if (!ft_switch(head_b))
			return (0);
		ft_printf("sb\n");
	}
	return (1);
}

int	ft_ss(t_list **head_a, t_list **head_b)
{
	if (*head_a && (*head_a)->next)
	{
		if (!ft_switch(head_a))
			return (0);
	}
	if (*head_b && (*head_b)->next)
	{
		if (!ft_switch(head_b))
			return (0);
	}
	ft_printf("ss\n");
	return (1);
}

int	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list	*b;

	if (*head_b)
	{
		temp = ft_lstnew((void *)((*head_b)->content));
		if (!temp)
			return (0);
		ft_lstadd_front(head_a, temp);
		b = *head_b;
		*head_b = (*head_b)->next;
		free (b);
		ft_printf("pa\n");
	}
	return (1);
}

int	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list	*a;

	if (*head_a)
	{
		temp = ft_lstnew((void *)((*head_a)->content));
		if (!temp)
			return (0);
		ft_lstadd_front(head_b, temp);
		a = *head_a;
		*head_a = (*head_a)->next;
		free (a);
		ft_printf("pb\n");
	}
	return (1);
}
