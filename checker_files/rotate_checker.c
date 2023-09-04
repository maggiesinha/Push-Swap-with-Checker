/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:33:29 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 15:23:53 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rac(t_list **head_a)
{
	if (!(*head_a) || !((*head_a)->next))
		return (10);	
	ft_rotate(head_a);
	return (0);
}

int	ft_rbc(t_list **head_b)
{
	if (!(*head_b) || !((*head_b)->next))
		return (10);
	ft_rotate(head_b);
	return (0);
}

int	ft_rrc(t_list **head_a, t_list **head_b)
{
	if ((*head_a) && ((*head_a)->next))
		ft_rotate(head_a);
	if ((*head_b) && ((*head_b)->next))
		ft_rotate(head_b);
	return (0);
}
