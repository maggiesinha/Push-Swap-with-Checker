/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:43:22 by maggie            #+#    #+#             */
/*   Updated: 2023/09/04 02:58:21 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_args_into_stack(int argc, char *argv[], t_list **head_a)
{
	int	i;
	int		argument;
	int		*argument_copy;
	t_list	*new;

	i = 0;
	while (++i < argc)
	{
		argument = ft_atoi(argv[i]);
		argument_copy = malloc(sizeof(int));
		if (!argument_copy)
			return ;
		*argument_copy = argument;
		new = ft_lstnew(argument_copy);
		ft_lstadd_back(head_a, new);
	}
} */

void	ft_arrtostack(t_list **head, char **array)
{
	size_t	i;
	t_list	*new;

	i = 0;
	while (array[i])
	{
		new = ft_lstnew(array[i]);
		ft_lstadd_back(head, new);
		i++;
	}
}

int	ft_separgs(int argc, char *argv[], t_list **head)
{
	char	**temp;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_equal(&(argv[i]), ""))
		{
			ft_printf("Error\n");
			return (0);
		}
		temp = ft_split(argv[i], ' ');
		ft_arrtostack(head, temp);
		free(temp);
	}
	return (1);
}
