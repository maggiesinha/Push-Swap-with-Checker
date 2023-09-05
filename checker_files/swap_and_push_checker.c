/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:15:24 by maggie            #+#    #+#             */
/*   Updated: 2023/09/05 14:10:29 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sac(t_list **head_a)
{
	if (*head_a && (*head_a)->next)
		ft_switch(head_a);
	return (0);
}

int	ft_sbc(t_list **head_b)
{	
	if (*head_b && (*head_b)->next)
		ft_switch(head_b);
	return (0);
}

int	ft_ssc(t_list **head_a, t_list **head_b)
{
	if (*head_b && (*head_b)->next)
		ft_switch(head_b);
	if (*head_a && (*head_a)->next)
		ft_switch(head_a);
	return (0);
}

int	ft_pac(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list	*b;

	if (!(*head_b))
		return (10);
	temp = ft_lstnew((void *)((*head_b)->content));
	if (!temp)
		return (0);
	ft_lstadd_front(head_a, temp);
	b = *head_b;
	*head_b = (*head_b)->next;
	free (b);
	return (0);
}

int	ft_pbc(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list	*a;

	if (!(*head_a))
		return (10);
	temp = ft_lstnew((void *)((*head_a)->content));
	if (!temp)
		return (0);
	ft_lstadd_front(head_b, temp);
	a = *head_a;
	*head_a = (*head_a)->next;
	free (a);
	return (0);
}
