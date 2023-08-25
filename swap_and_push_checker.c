/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:15:24 by maggie            #+#    #+#             */
/*   Updated: 2023/08/23 22:25:24 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sac(t_list **head_a)
{
	if (*head_a && (*head_a)->next)
	{
		if (!ft_switch(head_a))
			return (0);
	}
	return (1);
}

int	ft_sbc(t_list **head_b)
{
	if (*head_b && (*head_b)->next)
	{
		if (!ft_switch(head_b))
			return (0);
	}
	return (1);
}

int	ft_ssc(t_list **head_a, t_list **head_b)
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
	return (1);
}

int	ft_pac(t_list **head_a, t_list **head_b)
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
	}
	return (1);
}

int	ft_pbc(t_list **head_a, t_list **head_b)
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
	}
	return (1);
}
