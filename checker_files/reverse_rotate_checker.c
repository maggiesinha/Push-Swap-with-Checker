/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:54:01 by mvalerio          #+#    #+#             */
/*   Updated: 2023/09/04 05:45:51 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rrac(t_list **head_a)
{
	if (!(*head_a) || !((*head_a)->next))
		return (10);
	ft_reverse_rotate(head_a);
	return (0);
}

int	ft_rrbc(t_list **head_b)
{
	if (!(*head_b) || !((*head_b)->next))
		return (10);	
	ft_reverse_rotate(head_b);
	return (0);
}

int	ft_rrrc(t_list **head_a, t_list **head_b)
{
	if (!(*head_a) || !((*head_a)->next) || !(*head_b) || !((*head_b)->next))
		return (10);	
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
	return (0);
}
