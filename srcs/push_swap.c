/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:08:53 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 10:08:57 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	which_way_faster(t_all *all)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = all->stack_a;
	i = 0;
	while (++i)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->next;
	}
	tmp = all->stack_a;
	j = 0;
	while (++j)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

int	ft_is_sort_true(t_all *all)
{
	int		i;
	t_node	*head;

	head = all->stack_a;
	i = all->size_a - 1;
	while (i-- > 0)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
//	write (1, "sorted", 6);
	return (1);
}

t_all	*ft_parsing_args(char **av)
{
	t_all	*all;
	char	**arr;

	arr = ft_readline(av);
	ft_check_input_numbers(arr);
	ft_check_for_doubles(arr);
	all = ft_init_struct(arr);
	ft_prepare_for_stack(all, arr);
	ft_free_arr(arr, 0);
	return (all);
}

void	ft_sorting(t_all *all)
{
	if (ft_is_sort_true(all))
		ft_free_stack(all);
	if (all->size_a < 6)
	{
		ft_sorting_five(all);
		ft_free_stack(all);
	}
	send_first_group_to_b(all);
	while (!(ft_is_sort_true(all) && all->size_b == 0))
	{
		if (all->size_b > 0 && all->size_b < 6)
			stack_b_sorting_five(all);
		else if (all->size_b >= 6)
			send_from_b_to_a(all);
		if (all->size_b == 0)
		{
			sorting_five_from_a_to_b(all, 0, 0, 0);
			ft_send_back(all);
		}
	}
}

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac > 1)
	{
		all = ft_parsing_args(av);
		ft_sorting(all);
		ft_free_stack(all);
	}
	return (0);
}
