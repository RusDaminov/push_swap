/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:29:54 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 11:29:56 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

# define MAX_INT 21474483647
# define MIN_INT -21474483648

typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				med;
	int				max;
	int				min_a;
}					t_all;

int		ft_is_sort_true(t_all *all);
int		which_way_faster(t_all *all);

void	ft_display_error(void);
char	**ft_readline(char **av);
void	ft_free_arr(char **arr, int flag);
void	ft_check_input_numbers(char **arr);
void	ft_check_for_doubles(char **arr);

t_node	*ft_new_list(int num, int index);
void	listadd_back(t_node **stack_a, t_node *new);
int		ft_arr_len(char **arr);
t_all	*ft_init_struct(char **arr);

void	ft_build_stack(t_all *all, int *sort, int *not_sort, int len);
void	ft_free_stack(t_all *all);
void	ft_buble_sort(t_all *all, int *sort, int *not_sort, int len);
void	ft_prepare_for_stack(t_all *all, char **arr);

void	ft_sorting_three_a(t_all *all);
void	ft_sorting_five(t_all *all);

void	stack_a_find_minmax_med(t_all *all);
void	stack_b_find_minmax_med(t_all *all);
void	final_rotate_send_to_a(t_all *all);
void	send_first_group_to_b(t_all *all);

void	push_top_a_to_b(t_all *all);
void	push_top_b_to_a(t_all *all);
void	pa(t_all *all, int flag);
void	pb(t_all *all, int flag);

void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);

void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);

void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all, int flag);

void	inverse_stack(t_all *all);
void	stack_b_sorting_three(t_all *all);
void	aftermath_sorting_three(t_all *all, int flag);
void	stack_b_sorting_five(t_all *all);
void	send_from_b_to_a(t_all *all);

void 	search_min_a_to_b(t_all *all);
int 	search_min_b_to_a(t_all *all);
void	ft_send_back(t_all *all);
void	sorting_five_from_a_to_b(t_all *all, int flag, int min, int i);
void	sorting_five_from_a_to_b_sec(t_all *all, int flag);

void	check_trap(int ac, char **av);

#endif