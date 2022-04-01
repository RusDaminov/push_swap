/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:25:31 by abernita          #+#    #+#             */
/*   Updated: 2022/04/01 18:25:33 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	word_len(char *word)
{
	int	len;

	len = 0;
	while (word[len])
		len++;
	if (len < 1)
		ft_display_error();
}

void	check_trap(int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ac)
		word_len(av[i]);
}

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
	return (1);
}
