/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:43:20 by maggie            #+#    #+#             */
/*   Updated: 2023/08/11 15:58:09 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(t_list *head)
{
	int		number;
	t_list	*lst;

	lst = head;
	while (lst)
	{
		if (!ft_is_digit(lst->content))
			return (0);
		if (!ft_check_int_range(lst->content))
			return (0);
		number = ft_atoi(lst->content);
		free (lst->content);
		lst->content = malloc(sizeof(int *));
		*(int *)(lst->content) = number;
		lst = lst->next;
	}
	lst = head;
	if (!ft_check_duplicates(lst))
		return (0);
	return (1);
}

int	ft_is_digit(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_int_range(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
	{
		if (!ft_check_int_min(str))
			return (0);
	}
	else if (!ft_check_int_max(str))
		return (0);
	return (1);
}

int	ft_check_int_max(char *str)
{
	size_t	a;

	a = 0;
	while (str[a] && str[a] == '0')
		a++;
	if (str[a])
	{
		if (ft_strlen(&(str[a])) > 10)
			return (0);
		else if (ft_strlen(&(str[a])) == 10 && \
				ft_strncmp(&(str[a]), "2147483647", 10) > 0)
			return (0);
	}
	return (1);
}

int	ft_check_int_min(char *str)
{
	size_t	a;

	a = 1;
	while (str[a] && str[a] == '0')
		a++;
	if (str[a])
	{
		if (ft_strlen(&(str[a])) > 10)
			return (0);
		else if (ft_strlen(&(str[a])) == 10 && \
			ft_strncmp(&(str[a]), "2147483648", 10) > 0)
			return (0);
	}
	return (1);
}
