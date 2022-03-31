/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_base_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:33:02 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 11:33:04 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_build_stack(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (not_sort[i] == sort[j])
			{
				listadd_back(&all->stack_a, ft_new_list(not_sort[i], j + 1));
				j++;
				break ;
			}
			j++
			}
		i++;
		}
		free(not_sort);
		free(sort);
	}

void	ft_free_stack(t_all *all)
{
	t_node	*tmp;

	while (all->size_a--)
	{
		tmp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = tmp;
	}
	while (all->size_b--)
	{
		tmp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = tmp;
	}
	free(all);
	exit(0);
}

void	ft_buble_sort(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
				count++;
			}
			j++;
		}
		i++;
	}
	ft_build_stack(all, sort, not_sort, len);
}

void	ft_prepare_for_stack(t_all *all, char **arr)
{
	int	i;
	int	*sort;
	int	*not_sort;
	int	num;
	int	len;

	len = ft_arr_len(arr);
	not_sort = malloc(sizeof(int) * (len));
	sort = malloc(sizeof(int) * (len));
	i = -1;
	while (++i < len)
	{
		num = ft_atoi(arr[i]);
		not_sort[i] = num;
		sort[i] = num;
	}
	ft_buble_sort(all, sort, not_sort, len);
}
