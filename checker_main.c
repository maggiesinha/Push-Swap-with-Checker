/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 02:35:48 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 02:59:11 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	int		a;
	t_list	*instructions;
	char	*current_inst;

	head_a = 0;
	head_b = 0;
	if (argc <= 1)
		return (0);
	if (!ft_separgs(argc, argv, &head_a) || !ft_check(&head_a))
		return (0);
	instructions = ft_get_instr();
	while (instructions)
	{
		current_inst = (char *)(instructions->content);
		a = ft_ordering(&current_inst, &head_a, &head_b);
		if (!a)
			{
				ft_printf("Error\n");
				return (0);
			}
		else if (a == 2)
			return (0);
		instructions = instructions->next;
	}
	ft_ok_ko(head_a, head_b);
}
