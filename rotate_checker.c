/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:33:29 by maggie            #+#    #+#             */
/*   Updated: 2023/08/23 22:24:55 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rac(t_list **head_a)
{
	ft_rotate(head_a);
}

void	ft_rbc(t_list **head_b)
{
	ft_rotate(head_b);
}

void	ft_rrc(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}
