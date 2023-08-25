/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:54:01 by mvalerio          #+#    #+#             */
/*   Updated: 2023/08/23 22:24:40 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrac(t_list **head_a)
{
	ft_reverse_rotate(head_a);
}

void	ft_rrbc(t_list **head_b)
{
	ft_reverse_rotate(head_b);
}

void	ft_rrrc(t_list **head_a, t_list **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
}
