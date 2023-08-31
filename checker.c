/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:08:23 by mvalerio          #+#    #+#             */
/*   Updated: 2023/08/31 18:56:21 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_equal(char **str1, const char str2[])
{
	size_t	i;

	i = 0;
	while ((*str1)[i] && str2[i])
	{
		if ((*str1)[i] != str2[i])
			return (0);
		i++;
	}
	if ((*str1)[i] && !str2[i])
		return (0);
	if (str2[i] && !((*str1)[i]))
		return (0);
	return (1);
}

int	ft_compare(char **inst, t_list **head_a, t_list **head_b)
{
	if (ft_equal(inst, "rr\n"))
		ft_rrc(head_a, head_b);
	else if (ft_equal(inst, "ra\n"))
		ft_rac(head_a);
	else if (ft_equal(inst, "rb\n"))
		ft_rbc(head_b);
	else if (ft_equal(inst, "rrr\n"))
		ft_rrrc(head_a, head_b);
	else if (ft_equal(inst, "rra\n"))
		ft_rrac(head_a);
	else if (ft_equal(inst, "rrb\n"))
		ft_rrbc(head_a);
	else if (ft_equal(inst, "sa\n"))
		ft_sac(head_a);
	else if (ft_equal(inst, "sb\n"))
		ft_sbc(head_a);
	else if (ft_equal(inst, "pa\n"))
		ft_pac(head_a, head_b);
	else if (ft_equal(inst, "pb\n"))
		ft_pbc(head_a, head_b);
	else if (ft_equal(inst, "\n"))
		return (0);
	else
		return (2);
	return (1);
}

int	ft_ordering(char **inst, t_list **head_a, t_list **head_b)
{
	int	a;

	a = ft_compare(inst, head_a, head_b);
	if (a == 0)
		return (0);
	else if (a == 2)
	{
		ft_printf("Error\n");
		return (2);
	}
	return (1);
}

void	ft_ok_ko(t_list *head_a, t_list *head_b)
{
	if (ft_ordered(head_a) && !head_b)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int	ft_check(t_list **head_a)
{
	if (!ft_checker(*head_a))
	{
		ft_printf("Error\n");
		ft_lstclear(head_a, &free);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	char	*inst;
	int		a;

	head_a = 0;
	head_b = 0;
	if (argc <= 1)
		return (0);
	ft_separgs(argc, argv, &head_a);
	if (!ft_check(&head_a))
		return (0);
	inst = get_next_line(0);
	while (inst != NULL)
	{
		a = ft_ordering(&inst, &head_a, &head_b);
		if (!a)
			break ;
		else if (a == 2)
			return (0);
		inst = get_next_line(0);
	}
	ft_ok_ko(head_a, head_b);
}
