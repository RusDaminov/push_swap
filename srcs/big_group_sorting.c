/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_group_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:22:03 by abernita          #+#    #+#             */
/*   Updated: 2022/04/01 09:22:08 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inverse_stack(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

void	stack_b_sorting_three(t_all *all)
{
	int	main_index;
	int	next_index;
	int	prev_index;

	if (all->size_b == 0)
		return ;
	main_index = all->stack_b->index;
	next_index = all->stack_b->next->index;
	prev_index = all->stack_b->prev->index;
	if (next_index > main_index && next_index > prev_index)
		rrb(all, 1);
	else if (main_index > next_index && main_index > prev_index)
		rb(all, 1);
	main_index = all->stack_b->index;
	next_index = all->stack_b->next->index;
	if (main_index > next_index)
		sb(all, 1);
}

void	aftermath_sorting_three(t_all *all, int flag)
{
	stack_b_sorting_three(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			pa(all, 1);
			inverse_stack(all);
		}
		else
			inverse_stack(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
			all->stack_a->index +1 == all->stack_a->prev->index)
		inverse_stack(all);
}

void	stack_b_sorting_five(t_all *all)
{
	int	i;
	int	min;
	int	flag;

	i = all->size_b;
	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			inverse_stack(all);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	aftermath_sorting_three(all, flag);
}

void	send_from_b_to_a(t_all *all)
{
	int	i;

	stack_b_find_minmax_med(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
