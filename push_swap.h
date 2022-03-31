#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

# define MAX_INT 21474483647
# define MIN_INT -21474483648

typedef struct	s_node
{
    int				num;
    int				index;
    int				flag;
    struct s_node	*prev;
    struct s_node	*next;
}					t_node;

typedef struct	s_all
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

int	ft_is_sort_true(t_all *all);
int	which_way_faster(t_all *all);