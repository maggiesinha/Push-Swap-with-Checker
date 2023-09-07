/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:26:35 by maggie            #+#    #+#             */
/*   Updated: 2023/09/05 14:35:08 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"

// Constants
# define TOP 1
# define MIDDLE 2
# define BOTTOM 3
# define UPUP 4
# define DOWNDOWN 5
# define UPDOWN 6
# define DOWNUP 7

// Protections
//		Protections 1
int		ft_checker(t_list *head);
int		ft_is_digit(char *str);
int		ft_check_int_range(char *str);
int		ft_check_int_max(char *str);
int		ft_check_int_min(char *str);

//		Protections 2
int		ft_check_duplicates(t_list *lst);
int		ft_specific_cases(t_list **head_a);
int		ft_ordered(t_list *lst);

// Lists
void	ft_arrtostack(t_list **head, char **array);
int		ft_separgs(int argc, char *argv[], t_list **head);

// Utils
//		Utils 1
int		ft_switch(t_list **lst);
void	ft_rotate(t_list **head);
t_list	*ft_lst_secondlast(t_list *lst);
void	ft_reverse_rotate(t_list **head);
t_list	*ft_lst_biggest(t_list *lst);

//		Utils 2
t_list	*ft_lst_smallest(t_list *lst);
t_list	*ft_cheapest(t_list *head_b);
void	ft_rtop(t_list **head_a, t_list **head_b, t_list *cheapest);
void	ft_rrtop(t_list **head_a, t_list **head_b, t_list *cheapest);
void	ft_updown(t_list **head_a, t_list **head_b, t_list *cheapest);

//		Utils 3
void	ft_downup(t_list **head_a, t_list **head_b, t_list *cheapest);
void	ft_top(t_list **head_a, t_list **head_b, t_list *cheapest);
int		ft_equal(char **str1, const char str2[]);

// Operations
//		Swap and Push
int		ft_sa(t_list **head_a);
int		ft_sb(t_list **head_b);
int		ft_ss(t_list **head_a, t_list **head_b);
int		ft_pa(t_list **head_a, t_list **head_b);
int		ft_pb(t_list **head_a, t_list **head_b);

//		Rotate
void	ft_ra(t_list **head_a);
void	ft_rb(t_list **head_b);
void	ft_rr(t_list **head_a, t_list **head_b);

//		Reverse Rotate
void	ft_rra(t_list **head_a);
void	ft_rrb(t_list **head_b);
void	ft_rrr(t_list **head_a, t_list **head_b);

// Data
//		Data 1
size_t	ft_lstlen(t_list *lst);
int		ft_lstmin(t_list *lst);
int		ft_lstmedian(int length, t_list *lst);
void	ft_position(t_list *lst);
void	ft_individual_cost(t_list	*lst);

//		Data 2
size_t	ft_biggest(size_t args, ...);
size_t	ft_smallest(size_t args, ...);
void	ft_total_cost(t_list *head_b);
void	ft_smallest_bigger(t_list *i_a, t_list *head_b);
void	ft_section(t_list *lst);

//		Data 3
void	ft_set_targets(t_list *head_a, t_list *head_b);
void	ft_refresh_nodes(t_list *head_a, t_list *head_b);

// Algorithm
void	three_sort_a(t_list **lst);
void	ft_sort_small(t_list **head_a);
void	ft_finalize(t_list **head_a);

// Tests
void	ft_print_lists(t_list *head_a, t_list *head_b);
void	ft_costs_and_positions(t_list *head_a, t_list *head_b);

//BONUS

// Operations
//		Swap and Push
int		ft_sac(t_list **head_a);
int		ft_sbc(t_list **head_b);
int		ft_ssc(t_list **head_a, t_list **head_b);
int		ft_pac(t_list **head_a, t_list **head_b);
int		ft_pbc(t_list **head_a, t_list **head_b);

//		Rotate
int		ft_rac(t_list **head_a);
int		ft_rbc(t_list **head_b);
int		ft_rrc(t_list **head_a, t_list **head_b);

//		Reverse Rotate
int		ft_rrac(t_list **head_a);
int		ft_rrbc(t_list **head_b);
int		ft_rrrc(t_list **head_a, t_list **head_b);

//		Checker Utils
int		ft_compare(char **inst, t_list **head_a, t_list **head_b);
int		ft_ordering(char **inst, t_list **head_a, t_list **head_b);
void	ft_ok_ko(t_list *head_a, t_list *head_b);
int		ft_check(t_list **head_a);
t_list	*ft_get_instr(void);

//		Checker Utils 2
void	ft_freememory(t_list **head_a, t_list **head_b, t_list **instructions);

#endif
