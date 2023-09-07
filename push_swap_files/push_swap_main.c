/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:05 by maggie            #+#    #+#             */
/*   Updated: 2023/09/07 13:34:53 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_big_sort(t_list **head_a, t_list **head_b)
{
	while (ft_lstlen(*head_a) > 3)
		ft_pb(head_a, head_b);
	ft_sort_small(head_a);
	ft_refresh_nodes(*head_a, *head_b);
	while (*head_b)
	{
		ft_top(head_a, head_b, ft_cheapest(*head_b));
		ft_pa(head_a, head_b);
		ft_refresh_nodes(*head_a, *head_b);
	}
	ft_finalize(head_a);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = 0;
	head_b = 0;
	if (argc <= 1 || !ft_separgs(argc, argv, &head_a))
		return (0);
	if (ft_specific_cases(&head_a))
	{
		ft_lstclear(&head_a, free);
		return (0);
	}
	ft_big_sort(&head_a, &head_b);
	ft_lstclear(&head_a, free);
}
