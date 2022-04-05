/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:08:37 by abernita          #+#    #+#             */
/*   Updated: 2022/03/31 10:08:45 by abernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_display_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_SUCCESS);
}

char	**ft_readline(char **av)
{
	int		i;
	char	*line;
	char	**arr;

	line = ft_strdup(av[1]);
	i = 1;
	while (av[++i])
	{
		line = ft_strjoin(line, " ");
		line = ft_strjoin(line, av[i]);
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

void	ft_free_arr(char **arr, int flag)
{
	int		i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag)
		ft_display_error();
}

void	ft_check_input_numbers(char **arr)
{
	int			i;
	int			j;
	long long	num;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (!(ft_isdigit(arr[i][j])))
				ft_free_arr(arr, 1);
			j++;
		}
		num = ft_atoi(arr[i]);
		if (num > MAX_INT || num < MIN_INT)
		{
			ft_free_arr(arr, 1);
		}
	}
}

void	ft_check_for_doubles(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				ft_free_arr(arr, 1);
			j++;
		}
		i++;
	}
}
