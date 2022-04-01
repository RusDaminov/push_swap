/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_group_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:03:30 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 14:03:35 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorting_three_a(t_all *all)
{
	int	main_index;
	int	next_index;
	int	prev_index;

	main_index = all->stack_a->index;
	next_index = all->stack_a->next->index;
	prev_index = all->stack_a->prev->index;
	if (next_index > main_index && next_index > prev_index)
		rra(all, 1);
	else if (main_index > next_index && main_index > prev_index)
		ra(all, 1);
	main_index = all->stack_a->index;
	next_index = all->stack_a->next->index;
	if (main_index > next_index)
		sa(all, 1);
}

void	ft_sorting_five(t_all *all)
{
	while (all->size_a > 3)
	{
		stack_a_find_minmax_med(all);
		if (all->stack_a->index == all->min)
		{
			pb(all, 1);
			continue ;
		}
		if (which_way_faster(all))
			ra(all, 1);
		else
			rra(all, 1);
	}
	ft_sorting_three_a(all);
	pa(all, 1);
	pa(all, 1);
}
