/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 02:35:48 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 18:36:23 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_freememory(t_list **head_a, t_list **head_b, t_list **instructions)
{
	ft_lstclear(instructions, free);
	ft_lstclear(head_a, free);
	ft_lstclear(head_b, free);
}

int	ft_do_instructions(t_list **instructions, t_list **head_a, t_list **head_b)
{
	char	*current_inst;
	int		a;
	t_list	*temp;
	
	temp = *instructions;
	while (temp)
	{
		current_inst = (char *)((temp)->content);
		a = ft_ordering(&current_inst, head_a, head_b);
		if (!a)
		{
			ft_printf("Error\n");
			ft_freememory(head_a, head_b, instructions);
			return (0);
		}
		else if (a == 2)
		{
			ft_freememory(head_a, head_b, instructions);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*instructions;

	head_a = 0;
	head_b = 0;
	if (argc <= 1)
		return (0);
	if (!ft_separgs(argc, argv, &head_a) || !ft_check(&head_a))
		return (0);
	instructions = ft_get_instr();
	if (!ft_do_instructions(&instructions, &head_a, &head_b))
		return (0);
	ft_ok_ko(head_a, head_b);
	ft_freememory(&head_a, &head_b, &instructions);
}
