/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:03:36 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 05:14:32 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_section(t_list *lst)
{
	size_t	len;

	len = ft_lstlen(lst);
	while (lst)
	{
		if (len % 2 == 0)
		{
			if (lst->position == len / 2 + 1)
				lst->section = MIDDLE;
			else if (lst->position > len / 2 + 1)
				lst->section = BOTTOM;
			else
				lst->section = TOP;
		}
		else
		{
			if (lst->position < len / 2 + 2)
				lst->section = TOP;
			else
				lst->section = BOTTOM;
		}
		lst = lst->next;
	}
}

void	ft_refresh_nodes(t_list *head_a, t_list *head_b)
{
	ft_position(head_a);
	ft_position(head_b);
	ft_section(head_a);
	ft_section(head_b);
	ft_individual_cost(head_a);
	ft_individual_cost(head_b);
	ft_set_targets(head_a, head_b);
	ft_total_cost(head_b);
}
