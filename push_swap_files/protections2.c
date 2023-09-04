/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protections2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:55:55 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 05:14:49 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_duplicates(t_list *head)
{
	t_list	*lst;

	while (head && head->next)
	{
		lst = head->next;
		while (lst)
		{
			if (*(int *)(head->content) == *(int *)(lst->content))
				return (0);
			lst = lst->next;
		}
		head = head->next;
	}
	return (1);
}


int	ft_specific_cases(t_list **head_a)
{
	if (!ft_checker(*head_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ft_lstlen(*head_a) <= 3)
	{
		ft_sort_small(head_a);
		return (1);
	}
	if (ft_ordered(*head_a))
		return (1);
	return (0);
}

int	ft_ordered(t_list *lst)
{
	int	number;

	number = *(int *)(lst->content);
	lst = lst->next;
	while (lst)
	{
		if (*(int *)(lst->content) > number)
		{
			number = *(int *)(lst->content);
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}
