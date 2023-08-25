/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:52:15 by maggie            #+#    #+#             */
/*   Updated: 2023/08/17 12:10:40 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = 0;
	head_b = 0;
	if (argc <= 1)
		return (0);
	ft_separgs(argc, argv, &head_a);
	if (ft_specific_cases(&head_a))
	{
		ft_lstclear(&head_a, free);
		return (0);
	}
	while (ft_lstlen(head_a) > 3)
		ft_pb(&head_a, &head_b);
	ft_sort_small(&head_a);
	ft_refresh_nodes(head_a, head_b);
	while (head_b)
	{
		ft_top(&head_a, &head_b, ft_cheapest(head_b));
		ft_pa(&head_a, &head_b);
		ft_refresh_nodes(head_a, head_b);
	}
	ft_finalize(&head_a);
	ft_lstclear(&head_a, free);
}
