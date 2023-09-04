/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:54:01 by mvalerio          #+#    #+#             */
/*   Updated: 2023/09/04 15:23:37 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rrac(t_list **head_a)
{
	if (*head_a && (*head_a)->next)
		ft_reverse_rotate(head_a);
	return (0);
}

int	ft_rrbc(t_list **head_b)
{
	if (*head_b && (*head_b)->next)
		ft_reverse_rotate(head_b);
	return (0);
}

int	ft_rrrc(t_list **head_a, t_list **head_b)
{
	if ((*head_a) && ((*head_a)->next))
		ft_reverse_rotate(head_a);
	if ((*head_b) && ((*head_b)->next))
		ft_reverse_rotate(head_b);
	return (0);
}
