/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:12:12 by maggie            #+#    #+#             */
/*   Updated: 2023/09/05 14:22:38 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strcpy(char *str)
{
	char	*copy;
	size_t	i;

	if (!str)
		return (NULL);
	copy = malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_freememory(t_list **head_a, t_list **head_b, t_list **instructions)
{
	ft_lstclear(instructions, free);
	ft_lstclear(head_a, free);
	ft_lstclear(head_b, free);
}
