/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_group_second_sorting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:21:55 by abernita          #+#    #+#             */
/*   Updated: 2022/04/01 09:21:58 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	search_min_a_to_b(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index +1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		inverse_stack(all);
	}
	else if (all->stack_b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		inverse_stack(all);
	}
	else if (all->stack_b->prev->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		inverse_stack(all);
	}
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		inverse_stack(all);
	}
}

int	search_min_b_to_a(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index +1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		inverse_stack(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		inverse_stack(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		inverse_stack(all);
	}
	return (0);
}

void	ft_send_back(t_all *all)
{
	int	min;
	int	flag;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			search_min_a_to_b(all);
		if (all->stack_a->index == min)
			inverse_stack(all);
		else
			pb(all, 1);
	}
}

void	sorting_five_from_a_to_b(t_all *all, int flag, int min, int i)
{
	t_node	*tmp;

	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (all->stack_a->index == min)
			{
				inverse_stack(all);
				min++;
			}
			else
				pb(all, 1);
			i--;
		}
		sorting_five_from_a_to_b_sec(all, flag);
	}
}

void	sorting_five_from_a_to_b_sec(t_all *all, int flag)
{
	stack_b_sorting_three(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag != flag)
		{
			pa(all, 1);
			inverse_stack(all);
		}
		else
			inverse_stack(all);
	}
	while (all->stack_a->flag == flag && flag != -1)
		inverse_stack(all);
}
