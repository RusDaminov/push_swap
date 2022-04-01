/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:04:05 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 14:04:07 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_a_find_minmax_med(t_all *all)
{
	int	i;
	int	min;
	int	max;

	if (all->size_a == 0)
		return ;
	i = all->size_a;
	min = all->stack_a->index;
	max = all->stack_a->index;
	while (i-- > 0)
	{
		if (min > all->stack_a->index)
			min = all->stack_a->index;
		if (max < all->stack_a->index)
			max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
}

void	stack_b_find_minmax_med(t_all *all)
{
	int	i;
	int	min;
	int	max;

	if (all->size_b == 0)
		return ;
	i = all->size_b;
	min = all->stack_b->index;
	max = all->stack_b->index;
	while (i-- > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
	}
	all->max = max;
	all->med = (min + max) / 2;
}

void	final_rotate_send_to_a(t_all *all)
{
	while (all->stack_b->prev->flag == -1)
		rrb(all, 1);
	while (all->stack_b->flag == -1)
	{
		pa(all, 1);
		ra(all, 1);
	}
}

void	send_first_group_to_b(t_all *all)
{
	int	i;

	stack_a_find_minmax_med(all);
	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->index <= all->med)
		{
			pb(all, 1);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				rb(all, 1);
			}
		}
		else
		{
			if (all->size_b == all->max - all->med + 1)
				break ;
			else
				ra(all, 1);
		}
	}
	final_rotate_send_to_a(all);
}
