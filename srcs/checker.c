/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:25:22 by abernita          #+#    #+#             */
/*   Updated: 2022/04/01 18:25:25 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_cmd(t_all *all, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(all, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(all, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(all, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(all, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(all, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(all, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(all, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(all, 0);
	else if (!ft_strncmp(line, "rra\n", 3))
		rra(all, 0);
	else if (!ft_strncmp(line, "rrb\n", 3))
		rrb(all, 0);
	else if (!ft_strncmp(line, "rrr\n", 3))
		rrr(all, 0);
	else
		ft_display_error();
}

static void	checker(t_all *all)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		get_cmd(all, line);
	}
	if (ft_is_sort_true(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac > 1)
	{
		check_trap(ac, av);
		all = ft_parsing_args(av);
		checker(all);
		ft_free_stack(all);
	}
	return (0);
}
